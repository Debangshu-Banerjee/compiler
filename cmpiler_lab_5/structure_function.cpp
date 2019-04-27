#include<bits/stdc++.h>
#include "structure_def.h"

using namespace std;

rel_tag_genarator rel_tag;

gloabal_offset_structure global_offset;
extern void yyerror(string s);
extern code_output intermediate_output;
extern user_define_data total_user_variable;
int get_compatible_type_non_bool(int type1 ,int type2){
	if(type1 == ERROR_TYPE || type2 == ERROR_TYPE){
		return ERROR_TYPE;
	}
	if(type1 == BOOL_TYPE || type2 == BOOL_TYPE){
		return ERROR_TYPE;
	}
	if(type1 == VOID_TYPE || type2 == VOID_TYPE){
		return ERROR_TYPE;
	}
	if(type1 == INT_TYPE && type2 == INT_TYPE){
		return INT_TYPE;
	}
	if(type1 == FLOAT_TYPE || type2 == FLOAT_TYPE){
		/* try for type casting */

		return FLOAT_TYPE;
	}
	return ERROR_TYPE;
}

int get_compatible_type_bool_only(int type1 ,int type2){
		if(type1 == BOOL_TYPE && type2 == BOOL_TYPE){
			return BOOL_TYPE;
		}
		else{
			return ERROR_TYPE;
		}
}
int get_compatible_type_rel_op(int type1, int type2){
	if(type1 == ERROR_TYPE || type2 == ERROR_TYPE){
		return ERROR_TYPE;
	}
	if(type1 == BOOL_TYPE && type2 != BOOL_TYPE){
		return ERROR_TYPE;
	}
	if(type1 != BOOL_TYPE && type2 == BOOL_TYPE){
		return ERROR_TYPE;
	}
	return BOOL_TYPE;
}

void sym_tab :: display(){
		if(global_sym_tab.size() == 0){
			cout << "symbol table is empty" << "\n";
		}
		else{
			for(int i = 0;i<global_sym_tab.size();i++){
				cout << "SYMBOL TABLE:" << i+1 << "\n";
				cout << "function_name: " << global_sym_tab[i]->function_name << "\n";
				cout << "result_type: " << global_sym_tab[i]->result_type << "\n";
				cout << "PARAM_LIST:  " << "\n";
				for(int j = 0;j<global_sym_tab[i]->param_list.size();j++){
						cout << "name: " <<  global_sym_tab[i]->param_list[j]->name << " " <<  "type: " << global_sym_tab[i]->param_list[j]->type << "eletype: " << global_sym_tab[i]->param_list[j]->eletype << "\n";
				}
				cout << "local_variable_list: " <<  "\n";
				for(int j = 0;j<global_sym_tab[i]->local_variable_list.size();j++){
					cout << "name: " << global_sym_tab[i]->local_variable_list[j]->name << " " << "type: " << global_sym_tab[i]->local_variable_list[j]->type << " " << "eletype: " << global_sym_tab[i]->local_variable_list[j]->eletype << "\n";
					cout << "dimlist: ";
					for(int k = 0;k<global_sym_tab[i]->local_variable_list[j]->dimlist.size();k++){
						cout << global_sym_tab[i]->local_variable_list[j]->dimlist[k] << " ";
					}
					cout << "\n";
					cout << "level_of_declaration: " << global_sym_tab[i]->local_variable_list[j]->level_of_declaration << "\n";
					cout << "offset: " << global_sym_tab[i]->local_variable_list[j]->offset << "\n";
				}
				cout << "no_of_parameter: " << global_sym_tab[i]->no_of_parameter << "\n";
			}
		}
}

// search in the symbol table for a function_name and return it's index
int sym_tab :: search_func(string function_name){
	for(int i=0;i< this->global_sym_tab.size();i++){
		if(this->global_sym_tab[i]->function_name == function_name ) return i;
	}
	return -1;
}

// note active_function_index 0 will be reserved for global function
int sym_tab :: add_function(string function_name , int result_type){
	sym_tab_entry * temp = new sym_tab_entry(function_name,result_type);
	int index = this->global_sym_tab.size();
	global_sym_tab.push_back(temp);
	return index;
}

