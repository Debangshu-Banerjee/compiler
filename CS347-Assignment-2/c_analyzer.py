import sys,os
import re
import xml.etree.ElementTree as ET
from pyparsing import *

xmlfile = "temp.xml"
logfile = "logs.txt"
fileid = "f1"   #default

xmlfile_variable = "variable_temp.xml"


def find_fileid(inputfile,xmlfile):
    tree = ET.parse(xmlfile)
    root = tree.getroot()
    for file in root.findall('File'):
        if file.get('name') == inputfile:
            return file.get('id')
    # return "f1"   #default

                        
def allvariables(infile,outfile):
    data_types = ['int','float','char','double','long','typedef']
    tree = ET.parse(xmlfile)
    root = tree.getroot()
    typedefs = []
    for typedef in root.findall('Typedef'):
        data_types.append(typedef.get('name'))

    with open(infile) as a, open(outfile, 'w') as b:
        for line in a:
            for type in data_types:
                 if type in line and 'printf' not in line:
                     b.write(line + '\n')
                     break                        

def line_number(filename,index):
    ct = 0
    index += 1
    line_no =1
    with open(filename) as f:
        for line in f.readlines():
            ct += len(line)
            if ct > index:
                return line_no
            line_no += 1

def statements_count(filename):
    lines = 0
    with open(filename) as f:
        for line in f.readlines():
            lines += 1
    return lines

def comments_count(filename):
    multiline_cmnt = Combine(Regex(r"/\*(?:[^*]|\*(?!/))*") + '*/').setName("c_comment")
    singleline_cmnt = Regex(r"//(?:\\\n|[^\n])*").setName("// comment") # Comment of the form //
    cppstyle_cmnt = Combine(multiline_cmnt | singleline_cmnt).setName("C++ style comment") #both sigle+multi
    with open(filename) as f:
        res = cppstyle_cmnt.scanString(f.read())
        # cmnt_list = [tokens.start for tokens, startPos, EndPos in res]
        cmnt_list = [(startPos,EndPos) for tokens, startPos, EndPos in res]
        # print(cmnt_list)
    return len(cmnt_list)
    # return 0

def total_commented_lines(filename):
    multiline_cmnt = Combine(Regex(r"/\*(?:[^*]|\*(?!/))*") + '*/').setName("c_comment")
    singleline_cmnt = Regex(r"//(?:\\\n|[^\n])*").setName("// comment") # Comment of the form //
    cppstyle_cmnt = Combine(multiline_cmnt | singleline_cmnt).setName("C++ style comment") #both sigle+multi
    with open(filename) as f:
        cfile = f.read()
        res = cppstyle_cmnt.scanString(cfile)
        cmnt_list = [(startPos,EndPos) for tokens, startPos, EndPos in res]
        # print(len(cmnt_list))
        total_lines = 0
        for posn in cmnt_list:
            # print(line_number(filename,posn[1]-1)-line_number(filename,posn[0])+1)
            # print(lineno(posn[0],f.read()), lineno(posn[1]-1,f.read()))
            #print(posn[0],posn[1],lineno(posn[1],cfile),lineno(posn[0],cfile))
            total_lines += lineno(posn[1],cfile)-lineno(posn[0],cfile)+1
        # print(cmnt_list)
        return total_lines


def blanklines_count(filename):
    blanks = 0
    with open(filename) as f:
        for line in f.readlines():
            if not line.strip():
                blanks += 1
    return blanks

def macros_count(filename):
    macrodef = "#" + ZeroOrMore(' ') + "define" + Word(alphas+"_"+alphanums).setResultsName("macro") + empty + restOfLine.setResultsName("value")

    with open(filename) as f:
        string = f.read()
        string = re.sub(re.compile("/\*.*?\*/",re.DOTALL ) ,"" ,string)
        string = re.sub(re.compile("//.*?\n" ) ,"" ,string)
        res = macrodef.scanString(string)
        macros = [tokens.macro for tokens, startPos, EndPos in res]
        # print(macros)
    return len(macros)

def variables_count(filename):
    f2 = open("only_variable.c","w+")
    f2.close()
    allvariables("temp_variable_file.c","only_variable.c")
    os.system("gccxml -std=c89 {} -fxml={} > {}".format("only_variable.c",xmlfile_variable,logfile))
    tree = ET.parse(xmlfile_variable)
    root = tree.getroot()
    variables = []
    for variable in root.findall('Variable'):
        if variable.get('file') == fileid:
            variables.append(variable.get('name'))
    # print(variables)
    return len(variables)


