%{
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void yyerror(char *s){
	fprintf (stderr, "%s\n", s);

}


char* given_input;
int my_type;

%}

%union{ char Char;}

%token <Char> ERROR NUM WHITE_SPACE SEMI LESS_THAN GRE_THAN LB_ROUND RB_ROUND AMP COMMA PLUS MINUS TIMES DIV EQUAL DOT AND OR NOT STRING SELECT PROJECT CARTESIAN_PRODUCT EQUI_JOIN ID ENDLN GRE_THAN_EQ LESS_THAN_EQ

%start INITIAL

%%
INITIAL:          QUERY ENDLN          { printf("INITIAL -> QUERY \n"); printf("\n the string is valid\n"); printf("\n%s\n",given_input); handle_cpp_file(my_type, given_input);return 0;}
                  ;

QUERY:             SELECTION           {printf("QUERY -> SELECTION\n"); my_type = 0;}
                  | PROJECTION          {printf("QUERY -> PROJECTION\n"); my_type = 1;}
                  | PRODUCT_CART         {printf("QUERY -> PRODUCT_CART\n"); my_type = 2;}
                  | JOINING             {printf("QUERY -> JOINING\n");my_type = 3;}
                  ;

SELECTION:      SELECT LESS_THAN CONDITION GRE_THAN LB_ROUND ID RB_ROUND     {printf("SELECTION -> SELECT <condition> (Table_Name)\n");}
                ;

PROJECTION:     PROJECT LESS_THAN ATTRIBUTE_LIST GRE_THAN LB_ROUND ID RB_ROUND {printf("PROJECTION -> PROJECT <attribute_list> (Table_Name)\n");}
                ;

PRODUCT_CART:   LESS_THAN ID GRE_THAN CARTESIAN_PRODUCT LESS_THAN ID GRE_THAN  {printf("PRODUCT_CART -> < Table_Name_1 > CARTESIAN_PRODUCT < Table_Name_2 >\n");}
                ;

JOINING:   LESS_THAN ID GRE_THAN EQUI_JOIN LESS_THAN CONDITION GRE_THAN LESS_THAN ID GRE_THAN {printf("JOINING -> < Table_Name_1 > EQUI_JOIN <condition> < Table_Name_2 >\n");}
            ;

CONDITION:    CONDITION_SMALL CONDITION_PRIME      {printf("CONDITION -> CONDITION_SMALL CONDITION_PRIME\n");strcat(given_input,"$");}
            | NOT CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION -> NOT CONDITION_SMALL CONDITION_PRIME\n");}
            ;

CONDITION_SMALL:   COMPARISON_COND               {printf("CONDITION_SMALL -> COMPARISON_COND \n");}
                  | LB_ROUND CONDITION RB_ROUND   {printf("CONDITION_SMALL -> LB_ROUND CONDITION RB_ROUND \n");}
                  ;

CONDITION_PRIME:   AND CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> AND CONDITION_SMALL CONDITION_PRIME\n");}
                  | OR CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> OR CONDITION_SMALL CONDITION_PRIME\n");}
                  | AND NOT CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> AND NOT CONDITION_SMALL CONDITION_PRIME\n");}
                  | OR NOT CONDITION_SMALL CONDITION_PRIME  {printf("CONDITION_PRIME -> OR NOT CONDITION_SMALL CONDITION_PRIME\n");}
                  | /* empty */                             {printf("CONDITION_PRIME -> epsilon\n");}
                  ;

COMPARISON_COND:   EXPR EQUAL EXPR    {printf("COMPARISON_COND -> EXPR EQUAL EXPR\n");}
                  | EXPR GRE_THAN EQUAL EXPR    {printf("COMPARISON_COND -> EXPR GRE_THAN EQUAL EXPR\n");}
                  | EXPR LESS_THAN EQUAL EXPR    {printf("COMPARISON_COND -> EXPR LESS_THAN EQUAL EXPR\n");}
                  | EXPR GRE_THAN EXPR    {printf("COMPARISON_COND -> EXPR GRE_THAN EXPR\n");}
                  | EXPR LESS_THAN EXPR    {printf("COMPARISON_COND -> EXPR LESS_THAN EXPR\n");}
                  | EXPR GRE_THAN_EQ EXPR  {printf("COMPARISON_COND -> EXPR GRE_THAN_EQUAL EXPR\n");}
                  | EXPR LESS_THAN_EQ EXPR  {printf("COMPARISON_COND -> EXPR LESS_THAN_EQUAL EXPR\n");}
                  ;