variable * sym_tab :: search_variable_current(int active_function_index,string name,int level_of_declaration){
	variable * index = NULL;
	int level_local = -1;
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return NULL;
	for(int i=0;i<global_sym_tab[active_function_index]->local_variable_list.size();i++){
		if(global_sym_tab[active_function_index]->local_variable_list[i]->name == name && global_sym_tab[active_function_index]->local_variable_list[i]->level_of_declaration <= level_of_declaration){
			if(level_local <= global_sym_tab[active_function_index]->local_variable_list[i]->level_of_declaration){
				level_local = global_sym_tab[active_function_index]->local_variable_list[i]->level_of_declaration;
				index = global_sym_tab[active_function_index]->local_variable_list[i];
			}
		}
	}
	return index;
}

variable * sym_tab ::search_variable_global(int active_function_index,string name, int level_of_declaration){
		if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return NULL;
		variable * index = this->search_variable_current(active_function_index,name,level_of_declaration);
		if(index != NULL ) return index;
		else{
			int parameter_index = search_parameter_index(active_function_index,name);
			if(parameter_index == -1){
				return this->search_variable_current(0,name,level_of_declaration); // search global variables
			}
			vector<int> dimlist;
			dimlist.push_back(1);
			index = new variable("_param",global_sym_tab[active_function_index]->param_list[parameter_index]->type, global_sym_tab[active_function_index]->param_list[parameter_index]->eletype,dimlist,1);
			index->offset = parameter_index;
			return index;
		}

}

int sym_tab :: add_variable(int active_function_index,string name,int type,vector<int> dimlist,int level_of_declaration){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return -1;
	 variable * t = new variable(name,type,INT_TYPE,dimlist,level_of_declaration);
	 int index = global_sym_tab[active_function_index]->local_variable_list.size();
	 global_sym_tab[active_function_index]->local_variable_list.push_back(t);
	 return index;
}

bool sym_tab :: search_parameter(int active_function_index,string name){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return false;
	for(int i=0;i< global_sym_tab[active_function_index]->param_list.size();i++){
		if(global_sym_tab[active_function_index]->param_list[i]->name == name){
			return true;
		}
	}
	return false;
}
int sym_tab :: search_parameter_index(int active_function_index,string name){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return -1;
	for(int i=0;i< global_sym_tab[active_function_index]->param_list.size();i++){
		if(global_sym_tab[active_function_index]->param_list[i]->name == name){
			return i;
		}
	}
	return -1;
}
int sym_tab :: add_parameter(int active_function_index,string name,int type,int eletype){

		if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return -1;
		parameter * t = new parameter(name,type,eletype);
		int index = global_sym_tab[active_function_index]->param_list.size();
		global_sym_tab[active_function_index]->param_list.push_back(t);
		return index;
}

