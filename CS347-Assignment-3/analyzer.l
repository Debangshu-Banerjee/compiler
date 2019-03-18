%{
int cmnt_start = 0,total_multilines=0;
int prev_line = -1;
int prev_line_func = -1;
int a=0,b=0,c=0,d,lines=0;
int blanklines=0;
int chars=0;
int macros=0;
int variables=0;
int f_dec=0;
int f_def=0;
%}
%x COMMENT
%x FUNC
%x STRUCT_STATE
VARIABLE1  ("extern "|"signed "|"unsigned "|"")[ \t]*("int "|"char "|"float "|"double ")[ \t\*]*[a-zA-Z_][a-zA-Z0-9]*[ \t]*
VARIABLE2  ("extern ")[ \t]*[a-zA-Z][a-zA-Z0-9]*[ \t]*
VAR_STR ("extern "|"")[ \t]*("struct ")[ \t]*[a-zA-Z][a-zA-Z0-9]*(" ")[ \t\*]*[a-zA-Z_][a-zA-Z0-9]*[ \t]*
FUNCTIONAL_VAR1 ("extern "|"signed "|"unsigned "|"")[ \t]*("int "|"char "|"float "|"double ")[ \t\*]*
FUNCTIONAL_VAR2 ("extern ")
FUNCTIONAL_VAR_STR ("extern "|"")[ \t]*("struct ")[ \t]*[a-zA-Z_][a-zA-Z0-9]*(" ")[ \t\*]*
WHITE_SPACE [ \t]
%%
"//".*   {chars++;a++;}
"/*"     { chars++;cmnt_start=lines;BEGIN COMMENT; }
<COMMENT>{
"*/"      {chars++;c++;total_multilines+=lines-cmnt_start+1;BEGIN(INITIAL);}
[^*\n]+   {chars++;}
"*"       {chars++;}
\n { yylineno++;lines++;if(chars==0) blanklines++;chars=0; }
}
("struct ")[ \t]*[a-zA-Z][a-zA-Z0-9]*[ \t]*("{") {chars++;BEGIN STRUCT_STATE;}
<STRUCT_STATE>{
[^ \t\n\}]+ {chars++;}
[ \t]+
"\n" {if(chars==0) blanklines++;lines++;chars=0;}
"}" {chars++;BEGIN(INITIAL);}
}

({VARIABLE1}|{VARIABLE2}|{VAR_STR})(";"|","|"=") {chars++;if(lines!=prev_line){variables++;prev_line = lines;}}
({FUNCTIONAL_VAR1}|{FUNCTIONAL_VAR2}|{FUNCTIONAL_VAR_STR}|("void "))[ \t]*[a-zA-Z_][a-zA-Z0-9]*[ \t]*("(")[^\n\)]*(")") {chars++;BEGIN FUNC;}
<FUNC>{
[ \t]*";" {chars++;if(prev_line_func !=lines)f_dec++; prev_line_func = lines;BEGIN(INITIAL);}
[ \t]*"{" {chars++;f_def++;BEGIN(INITIAL);}
[ \t]*"\n" {f_def++;if(chars==0) blanklines++;chars=0;lines++;BEGIN(INITIAL);}
[ \t]*("//"|"/*").* {chars++;a++;}
}

"#define "[ \t]*[a-zA-Z_][0-9a-zA-Z_]*[ \t]* {chars++;macros++;}
[a-zA-Z] {chars++;}
.  {chars++;}
\n { lines++;if(chars==0) blanklines++;chars=0; }
%%
void main(){
    yylex();
    FILE * outfile = fopen("out.txt", "w");
    /*printf("single line %d \nmultiline %d \n",a,c);*/
    fprintf(outfile,"total lines %d \n",lines);
    fprintf(outfile,"blank lines %d \n",blanklines);
    d=a+c;
    fprintf(outfile,"total commented lines %d \n",total_multilines+a);
    fprintf(outfile,"total macros %d \n",macros);
    fprintf(outfile,"total variables %d \n",variables);
    fprintf(outfile,"function declarations: %d \n",f_dec);
    fprintf(outfile,"function definitions: %d \n",f_def);
}