EXPR:    TERM EXPR_PRIME  {printf("EXPR -> TERM EXPR_PRIME\n");}
          ;

EXPR_PRIME:    PLUS TERM EXPR_PRIME    {printf("EXPR_PRIME -> PLUS TERM EXPR_PRIME\n");}
              | MINUS TERM EXPR_PRIME  {printf("EXPR_PRIME -> MINUS TERM EXPR_PRIME\n");}
              |  /* empty */           {printf("EXPR_PRIME -> epsilon\n");}
              ;

TERM:      FACTOR TERM_PRIME    {printf("TERM -> FACTOR TERM_PRIME\n");}
            ;

TERM_PRIME:    TIMES FACTOR TERM_PRIME     {printf("TERM_PRIME -> TIMES FACTOR TERM_PRIME\n");}
              | DIV FACTOR TERM_PRIME      {printf("TERM_PRIME -> DIV FACTOR TERM_PRIME\n");}
              | /* empty */                  {printf("TERM_PRIME -> epsilon\n");}
              ;

FACTOR:      ID            {printf("FACTOR -> ID\n");}
            | NUM          {printf("FACTOR -> NUM\n");}
            | STRING       {printf("FACTOR -> STRING\n");}
            | ID DOT ID    {printf("FACTOR -> ID DOT ID\n");}
            ;

ATTRIBUTE_LIST:     ID ATTRIBUTE_LIST_PRIME    {printf("ATTRIBUTE_LIST -> ID ATTRIBUTE_LIST_PRIME\n");}
                    ;

ATTRIBUTE_LIST_PRIME:   COMMA ID ATTRIBUTE_LIST_PRIME    {printf("ATTRIBUTE_LIST_PRIME -> COMMA ID ATTRIBUTE_LIST_PRIME\n");}
                       | /* empty */                     {printf("ATTRIBUTE_LIST_PRIME -> epsilon\n");}
                       ;

%%
struct attribute{
	char attribute_name[200];
	int type;                     /* int,float or double = 0 and strings = 1*/
	struct attribute * next;	

};

struct projection{
	char attribute_name [200];
	struct projection* next ;
};

struct attribute* get_attributes( FILE * fp){
	char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int temp =0;
    struct attribute* head= NULL;
    struct attribute* prev = NULL;
    while((read = getline(&line, &len, fp)) != -1){
    	if(temp >= 2) break;
    	char *token;
    	token=strtok(line,",\n");
    	if(temp == 0){
    		while(token != NULL){
    			struct attribute* tem1 = (struct attribute*)malloc(sizeof(struct attribute));
    			strcpy(tem1->attribute_name,token);
    			tem1->next = NULL;
    			tem1->type = 0;
    			if(prev == NULL){
    				head = tem1;
    			}
    			else{
    				prev->next = tem1;
    			}
    			prev = tem1;
    			token=strtok(NULL,",\n");
    			
    		}
    	}
    	else{
    		struct attribute* t= head;
    		while(token != NULL && t!= NULL){
    			char *ptr = NULL;
   				double ret = 0.0;
   				ret = strtod(token, &ptr);
   				if(strlen(ptr)){
   					t->type = 1;
   				}
   				else{
   					t->type = 0;
   				}
    			token=strtok(NULL,",\n");
    			t= t->next;
    		}

    	}	
    	temp++;
    }
    return head;
}

