#ifndef STRUCT_H
#define STRUCT_H
#include<bits/stdc++.h>
using namespace std;

int temp_count = 0; 

class variable{
public :
	string name;
	int type;
	int eletype;
	vector<int> dimlist;
	int level_of_declaration;
	variable(string name,int type,int eletype,vector<int> dimlist,int level_of_declaration){
		this->name = name;
		this->type = type;
		this->eletype = eletype;
		this->dimlist = dimlist;
		this->level_of_declaration = level_of_declaration; 
	}
};
class parameter{
public :
	string name;
	int type;
	int eletype;
	parameter(string name,int type,int eletype){
		this->name = name;
		this->type = type;
		this->eletype = eletype;
	}
};
class sym_tab_entry{
public:
	string function_name;
	int result_type;
	vector<parameter *> param_list;
	vector<variable *> local_variable_list;
	int no_of_parameter;
	sym_tab_entry(string function_name,int result_type){
		this->function_name = function_name;
		this->result_type = result_type;
	}
};

class sym_tab{
public:
	vector<sym_tab_entry *> global_sym_tab;
	bool search_func(string function_name);
	int add_function(string function_name,int result_type);
	bool search_variable(int active_function_index,string name,int level_of_declaration);
	int add_variable(int active_function_index,string name,int type,vector<int> dimlist,int level_of_declaration);
	bool search_parameter(int active_function_index,string name);
	int add_parameter(int active_function_index,string name,int type,int eletype);
	bool patch_variable(int active_function_index,int var_index,int eletype);
};

class result_{
public:
	int result_type;
	result_(int type){
		this->result_type = type;
	}
};

class id_{
public :
	string name;
	id_(string name){
		this->name = name;
	}
};

class statement_list_{
public:
	vector<int> next;
	int can_appear_in_global; // 0 variables both global and local 1 for local only 2 global only
	bool error ; 			// 0 --> variables 1 --> if/while/for 2 --> functions
};


class parameter_list_{
public:
	int no_of_parameter; 
	parameter_list_(int no_of_parameter){
		this->no_of_parameter = no_of_parameter;
	}
};

class conditional_expression_{
public:	
	int type;
	string temporary_name;
	conditional_expression_(){
		this->type = type;
		temp_count ++;
		string t = to_string(temp_count);
		this->temporary_name = "T";
		temporary_name = temporary_name + t;
	}

};

class elelist_{
public:	
	int type;
	int no_of_expressions;
	vector<int> elements;
};

class type_{
public:	
	int type;
	type_(int type){
		this->type = type;
	}
};

class var_list_{
public:
	vector<int> list_of_indexes;
};

class ifexp_{
public:
	vector<int> false_list; 
	ifexp_(int index){
		this->false_list.push_back(index);
	}
};

class loopexp_{
public:
	vector<int> false_list;
	int jump_back_address;
	loopexp_(int index,int jump_back_address){
		this->false_list.push_back(index);
		this->jump_back_address = jump_back_address;
	}
};

class M_{
public:
	int position;
	M_(int position){
		this->position = position;
	}
};

class N_{
public:
	vector<int> next;
	N_(int index){
		this->next.push_back(index);
	}
};

class id_arr_{
public:
	int index_in_sym_tab;
	id_arr_(int index_in_sym_tab){
		this->index_in_sym_tab = index_in_sym_tab;
	}
};


#endif 