bool sym_tab :: patch_variable(int active_function_index,vector<int> var_index,int eletype){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return false;
	for(int i=0;i<var_index.size();i++){
		if(var_index[i] < 0 || var_index[i] >= global_sym_tab[active_function_index]->local_variable_list.size()) continue;
		global_sym_tab[active_function_index]->local_variable_list[var_index[i]]->eletype = eletype;
		variable * temp = global_sym_tab[active_function_index]->local_variable_list[var_index[i]];
		int curr_offset = global_offset.get_curr_offset();
		temp->offset = curr_offset;
		int addition = 0;
		if(temp->type == SIMPLE){
			if(temp->eletype == FLOAT_TYPE) addition = FLOAT_TYPE_SIZE;
			if(temp->eletype == INT_TYPE) addition = INT_TYPE_SIZE;
		}
		if(temp->type == ARRAY){
			int size = 1;
			for(int j=0;j<temp->dimlist.size();j++){
				size = size * temp->dimlist[j];
			}
			if(temp->eletype == FLOAT_TYPE) addition = FLOAT_TYPE_SIZE * size;
			if(temp->eletype == INT_TYPE) addition = INT_TYPE_SIZE * size;
		}
		global_offset.update_curr_offset(addition);
		total_user_variable.user_variable.push_back(temp->name +"_"+to_string(temp->offset)+" "+to_string(addition));
	}
	return true;
}
bool sym_tab :: clear_var_list(int active_function_index,int level){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return false;
	vector<int>indexes_to_delete;
	int i=0;
	while(i < global_sym_tab[active_function_index]->local_variable_list.size()){
		if(global_sym_tab[active_function_index]->local_variable_list[i]->level_of_declaration == level){
			global_sym_tab[active_function_index]->local_variable_list.erase(global_sym_tab[active_function_index]->local_variable_list.begin() +i);
			continue;
		}
		i++;
	}
	//cout<< endl<<endl
	return true;
}
bool sym_tab :: patch_function_parameter_no(int active_function_index,int no_of_parameter){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return false;
	this->global_sym_tab[active_function_index]->no_of_parameter = no_of_parameter;
}
/* this function also prints error msgs*/
int sym_tab :: check_param_compatible(int call_function_index,vector<int> type_list){
	if(call_function_index < 0 || call_function_index >= this->global_sym_tab.size()) return ERROR_TYPE;

	if(this->global_sym_tab[call_function_index]->param_list.size() != type_list.size()){
			yyerror("No of arguments passed does not match defination of "+this->global_sym_tab[call_function_index]->function_name);
			return ERROR_TYPE;
	}
	else{
		bool flag = true;
		for(int i=0;i<type_list.size();i++){

			if(type_list[i]!=FLOAT_ADDRESS_TYPE && type_list[i]!=INT_ADDRESS_TYPE){
				if(type_list[i] != this->global_sym_tab[call_function_index]->param_list[i]->eletype){
					yyerror( to_string(i+1)+to_string(type_list[i]) +" argument passed does not match defination of "+this->global_sym_tab[call_function_index]->function_name);
					flag = false;
				}
			}
			else{
				if(type_list[i] == FLOAT_ADDRESS_TYPE){
				if(!(type_list[i]==FLOAT_ADDRESS_TYPE && this->global_sym_tab[call_function_index]->param_list[i]->eletype == FLOAT_TYPE && this->global_sym_tab[call_function_index]->param_list[i]->type == ARRAY)){
					yyerror( to_string(i+1)+" argument passed does not match defination of "+this->global_sym_tab[call_function_index]->function_name);
					flag = false;
				}
			}
			else{
				if(!(type_list[i]==INT_ADDRESS_TYPE && this->global_sym_tab[call_function_index]->param_list[i]->eletype == INT_TYPE && this->global_sym_tab[call_function_index]->param_list[i]->type == ARRAY)){
					yyerror( to_string(i+1)+" argument passed does not match defination of "+this->global_sym_tab[call_function_index]->function_name);
					flag = false;
				}
			}
		}
		}
		if(flag == false){
			return ERROR_TYPE;
		}
		else{
			return 	this->global_sym_tab[call_function_index]->result_type;
		}
	}
}

string sym_tab :: genarate_function_call(int call_function_index,elist_func_call_ * temp){
	if(call_function_index < 0 || call_function_index >= this->global_sym_tab.size()) return "ERR";
	for(int i=0;i<temp->type_list.size();i++){
		if(this->global_sym_tab[call_function_index]->param_list[i]->type == SIMPLE){
				intermediate_output.gen_special("param",temp->name_list[i],"---","---");
		}
		else{
			intermediate_output.gen_special("refparam",temp->name_list[i],"---","---");
		}
	}
	if(this->global_sym_tab[call_function_index]->result_type != VOID_TYPE){
		string t = to_string(global_temp);
		global_temp++;

		string temporary_name;
		if(this->global_sym_tab[call_function_index]->result_type == INT_TYPE){
			temporary_name = "_T";
		}
		else{
			temporary_name = "_F";
		}
		temporary_name = temporary_name + t;
		total_temp_data.temp_variable.push_back(temporary_name);
		intermediate_output.gen_special("refparam",temporary_name,"---","---");
		intermediate_output.gen_special("call",this->global_sym_tab[call_function_index]->function_name,to_string(temp->type_list.size()+1),"---");
		return temporary_name;
	}
	else{
		intermediate_output.gen_special("call",this->global_sym_tab[call_function_index]->function_name,to_string(temp->type_list.size()),"---");
		return "ERR";
	}
}