int search(struct attribute* head, char* s){
	int i=0;
	while(head){
		if(strcmp(head->attribute_name,s) == 0) return i;
		i++; head = head->next;
	}
	return -1;
}
int search1(int* index,int size,int key){
	int i=0;
	for(i=0;i<size;i++){
		if(index[i] == key) return 1;
	}	
	return 0;
}
void genarate_output_file_equi( char* condition,char* fname1,char* fname2,struct attribute* head1,struct attribute* head2){
	FILE *fp = fopen("output_file.cpp","w");
	fprintf(fp,"#include<bits/stdc++.h>\n\n");
	fprintf(fp,"using namespace std;\n\n");
	fprintf(fp,"int main(){\n\n"); /* opened int main()*/
	struct attribute* t= head1;
	while(t){
	 	if(t->type == 0){
	 		fprintf(fp,"double %s_%s;\n\n",fname1,t->attribute_name);
	 	}
	 	else{
	 		fprintf(fp,"string %s_%s;\n\n",fname1,t->attribute_name);
	 	}
	 	t=t->next;
	}
	 t= head2;
	 while(t){
	 	if(t->type == 0){
	 		fprintf(fp,"double %s_%s;\n\n",fname2,t->attribute_name);
	 	}
	 	else{
	 		fprintf(fp,"string %s_%s;\n\n",fname2,t->attribute_name);
	 	}
	 	t=t->next;
	}
	char file_name[1000]; /******************needs attention***************/
	sprintf(file_name,"ifstream fp1(\"%s\");",fname1);  /* opened file in cpp file*/
	fprintf(fp,"%s\n\n",file_name);
	sprintf(file_name,"ifstream fp2(\"%s\");",fname2);  /* opened file in cpp file*/
	fprintf(fp,"%s\n\n",file_name);
	fprintf(fp,"string a12b1;\n\n");
	fprintf(fp,"string a12b2;\n\n");
	fprintf(fp,"\ngetline(fp1,a12b1);\n");
	fprintf(fp,"\ngetline(fp2,a12b2);\n");
	fprintf(fp,"cout<<a12b1<<\" | \"<<a12b2<<endl;\n\n");
	fprintf(fp,"fp2.close();\n\n"); /* closed file in cpp file*/
	fprintf(fp,"while (getline(fp1,a12b1)){\n\n"); /*1st while start*/
	sprintf(file_name,"ifstream fp2(\"%s\");",fname2);  /* opened file in cpp file*/
	fprintf(fp,"\t%s\n",file_name);
	fprintf(fp,"\n\tgetline(fp2,a12b2);\n");
	fprintf(fp,"\tstringstream check11(a12b1);\n");
	 fprintf(fp,"\tstring intermediate1;\n");
	 t = head1;
	 fprintf(fp,"\n\n");
	 while(t){
	 	fprintf(fp,"\tgetline(check11, intermediate1, ',');\n");
	 	if(t->type == 0){
	 		sprintf(file_name,"%s_%s = stod(intermediate1);\n",fname1,t->attribute_name);
	 		fprintf(fp,"\t%s",file_name);
	 	}
	 	else{
	 		sprintf(file_name,"%s_%s= intermediate1;\n",fname1,t->attribute_name);
	 		fprintf(fp,"\t%s",file_name);
	 	}
	 	fprintf(fp,"\n\n");
	 	t= t->next;
	 }			
	fprintf(fp,"\twhile (getline(fp2,a12b2)){\n"); 			/*2nd while start*/

	t = head2;
	 fprintf(fp,"\n\n");
	 fprintf(fp,"\t\tstringstream check12(a12b2);\n");
	 fprintf(fp,"\t\tstring intermediate2;\n");
	 while(t){
	 	fprintf(fp,"\t\tgetline(check12, intermediate2, ',');\n");
	 	if(t->type == 0){
	 		sprintf(file_name,"%s_%s = stod(intermediate2);\n",fname2,t->attribute_name);
	 		fprintf(fp,"\t\t%s",file_name);
	 	}
	 	else{
	 		sprintf(file_name,"%s_%s= intermediate2;\n",fname2,t->attribute_name);
	 		fprintf(fp,"\t\t%s",file_name);
	 	}
	 	fprintf(fp,"\n\n");
	 	t= t->next;
	 }			

	sprintf(file_name,"if(%s){\n",condition); 			/* if start*/
	fprintf(fp,"\t\t%s",file_name);
	fprintf(fp,"\t\t\tcout<<a12b1<<\" | \"<<a12b2<<endl;\n");
	fprintf(fp,"\t\t}\n"); 								/* if end*/
	fprintf(fp,"\t}\n"); 								/* 2nd while end*/
	fprintf(fp,"fp2.close();\n\n"); 				/* closed file in cpp file*/
	fprintf(fp,"}\n"); 									/*end of 1 st while*/
	fprintf(fp,"fp1.close();\n\n"); 				/* closed file in cpp file*/	
	fprintf(fp,"}\n"); 									/*end of main*/
}
void genarate_output_file_c_prod( char* fname1,char* fname2,struct attribute* head1,struct attribute* head2){
	FILE *fp = fopen("output_file.cpp","w");
	fprintf(fp,"#include<bits/stdc++.h>\n\n");
	fprintf(fp,"using namespace std;\n\n");
	fprintf(fp,"int main(){\n\n"); /* opened int main()*/
	struct attribute* t= head1;
	while(t){
	 	if(t->type == 0){
	 		fprintf(fp,"double %s_%s;\n\n",fname1,t->attribute_name);
	 	}
	 	else{
	 		fprintf(fp,"string %s_%s;\n\n",fname1,t->attribute_name);
	 	}
	 	t=t->next;
	}
	 t= head2;
	 while(t){
	 	if(t->type == 0){
	 		fprintf(fp,"double %s_%s;\n\n",fname2,t->attribute_name);
	 	}
	 	else{
	 		fprintf(fp,"string %s_%s;\n\n",fname2,t->attribute_name);
	 	}
	 	t=t->next;
	}
	char file_name[1000];
	sprintf(file_name,"ifstream fp1(\"%s\");",fname1);  /* opened file in cpp file*/
	fprintf(fp,"%s\n\n",file_name);
	sprintf(file_name,"ifstream fp2(\"%s\");",fname2);  /* opened file in cpp file*/
	fprintf(fp,"%s\n\n",file_name);
	fprintf(fp,"string a12b1;\n\n");
	fprintf(fp,"string a12b2;\n\n");
	fprintf(fp,"\ngetline(fp1,a12b1);\n");
	fprintf(fp,"\ngetline(fp2,a12b2);\n");
	fprintf(fp,"cout<<a12b1<<\" | \"<<a12b2<<endl;\n\n");
	fprintf(fp,"fp2.close();\n\n"); /* closed file in cpp file*/
	fprintf(fp,"while (getline(fp1,a12b1)){\n\n"); /*1st while start*/
	sprintf(file_name,"ifstream fp2(\"%s\");",fname2);  /* opened file in cpp file*/
	fprintf(fp,"\t%s\n",file_name);
	fprintf(fp,"\n\tgetline(fp2,a12b2);\n");
	fprintf(fp,"\twhile (getline(fp2,a12b2)){\n"); /*2nd while start*/
	fprintf(fp,"\t\tcout<<a12b1<<\" | \"<<a12b2<<endl;\n");
	fprintf(fp,"\t}\n"); /* 2nd while end*/
	fprintf(fp,"fp2.close();\n\n"); /* closed file in cpp file*/
	fprintf(fp,"}\n"); /* 1st while end*/
	fprintf(fp,"fp1.close();\n\n"); /* closed file in cpp file*/	
	fprintf(fp,"}\n");	

}

