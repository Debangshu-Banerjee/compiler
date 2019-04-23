#include<bits/stdc++.h>
#include "structure_def.h"

using namespace std;

gloabal_offset_structure global_offset;

int get_compatible_type_non_bool(int type1 ,int type2){
	if(type1 == ERROR_TYPE || type2 == ERROR_TYPE){
		return ERROR_TYPE;
	}
	if(type1 == BOOL_TYPE || type2 == BOOL_TYPE){
		return ERROR_TYPE;
	}
	if(type1 == INT_TYPE && type2 == INT_TYPE){
		return INT_TYPE;
	}
	if(type1 == FLOAT_TYPE && type2 == FLOAT_TYPE){
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
			return this->search_variable_current(0,name,level_of_declaration); // search global variables
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
	}
	return true;
}

bool sym_tab :: patch_function_parameter_no(int active_function_index,int no_of_parameter){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return false;
	this->global_sym_tab[active_function_index]->no_of_parameter = no_of_parameter;
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
	for(int i=0;i<this->intermediate_code.size();i++){
		cout<<this->intermediate_code[i]<<endl;
	}
	cout<<endl<<"-----------------end------------------"<<endl;
}