def fdecl_count(filename):
    tree = ET.parse(xmlfile)
    root = tree.getroot()
    function_lines = []
    function_lines1 = []
    function_names = []
    non_void_function_names = []
    void_function_names = []
    void_type = []
    for fundametaltype in root.findall('FundamentalType'):
        if fundametaltype.get('name') == 'void':
            void_type.append(fundametaltype.get('id'))
    print(void_type)
    declare_names = ['if','then','else','do','while','for','case','when','return']
    fdecl = 0
    for function in root.findall('Function'):
        if function.get('file') != fileid: continue
        temporary = function.get('line')
        function_lines.append(temporary)
        function_lines1.append(int(temporary))
        if function.get('returns') not in void_type:
            non_void_function_names.append(function.get('name'))
        else :
            void_function_names.append(function.get('name'))
    print( non_void_function_names)
    print(void_function_names)
    f1 = open(filename,"r")
    f2 = open("temp_variable_file.c","w+")
    all_file_lines = f1.readlines()
    i = 0
    for lines in all_file_lines:
        i = i + 1
        if i not in function_lines1:
            f2.write(lines)
    f2.close()
    s1 = ""
    with open("temp_variable_file.c") as f3:
        s = f3.read()
        declare = re.compile(r'\b(?:%s)\b.*?\n' % '|'.join(declare_names))
        s = re.sub(declare ,"" ,s)
        v_f_name = re.compile(r'\b(?:%s)\b[^)\n]*?\)' % '|'.join(void_function_names))
        s = re.sub(v_f_name ,"" ,s)
        nv_f_name = re.compile(r'\b(?:%s)\b[^)\n]*?\)' % '|'.join(non_void_function_names))
        s = re.sub(nv_f_name ,"0" ,s)
        s = re.sub(re.compile("{" ) ,"" ,s)
        s = re.sub(re.compile("}" ) ,"" ,s)
        s1 = s
        f3.close()
    f4 = open("temp_variable_file.c","w+")
    f4.write(s1)
    f4.close()

    with open(filename) as f:
        filelines = f.readlines()
        for line_no in function_lines:
            if (filelines[int(line_no) - 1].strip())[-1:] == ';':
                fdecl += 1
                print(filelines[int(line_no) - 1]) #func declaration lines

    return fdecl

def fdef_count(filename):
    # with open(filename) as f:
    #     for line in f.readlines():
    #         do_something(line)
    return total_functions(filename)-fdecl_count(filename)


def total_functions(filename):
    tree = ET.parse(xmlfile)
    root = tree.getroot()
    functions = []
    for function in root.findall('Function'):
        if function.get('file') == fileid:
            functions.append(function.get('name'))
    # print(variables)
    return len(functions)


def analyzer(filename):
#     os.system("gccxml -std=c89 {} -fxml={} > {}".format(filename,xmlfile,logfile))
    output_file = open("output.txt","w")
    s1 = statements_count(filename)
    s2 = total_commented_lines(filename)
    s3 = blanklines_count(filename)
    s4 = macros_count(filename)
    s6 = fdecl_count(filename)
    s7 = total_functions(filename) - s6
    s5 = variables_count(filename)
    output_file.write("{}) source code statements   : {} \n".format(1,s1))
    output_file.write("{}) comments                 : {} \n".format(2,s2))
    output_file.write("{}) blank lines              : {} \n".format(3,s3))
    output_file.write("{}) macro definitions        : {} \n".format(4,s4))
    output_file.write("{}) variable declarations    : {} \n".format(5,s5))
    output_file.write("{}) function declarations    : {} \n".format(6,s6))
    output_file.write("{}) function definitions     : {} \n".format(7,s7))



if __name__ == "__main__":
    if len(sys.argv) > 1:
        filename  = sys.argv[1]
    else:
        filename = 'temp.c'   # default file
    os.system("gccxml -std=c89 {} -fxml={} > {}".format(filename,xmlfile,logfile))
    fileid = find_fileid(filename,xmlfile)    
    analyzer(filename)
    # for i in range(15):
    # print(line_number(filename,76))
