#ifndef STRUCT_H
#define STRUCT_H
#define INT_TYPE -1
#define FLOAT_TYPE -2
#define BOOL_TYPE -3
#define VOID_TYPE -5
#define ERROR_TYPE -4
#define FLOAT_ADDRESS_TYPE -5
#define INT_ADDRESS_TYPE -6
#define SIMPLE -1
#define ARRAY -2
#define PARAM -1
#define VAR -2
#define INT_TYPE_SIZE 4
#define FLOAT_TYPE_SIZE 8

#include<bits/stdc++.h>
using namespace std;
extern int global_temp;
int get_compatible_type_non_bool(int type1 ,int type2);
int get_compatible_type_bool_only(int type1 ,int type2);
int get_compatible_type_rel_op(int type1 ,int type2);

class gloabal_offset_structure{
public:
	int curr_offset;
	gloabal_offset_structure(){
		curr_offset = 0;
	}
	int get_curr_offset(){
		return curr_offset;
	}
	void update_curr_offset(int addition){
		this->curr_offset = this->curr_offset + addition;
	}
};
class user_define_data{
public:
	vector<string> user_variable;
	user_define_data(){
		this->user_variable.clear();
	}
	void print(){
		cout<< endl<<endl<<"# user defined variable"<<endl;
		for(int i=0;i<this->user_variable.size();i++){
			cout<<"# "<<this->user_variable[i]<<endl;
		}
	}
};

class loop_tag_genarator{
public:
	int tag_no;
	loop_tag_genarator(){
			tag_no =0;
	}
	string get_loop_tag(){
		string t = "LOOP";
		t = t + to_string(this->tag_no)+ ":";
		tag_no++;
		return t;
	}
};
class rel_tag_genarator{
public:
	int tag_no;
	rel_tag_genarator(){
			tag_no =0;
	}
	string get_rel_tag(){
		string t = "REL";
		t = t + to_string(this->tag_no)+ ":";
		tag_no++;
		return t;
	}
};
class func_end_tag_genarator{
public:
	int tag_no;
	func_end_tag_genarator(){
			tag_no =0;
	}
	string get_func_end_tag(){
		string t = "func_end";
		t = t + to_string(this->tag_no)+ ":";
		tag_no++;
		return t;
	}
};
class conditional_tag_genator{
public:
	int tag_no;
 		conditional_tag_genator(){
		 	tag_no =0;
 		}
		string get_conditional_tag(){
			 string t = "COND";
			 t = t + to_string(this->tag_no) + ":";
			 tag_no++;
			 return t;
		}
};

class variable{
public :
	string name;
	int type;
	int eletype;
	vector<int> dimlist;
	int level_of_declaration;
	int offset;
	variable(string name,int type,int eletype,vector<int> dimlist,int level_of_declaration){
		this->name = name;
		this->type = type;
		this->eletype = eletype;
		this->dimlist = dimlist;
		this->level_of_declaration = level_of_declaration;
		this->offset = -1;
	}
};
class elist_func_call_{
public:
		vector<int> type_list;
		vector<string> name_list;
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
		this->no_of_parameter = 0;
	}
};
class code_output{
public:
	vector<string> intermediate_code;
	int global_index;
	code_output(){
		this->global_index =0;
		this->intermediate_code.clear();
	}
	void gen(string s);
	int get_next();
	void print();
	void put_tag(int index,string tag);
	void back_patch(string s,int index);
	void back_patch_special(string op,string op1,string op2,string result,int index);
	void gen_special(string op,string operand1,string operand2,string result);
	void patch_tag(string tag,vector<int> indexes,int index);
  void patch_tag_no_put(string tag,vector<int> indexes,int index);
	void patch_switch_con(string tag,vector<int> indexes);
	void gen_at_pos(string tag,int index);
	void gen_relational_op(string op,string operand1,string operand2,string result);
};

