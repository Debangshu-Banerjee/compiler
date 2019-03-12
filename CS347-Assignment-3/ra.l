%{
int valid=0;
%}

%%
"SELECT "+"<"+.*+">"+.*+"("+.*+")"  {printf("SELECT");valid=1;}
"PROJECT "+"<"+.*+">"+.*+"("+.*+")"  {printf("PROJECT");valid=1;}
"("+.*+")"+.*+"CARTESIAN_PRODUCT"+.*+"("+.*+")"  {printf("CARTESIAN_PRODUCT");valid=1;}
"("+.*+")"+.*+"EQUI_JOIN"+.*+"<"+.*+">"+.*+"("+.*+")"  {printf("EQUI_JOIN");valid=1;}
. {valid=0;}

%%

void main(){
    yylex();
    if(valid==0) printf("invalid syntax");
    else printf("valid syntax");

}
