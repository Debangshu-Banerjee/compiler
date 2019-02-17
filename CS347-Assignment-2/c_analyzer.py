import sys,os
import re
import xml.etree.ElementTree as ET
from pyparsing import *

xmlfile = "temp.xml"
logfile = "logs.txt"
outputfile = "output.txt"

def line_number(filename,index):
    ct = 0
    index += 1
    line_no = 1
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
            # print(posn[0],posn[1],lineno(posn[1],cfile),lineno(posn[0],cfile))
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
    tree = ET.parse(xmlfile)
    root = tree.getroot()
    variables = []
    for variable in root.findall('Variable'):
        variables.append(variable.get('name'))
    # print(variables)
    return len(variables)


def fdecl_count(filename):
    tree = ET.parse(xmlfile)
    root = tree.getroot()
    function_lines = []
    for function in root.findall('Function'):
        function_lines.append(function.get('line'))
    # print(function_lines)
    fdecl = 0
    with open(filename) as f:
        filelines = f.readlines()
        for line_no in function_lines:
            if (filelines[int(line_no) - 1].strip())[-1:] == ';':
                fdecl += 1
                # print(filelines[int(line_no) - 1]) #func declaration lines
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
        functions.append(function.get('name'))
    # print(variables)
    return len(functions)


def analyzer(filename):
    f = open(outputfile, "w+")
    os.system("gccxml -std=c89 {} -fxml={} > {}".format(filename,xmlfile,logfile))
    print("{}) source code statements   : {}".format(1,statements_count(filename)))
    f.write("{}) source code statements   : {}\n".format(1,statements_count(filename)))
    print("{}) comments                 : {}".format(2,total_commented_lines(filename)))
    f.write("{}) comments                 : {}\n".format(2,total_commented_lines(filename)))
    print("{}) blank lines              : {}".format(3,blanklines_count(filename)))
    f.write("{}) blank lines              : {}\n".format(3,blanklines_count(filename)))
    print("{}) macro definitions        : {}".format(4,macros_count(filename)))
    f.write("{}) macro definitions        : {}\n".format(4,macros_count(filename)))
    print("{}) variable declarations    : {}".format(5,variables_count(filename)))
    f.write("{}) variable declarations    : {}\n".format(5,variables_count(filename)))
    print("{}) function declarations    : {}".format(6,fdecl_count(filename)))
    f.write("{}) function declarations    : {}\n".format(6,fdecl_count(filename)))
    print("{}) function definitions     : {}".format(7,fdef_count(filename)))
    f.write("{}) function definitions     : {}\n".format(7,fdef_count(filename)))
    f.close()



if __name__ == "__main__":
    if len(sys.argv) > 1:
        filename  = sys.argv[1]
    else:
        filename = 'temp.c'   # default file
    analyzer(filename)
    # total_commented_lines(filename)
    # with open(filename) as f:
    #     print(lineno(645,f.read()))
    # # for i in range(15):
    # # print(line_number(filename,76))