class sym_tab{
public:
	vector<sym_tab_entry *> global_sym_tab;
	sym_tab(){
		sym_tab_entry * temp = new sym_tab_entry("_global_",INT_TYPE);
		global_sym_tab.push_back(temp);
	}
	int search_func(string function_name);
	int add_function(string function_name,int result_type);
	variable * search_variable_current(int active_function_index,string name,int level_of_declaration);
	variable * search_variable_global(int active_function_index,string name, int level_of_declaration);
	int add_variable(int active_function_index,string name,int type,vector<int> dimlist,int level_of_declaration);
	bool search_parameter(int active_function_index,string name);
	int search_parameter_index(int active_function_index,string name);
	int add_parameter(int active_function_index,string name,int type,int eletype);
	bool patch_variable(int active_function_index,vector<int> var_index,int eletype);
	bool patch_function_parameter_no(int active_function_index,int no_of_parameter);
	int check_param_compatible(int call_function_index,vector<int> type_list);
	string genarate_function_call(int call_function_index,elist_func_call_ * temp);
	bool clear_var_list(int active_function_index,int level);
	void display();
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
	vector<int> break_list;
	vector<int> continue_list;
	int can_appear_in_global; // 0 variables both global and local 1 for local only 2 global only
 	bool error;
	bool seen_loop;													// 0 --> variables 1 --> if/while/for 2 --> functions
	 statement_list_(int can_appear_in_global){
		 this->can_appear_in_global = can_appear_in_global;
		 this->error = false;
		 this->seen_loop = false;
	 }
};

class assignment_statement_{
public:
	int type;
	string temporary_var_name;
	int can_appear_in_global;
	assignment_statement_(int type, string temporary_var_name){
		this-> type = type;
		this->temporary_var_name = temporary_var_name;
		this->can_appear_in_global = 0;
	}

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
	conditional_expression_(int type){

			this->type = type;
			if(type != ERROR_TYPE){
					string t = to_string(global_temp);
					global_temp++;
					if(type == FLOAT_TYPE){
						this->temporary_name = "F" + t;
					}
					else{
						this->temporary_name = "T" + t;
					}
			}
			else{
				this->temporary_name = "ERR";
			}
	}
	conditional_expression_(int type,string temporary_name){

			this->type = type;
			if(type != ERROR_TYPE){
					this->temporary_name = temporary_name;
			}
			else{
				this->temporary_name = "ERR";
			}
	}
};
class unary_expression_{
public:
	int type;
	string temporary_name;
	variable * var;
	unary_expression_(int type){

			this->type = type;
			if(type != ERROR_TYPE){
					string t = to_string(global_temp);
					global_temp++;
					if(type == FLOAT_TYPE){
						this->temporary_name = "F" + t;
					}
					else{
						this->temporary_name = "T" + t;
					}
					this->var = NULL;
			}
			else{
				this->temporary_name = "ERR";
				this->var = NULL;
			}
	}

	unary_expression_(int type,string temporary_name){

			this->type = type;
			if(type != ERROR_TYPE){
					this->temporary_name = temporary_name;
					this->var = NULL;
			}
			else{
				this->temporary_name = "ERR";
				this->var = NULL;
			}
	}
};

class elist_{
public:
	int type;
	vector<string> name_list;
};

class case_name_{
public:
	int first_address;
	case_name_(int first_address){
		this->first_address = first_address;
	}
};

class case_list_{
public:
	vector<int> next;
	vector<int> break_list;
	vector<int> continue_list;
	int first_address;
	int second_address;
	vector<int> false_list;
	case_list_(int first_address,int second_address){
		this->first_address = first_address;
		this->second_address = second_address;
	}
};

class new_num_list_{
public:
	vector<int> num_list;
};

class type_{
public:
	int type;
	type_(int type){
		this->type = type;
	}
};

class varlist_{
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

class id_arr_declare_{
public:
	int index_in_sym_tab;
	id_arr_declare_(int index_in_sym_tab){
		this->index_in_sym_tab = index_in_sym_tab;
	}
};
class id_arr_{
public:
	  variable * var;
		string offset_temp;
	  id_arr_(variable * var1,string offset_temp){
	  		this->var = var1;
				if(var1 == NULL){
					this->offset_temp = "ERR";
				}
				else{
					if(var1->type == SIMPLE){
						this->offset_temp = "NONE";
					}
					else{
						this->offset_temp = offset_temp;
					}
				}
	  }
};
class unit_declaration_{
public:
	int type;
	unit_declaration_(int type){
		this->type = type;
	}
};

#endif