void genarate_output_file_project( int* index,char* fname,struct attribute* head,int size){
	 FILE *fp = fopen("output_file.cpp","w");
	 fprintf(fp,"#include<bits/stdc++.h>\n\n");
	 fprintf(fp,"using namespace std;\n\n");
	 fprintf(fp,"int main(){\n\n"); /* opened int main()*/
	 struct attribute* t= head;
	 while(t){
	 	if(t->type == 0){
	 		fprintf(fp,"double %s;\n\n",t->attribute_name);
	 	}
	 	else{
	 		fprintf(fp,"string %s;\n\n",t->attribute_name);
	 	}
	 	t=t->next;
	 }
	 char file_name[1000];
	 sprintf(file_name,"ifstream fp(\"%s\");",fname);  /* opened file in cpp file*/
	 fprintf(fp,"%s\n\n",file_name);
	 fprintf(fp,"string a12b;\n\n");
	 fprintf(fp,"while (getline(fp,a12b)){\n\n");/* while start*/
	 fprintf(fp,"\tstringstream check1(a12b);\n");
	 fprintf(fp,"\tstring intermediate;\n");
	 t= head;
	 int temp_index = 0;
	 int s_c = 0;
	 while(t){	 
	 	fprintf(fp,"\tgetline(check1, intermediate, ',');\n");
	 	if(search1(index,size,temp_index) == 1){
	 		if(s_c == 0){
	 			s_c++;fprintf(fp,"\tcout<<intermediate;\n");
	 		}
	 		else{
	 			fprintf(fp,"\tcout<<\",\"<<intermediate;\n");
	 		}	
	 	}
	 	fprintf(fp,"\n\n");
	 	t=t->next;
	 	temp_index++;
	 }
	 fprintf(fp,"cout<<endl;\n\n");
	 fprintf(fp,"}\n"); /* while end*/
	 fprintf(fp,"fp.close();\n\n"); /* closed file in cpp file*/
	 fprintf(fp,"}\n");	

}




