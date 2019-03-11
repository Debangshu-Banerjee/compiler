%{
int cmnt_start = 0,total_multilines=0;
int a=0,b=0,c=0,d,lines=0;
int blanklines=0;
int chars=0;
int macros=0;
int variables=0;
%}
%x COMMENT
%%
"//".*   {chars++;a++;}
"/*"     { chars++;cmnt_start=lines;BEGIN COMMENT; }
<COMMENT>{
"*/"      {chars++;c++;total_multilines+=lines-cmnt_start+1;BEGIN(INITIAL);}
[^*\n]+   {chars++;}
"*"       {chars++;}
[a-zA-Z] {chars++;}
.  {chars++;}
\n { yylineno++;lines++;if(chars==0) blanklines++;chars=0; }
}
("int "|"int *"|"char "|"char *"|"float "|"float *")+[a-zA-Z]+[a-zA-Z0-9]*+\s*+(;|(,|=).*;)  {chars++;variables++;}
"#define"+[ \t]*+[0-9a-zA-Z_]*+[ \t]* {chars++;macros++;}
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
}