void code_output :: gen(string s){
	this->intermediate_code.push_back(s);
	this->global_index = this->intermediate_code.size();
	return;
}

int code_output :: get_next(){
	return this->global_index;
}
void code_output :: print(){
	int count = 0;
	for(int i=0;i<this->intermediate_code.size();i++){
		if(this->intermediate_code[i] == "" ) continue;
		cout<<(count+1)<<" "<<this->intermediate_code[i]<<endl;
		count++;
	}
	cout<<endl<<"-----------------end------------------"<<endl;
}

void code_output :: gen_special(string op,string operand1,string operand2,string result){
	std::ostringstream out;
	out<< op << " "<<operand1<<" "<<operand2 <<" "<<result;
	string s = out.str();
	this->gen(s);
}
void 	code_output :: back_patch(string s,int index){
	if(index < 0 || index >= this->intermediate_code.size() ) {
		return;
	}
	this->intermediate_code[index] = this->intermediate_code[index] + s ;
}
void code_output :: back_patch_special(string op,string op1,string op2,string result,int index){
	vector<string>v(4,"");
	string s = this->intermediate_code[index];
	int d = s.length();
	int i = 0;
	int count = 0;
	string temp = "";
	while(i<d){
		if(s[i] == ' '){
			if(i>0){
				if(s[i] == ' ' && s[i-1]!= ' '){
					if(count<=3){
						v[count] = temp;
					}
					count++;

					temp = "";
				}
			}
		}
		else{
			temp+=s[i];
		}
		i++;
		if(i == d && count<=3){
			v[count] = temp;
		}
	}

	if(op!="_prev"){
		v[0] = op;
	}
	if(op1!="_prev"){
		v[1] = op1;
	}
	if(op2!="_prev"){
		v[2] = op2;
	}
	if(result!="_prev"){
		v[3] = result;
	}
	string final = v[0] + " " + v[1] + " " + v[2] + " " + v[3];
	this->intermediate_code[index] = final;

}
void code_output :: put_tag(int index,string tag){
	if(index < 0 || index >= this->intermediate_code.size() ) {
		return;
	}
	this->intermediate_code[index] = tag;
}
void code_output :: patch_tag(string tag,vector<int> indexes,int index){
		this->put_tag(index,tag);
		for(int i=0;i<indexes.size();i++){
			if(indexes[i]<0 || indexes[i] >= this->intermediate_code.size()) continue;
			this->back_patch_special("_prev","_prev","_prev",tag,indexes[i]);
		}
}

void code_output :: patch_switch_con(string tag,vector<int> indexes){
	if(indexes.empty()) return;
	for(int i=0;i<indexes.size();i++){
		if(indexes[i]<0 || indexes[i] >= this->intermediate_code.size()) continue;
		this->back_patch_special("_prev","_prev",tag,"_prev",indexes[i]);
	}
}
void code_output :: patch_tag_no_put(string tag,vector<int> indexes,int index){
	for(int i=0;i<indexes.size();i++){
		if(indexes[i]<0 || indexes[i] >= this->intermediate_code.size()) continue;
		this->back_patch_special("_prev","_prev","_prev",tag,indexes[i]);
	}
}
void code_output :: gen_at_pos(string tag,int index){
	if(index < 0 || index >= this->intermediate_code.size() ) {
		return;
	}
	this->intermediate_code[index] = tag;
}
void code_output ::  gen_relational_op(string op,string operand1,string operand2,string result){
	this->gen_special("=","1","---",result);
	string s2 = rel_tag.get_rel_tag();
	this->gen_special(op,operand1,operand2,s2);
	this->gen_special("=","0","---",result);
	this->gen(s2);
}