void genarate_output_file_select(char* condition,char* fname,struct attribute* head){
	 FILE *fp = fopen("output_file.cpp","w");
	 fprintf(fp,"#include<bits/stdc++.h>\n\n");
	 fprintf(fp,"using namespace std;\n\n");
	 fprintf(fp,"int main(){\n\n");               /* opened int main()*/
	 struct attribute* t= head;
	 while(t){
	 	if(t->type == 0){
	 		fprintf(fp,"double %s;\n\n",t->attribute_name);
	 	}
	 	else{
	 		fprintf(fp,"string %s;\n\n",t->attribute_name);
	 	}
	 	t=t->next;
	 }
	 char file_name[1000];
	 sprintf(file_name,"ifstream fp(\"%s\");",fname);  /* opened file in cpp file*/
	 fprintf(fp,"%s\n\n",file_name);

	 fprintf(fp,"string a12b;\n\n");
	 fprintf(fp,"\ngetline(fp,a12b);\n");
	 fprintf(fp,"while (getline(fp,a12b)){\n\n");/* while start*/
	 fprintf(fp,"\tstringstream check1(a12b);\n");
	 fprintf(fp,"\tstring intermediate;\n");
	 t = head;
	 fprintf(fp,"\n\n");
	 while(t){
	 	fprintf(fp,"\tgetline(check1, intermediate, ',');\n");
	 	if(t->type == 0){
	 		sprintf(file_name,"%s = stod(intermediate);\n",t->attribute_name);
	 		fprintf(fp,"\t%s",file_name);
	 	}
	 	else{
	 		sprintf(file_name,"%s = intermediate;\n",t->attribute_name);
	 		fprintf(fp,"\t%s",file_name);
	 	}
	 	fprintf(fp,"\n\n");
	 	t= t->next;
	 }	
	 sprintf(file_name,"if(%s){\n",condition);
	 fprintf(fp,"\t%s",file_name);
	 fprintf(fp,"\t\tcout<<a12b<<endl;\n");
	 fprintf(fp,"\t}");
	 fprintf(fp,"\n\n");

	 fprintf(fp,"}\n"); /* while end*/
	 fprintf(fp,"fp.close();\n\n"); /* closed file in cpp file*/
	 fprintf(fp,"}\n"); /* closed int main()*/
	 fclose(fp);
}


