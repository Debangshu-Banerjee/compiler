#include<bits/stdc++.h>
#include "structure_def.h"

using namespace std;

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
		variable * index = this->search_variable_current(active_function_index,name,level_of_declaration);
		if(index != NULL ) return index;
		else{
			return this->search_variable_current(0,name,level_of_declaration); // search global variables
		}	
}

int sym_tab :: add_variable(int active_function_index,string name,int type,vector<int> dimlist,int level_of_declaration){
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
		parameter * t = new parameter(name,type,eletype);
		int index = global_sym_tab[active_function_index]->param_list.size();
		global_sym_tab[active_function_index]->param_list.push_back(t);
		return index;  	
}

bool sym_tab :: patch_variable(int active_function_index,vector<int> var_index,int eletype){
	if( active_function_index < 0 || active_function_index >= global_sym_tab.size()) return false;
	for(int i=0;i<var_index.size();i++){
		global_sym_tab[active_function_index]->local_variable_list[var_index[i]]->eletype = eletype;
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