void handle_cpp_file(int my_type,char* given_input){
	if(my_type == 0){
		int i =0;
		int len = strlen(given_input);
		while(i< len){
			if(given_input[i] == '<'){break;}
			i++;
		}
		i++;
		char* condition = (char*) malloc(1000 * sizeof(char));
		int j=0;
		while(i<len){
			if(given_input[i] == '$' ) break;
			condition[j] = given_input[i];
			i++;j++;
		}
		j--;
		while(j>=0){
			if(condition[j] == '>' ){
				condition[j] = '\0';
				break;
			}
			j--;
		}
		int s_fname = 0;
		j=0;
		char* fname = (char*) malloc(100 * sizeof(char));
		while(i<len){
			if(given_input[i] == '(' ) {s_fname = 1;i++;continue;}
			if(s_fname == 1){
				while(isalnum(given_input[i])){
				   if(given_input[i] == ')') break;
				   fname[j] = given_input[i];
				   i++;j++;
				}
				fname[j]='\0';
				break;
			}
		    i++;
		}
		FILE * fp = fopen(fname,"r");
		if(fp == NULL){
			printf(" Table name entered is not present in database\n");
			return;
		}
		struct attribute* head = get_attributes(fp);
		fclose(fp);
		genarate_output_file_select(condition,fname,head);

	}
	else if(my_type == 1){
		char* str1 = (char*)malloc(2000*sizeof(char));
		int i=0;
		int len= strlen(given_input);
		while(i<len){
			if(given_input[i] == '<'){i++;break;}
			i++;
		}
		int j=0;
		while(i<len){
			if(given_input[i] == '>'){
				i++;
				str1[j]='\0';break;
			}
			str1[j]= given_input[i];
			i++;j++;
		}
		char * token = strtok(str1,",\n");
		struct projection* p_head=NULL;
		struct projection* p_prev = NULL;
		while(token!=NULL){
			struct projection* tem1 = (struct projection*)malloc(sizeof(struct projection));
			strcpy(tem1->attribute_name,token);
			tem1->next =NULL;
			if(p_prev == NULL){
				p_head = tem1;
			}
			else{
				p_prev->next = tem1;
			}
			token=strtok(NULL,",\n");
			p_prev = tem1;
		}
		j=0;
		struct projection * t= p_head;

		char* fname = (char*)malloc(100*sizeof(char));
		int s_fname = 0;
		while(i<len){
			if(s_fname == 1){
				if(given_input[i]==')'){
					fname[j]='\0';break;
				}
				fname[j]= given_input[i];j++;
			}
			else{
				if(given_input[i]=='(') s_fname = 1;
			}
			i++;	
		}
		FILE * fp = fopen(fname,"r");
		if(fp == NULL){
			printf(" Table name entered is not present in database\n");
			return;
		}
		struct attribute* head = get_attributes(fp);
		fclose(fp);
		int * index = (int *)malloc(100*sizeof(int));
		j=0;
		while(p_head){
			index[j]=search(head,p_head->attribute_name);
			if(index[j] < 0){
				printf("The attribute is not present in database\n");
				return;
			}
			p_head = p_head-> next;
			j++;
		}
		genarate_output_file_project(index, fname,head,j);
	}
	else if(my_type == 2){
		int i=0;
		int len = strlen(given_input);
		char* fname1 = (char*)malloc(200*sizeof(char));
		char* fname2 = (char*)malloc(200*sizeof(char));
		int s_fname =0;
		int j=0;
		while(i<len){
			if(s_fname == 1){
				if(given_input[i]== '>'){
					fname1[j]='\0';break;
				}
				fname1[j]=given_input[i];
				j++;
			}
			else{
				if(given_input[i]=='<') s_fname = 1;
			}
			i++;
		}
		while(i<len){
			if(given_input[i] == '<') break;
			i++;
		}
		s_fname = 0;
		j=0;
		while(i<len){
			if(s_fname == 1){
				if(given_input[i]== '>'){
					fname2[j]='\0';break;
				}
				fname2[j]=given_input[i];
				j++;
			}
			else{
				if(given_input[i]=='<') s_fname = 1;
			}
			i++;
		}
		printf("%s %s\n",fname1,fname2);
		FILE * fp = fopen(fname1,"r");
		if(fp == NULL){
			printf(" Table name %s entered is not present in database\n",fname1);
			return;
		}
		struct attribute* head1 = get_attributes(fp);
		fclose(fp);
		fp = fopen(fname2,"r");
		if(fp == NULL){
			printf(" Table name %s entered is not present in database\n",fname2);
			return;
		}
		struct attribute* head2 = get_attributes(fp);
		fclose(fp);
		genarate_output_file_c_prod(fname1,fname2,head1, head2);
	}
	else if(my_type == 3){
		int i=0;
		int len = strlen(given_input);
		char* fname1 = (char*)malloc(200*sizeof(char));
		char* fname2 = (char*)malloc(200*sizeof(char));
		int s_fname =0;
		int j=0;
		while(i<len){
			if(s_fname == 1){
				if(given_input[i]== '>'){
					fname1[j]='\0';break;
				}
				fname1[j]=given_input[i];
				j++;
			}
			else{
				if(given_input[i]=='<') s_fname = 1;
			}
			i++;
		}

		while(i< len){
			if(given_input[i] == '<'){break;}
			i++;
		}
		i++;
		char* condition = (char*) malloc(1000 * sizeof(char));
		j=0;
		while(i<len){
			if(given_input[i] == '$' ) break;
			condition[j] = given_input[i];
			i++;j++;
		}
		j--;
		while(j>=0){
			if(condition[j] == '>' ){
				condition[j] = '\0';
				break;
			}
			j--;
		}
		s_fname = 0;
		j=0;
		while(i<len){
			if(s_fname == 1){
				if(given_input[i]== '>'){
					fname2[j]='\0';break;
				}
				fname2[j]=given_input[i];
				j++;
			}
			else{
				if(given_input[i]=='<') s_fname = 1;
			}
			i++;
		}
		printf("%s\n %s\n %s\n",fname1,fname2,condition);
		FILE * fp = fopen(fname1,"r");
		if(fp == NULL){
			printf(" Table name %s entered is not present in database\n",fname1);
			return;
		}
		struct attribute* head1 = get_attributes(fp);
		fclose(fp);
		fp = fopen(fname2,"r");
		if(fp == NULL){
			printf(" Table name %s entered is not present in database\n",fname2);
			return;
		}
		struct attribute* head2 = get_attributes(fp);
		fclose(fp);
		genarate_output_file_equi(condition,fname1,fname2,head1, head2);

	}
	
}


int main(){
    given_input = (char*)malloc(10000*sizeof(char));
    given_input[0]= '\0';
	yyparse();
  //  printf("%d",my_type);

	return 0;
}
