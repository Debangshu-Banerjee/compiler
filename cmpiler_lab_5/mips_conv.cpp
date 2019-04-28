#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> lines;  //3AC code lines
vector<string> data_items;
vector<string> data_size;
ofstream mipsfile;

vector<string> parameter_mips;

void handle_param(vector<string> linevec)
{
  string param_name=linevec[2];
  parameter_mips.push_back(param_name);
  // mipsfile<<"sw "<<param_name<<"0($sp)"<<endl;
  // mipsfile<<"addiu $sp $sp - 4"<<endl;
}
void handle_refparam(vector<string> linevec)
{
  return;
}
void handle_call(vector<string> linevec)
{
  string func_name=linevec[2];
  string no_params=linevec[3];
  int no_param=0;
  stringstream temp(no_params);
  temp>>no_param;
  //cout<<no_param<<endl;
  mipsfile<<"sw $fp 0($sp)"<<endl;
  mipsfile<<"addiu $sp $sp - 4"<<endl;

  for(auto &p:parameter_mips)  //all parameters for this function
  {
    mipsfile<<"sw "<<p<<"0($sp)"<<endl;
    mipsfile<<"addiu $sp $sp - 4"<<endl;
  }

  mipsfile<<"jal "<<func_name<<":"<<endl;
  parameter_mips.clear();
}

void genarate_micro_op_int(string op,string opr1,string opr2,string result){
  int first=0;mipsfile<<"la $t"<<first<<", "<<opr1<<endl;
  int secnd=1;mipsfile<<"la $t"<<secnd<<", "<<opr2<<endl;
  int thrd=2;mipsfile<<"la $t"<<thrd<<", "<<result<<endl;
  int frth=3;mipsfile<<"lw $t"<<frth<<", "<<"0($t"<<first<<")"<<endl;
  int fifth=4;mipsfile<<"lw $t"<<fifth<<", "<<"0($t"<<secnd<<")"<<endl;
  int sixth=5;mipsfile<<op<<" $t"<<sixth<<", "<<"$t"<<frth<<", "<<"$t"<<fifth<<endl;
  mipsfile<<"sw $t"<<sixth<<", 0($t"<<thrd<<")"<<endl;
}
void genarate_micro_op_int_div(string op,string opr1,string opr2,string result){
  int first=0;mipsfile<<"la $t"<<first<<", "<<opr1<<endl;
  int secnd=1;mipsfile<<"la $t"<<secnd<<", "<<opr2<<endl;
  int thrd=2;mipsfile<<"la $t"<<thrd<<", "<<result<<endl;
  int frth=3;mipsfile<<"lw $t"<<frth<<", "<<"0($t"<<first<<")"<<endl;
  int fifth=4;mipsfile<<"lw $t"<<fifth<<", "<<"0($t"<<secnd<<")"<<endl;
  int sixth=5;mipsfile<<op<<" $t"<<frth<<", "<<"$t"<<fifth<<endl;
  mipsfile<<"mflo "<<"$t5 "<<endl;
  mipsfile<<"sw $t"<<sixth<<", 0($t"<<thrd<<")"<<endl;
}
void genarate_micro_op_float(string op,string opr1,string opr2,string result){
  int first=0;mipsfile<<"la $t"<<first<<", "<<opr1<<endl;
  int secnd=1;mipsfile<<"la $t"<<secnd<<", "<<opr2<<endl;
  int thrd=2;mipsfile<<"la $t"<<thrd<<", "<<result<<endl;
  int frth=3;mipsfile<<"l.s $f"<<frth<<", "<<"0($t"<<first<<")"<<endl;
  int fifth=4;mipsfile<<"l.s $f"<<fifth<<", "<<"0($t"<<secnd<<")"<<endl;
  int sixth=5;mipsfile<<op<<" $f"<<sixth<<", "<<"$f"<<frth<<", "<<"$f"<<fifth<<endl;
  mipsfile<<"s.s $f"<<sixth<<", 0($t"<<thrd<<")"<<endl;

}
void genarate_micro_op_float_int(string op,string opr1,string opr2,string result){
  int first=0;mipsfile<<"la $t"<<first<<", "<<opr1<<endl;
  int secnd=1;mipsfile<<"la $t"<<secnd<<", "<<opr2<<endl;
  int thrd=2;mipsfile<<"la $t"<<thrd<<", "<<result<<endl;
  int frth=3;mipsfile<<"l.s $f"<<frth<<", "<<"0($t"<<first<<")"<<endl;
  int fifth=4;mipsfile<<"l.s $f"<<fifth<<", "<<"0($t"<<secnd<<")"<<endl;
  mipsfile<<"cvt.s.w $f"<<frth<<", "<<"$f"<<frth<<endl;
  mipsfile<<"cvt.s.w $f"<<fifth<<", "<<"$f"<<fifth<<endl;
  int sixth=5;mipsfile<<op<<" $f"<<sixth<<", "<<"$f"<<frth<<", "<<"$f"<<fifth<<endl;
  mipsfile<<"s.s $f"<<sixth<<", 0($t"<<thrd<<")"<<endl;
}
void handle_num_assignment(vector<string> linevec){
  if(linevec[4][0]!= '_'){
    cout<<"ERROR : problem in intermediate\n";
    exit(0);
  }
  if(linevec[4][1]== 'F'){
    mipsfile<<"la $t0, "<<linevec[4]<<endl;
    mipsfile<<"li.s $f0, "<<linevec[2]<<endl;
    mipsfile<<"s.s $f0, "<<"0($t0)"<<endl;
  }
  if(linevec[4][1] == 'T'){
    mipsfile<<"la $t0, "<<linevec[4]<<endl;
    mipsfile<<"li $t1, "<<linevec[2]<<endl;
    mipsfile<<"sw $t1, "<<"0($t0)"<<endl;
  }
}
void handle_id_first_assignment(vector<string> linevec){
  if(linevec[4][0]!= '_'){
    cout<<"ERROR : problem in intermediate\n";
    exit(0);
  }
  if(linevec[4][1]== 'F'){
    mipsfile<<"la $t0, "<<linevec[2]<<endl;
    mipsfile<<"la $t1, "<<linevec[4]<<endl;
    mipsfile<<"l.s $f0, "<<"0($t0)"<<endl;
    mipsfile<<"s.s $f0, "<<"0($t1)"<<endl;
  }
  if(linevec[4][1]== 'T'){
    mipsfile<<"la $t0, "<<linevec[2]<<endl;
    mipsfile<<"la $t1, "<<linevec[4]<<endl;
    mipsfile<<"lw $t2, "<<"0($t0)"<<endl;
    mipsfile<<"sw $t2, "<<"0($t1)"<<endl;
  }
}
void handle_id_second_assignment(vector<string> linevec){
  if(linevec[2][0]!= '_'){
    cout<<"ERROR : problem in intermediate\n";
    exit(0);
  }
  if(linevec[2][1]== 'F'){
    mipsfile<<"la $t0, "<<linevec[2]<<endl;
    mipsfile<<"la $t1, "<<linevec[4]<<endl;
    mipsfile<<"l.s $f0, "<<"0($t0)"<<endl;
    mipsfile<<"s.s $f0, "<<"0($t1)"<<endl;
  }
  if(linevec[2][1]== 'T'){
    mipsfile<<"la $t0, "<<linevec[2]<<endl;
    mipsfile<<"la $t1, "<<linevec[4]<<endl;
    mipsfile<<"lw $t2, "<<"0($t0)"<<endl;
    mipsfile<<"sw $t2, "<<"0($t1)"<<endl;
  }
}
void handle_temp_to_temp_assignment(vector<string> linevec){
  if(linevec[2][0]!= '_' || linevec[4][0]!= '_' ){
    cout<<"ERROR : problem in intermediate\n";
    exit(0);
  }
  if(linevec[2][1]== 'F' && linevec[4][1]== 'F'){
    cout<<"ERROR : problem in intermediate\n";
    exit(0);
  }
  if(linevec[2][1]== 'T' && linevec[4][1]== 'T'){
    cout<<"ERROR : problem in intermediate\n";
    exit(0);
  }
  if(linevec[2][1]== 'T' && linevec[4][1] == 'F'){
    mipsfile<<"la $t0, "<<linevec[2]<<endl;
    mipsfile<<"la $t1, "<<linevec[4]<<endl;
    mipsfile<<"lw $t2, "<<"0($t0)"<<endl;
    mipsfile<<"mtc1 $t2, "<<"$f0"<<endl;
    mipsfile<<"cvt.s.w $f0, "<<"$f0"<<endl;
    mipsfile<<"s.s $f0, "<<"0$($t1)"<<endl;
  }
  if(linevec[2][1]!= 'F' && linevec[4][1]!= 'T'){
    mipsfile<<"la $t0, "<<linevec[2]<<endl;
    mipsfile<<"la $t1, "<<linevec[4]<<endl;
    mipsfile<<"l.s $f0, "<<"0($t0)"<<endl;
    mipsfile<<"cvt.w.s $f0, "<<"$f0"<<endl;
    mipsfile<<"s.s $f0, "<<"0$($t1)"<<endl;
  }
}

void handle_assignment(vector<string> linevec){
  if(linevec.size() == 2){      // not working as there is problem in tokenising
    if(linevec[1].empty()) return;
    if(linevec[1][linevec.size()-1] == ':' ){
      mipsfile<< linevec[1] << endl;
    }
  }
  if(linevec.size()<=4) return;
  if(linevec[1].empty() || linevec[2].empty() || linevec[3].empty() || linevec[4].empty()){
      return;
  }
  if(isdigit(linevec[2][0])){
    handle_num_assignment(linevec);
  }
  else{
    if(linevec[2][0]!='_'){
      handle_id_first_assignment(linevec);
    }
    else{
      if(linevec[4][0]!='_'){
        handle_id_second_assignment(linevec);
      }
      else{
        handle_temp_to_temp_assignment(linevec);
      }
    }
  }
}

void handle_rel_op(vector<string> linevec){

}

vector<std::string> split(string line){
  // string tok;
  // stringstream ss(line);
  vector<std::string> linevec;
  // // while(getline(ss, tok,' ')) {
  // //     linevec.push_back(tok);
  // // }
  istringstream ss(line);
    do {
        string word;
        ss >> word;
    } while (ss);
  return linevec;
}

void readfile(string filename){
  std::ifstream fin;
  std::string line;
  fin.open(filename.c_str());
  while(fin.good()){
    getline(fin,line);
    if(line != ""){
      lines.push_back(line);
    }
  }
  fin.close();
}

void generate_data_segment(){
    mipsfile<<".data"<< endl;
    for(int i=0;i< data_items.size();i++){
        mipsfile<< data_items[i] <<":"<< " .space " <<data_size[i]<<endl; // needs attention fora array declaration
    }
}
int tokenise_data_segment(){
  for(int i=0;i<lines.size();i++){
    vector<string> tokens = split(lines[i]);
    if(tokens.empty()){
      continue;
    }
    if(tokens[0] != "#" && tokens[0] != "##" ) return i;
    if(tokens[0] == "##" ) continue;
    if(tokens.size() < 3) continue;
    else{
      data_items.push_back(tokens[1]);
      data_size.push_back(tokens[2]);
    }
  }
  return lines.size();
}


void generate_each_instruction(vector<string> linevec)
{
  //mipsfile << text << endl;
  if(linevec.size() == 2){
    cout<< linevec[1] <<endl;
    if(linevec[1].empty()) return;
    if(linevec[1][linevec[1].size()-1] == ':'){
      mipsfile<< linevec[1] << endl;
    }
  }
  if(linevec.size() == 4){
    /* handle arrary assignment */
  }
  if(linevec.size()<=4) return;
  if(linevec[1].empty() || linevec[2].empty() || linevec[3].empty() || linevec[4].empty()){
      return;
  }
  if(linevec[1]=="+")
  {
    if(linevec[2][1]=='T'&&linevec[3][1]=='T'&&linevec[4][1]=='T')
    {
      genarate_micro_op_int("add",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][1]=='F'&&linevec[3][1]=='F'&&linevec[4][1]=='F')
    {
      genarate_micro_op_float("add.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("add.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1]=="-")
  {
    if(linevec[2][1]=='T'&&linevec[3][1]=='T'&&linevec[4][1]=='T')
    {
      genarate_micro_op_int("sub",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][1]=='F'&&linevec[3][1]=='F'&&linevec[4][1]=='F')
    {
      genarate_micro_op_float("sub.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("sub.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1]=="*")
  {
    if(linevec[2][1]=='T'&&linevec[3][1]=='T'&&linevec[4][1]=='T')
    {
      genarate_micro_op_int("mul",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][1]=='F'&&linevec[3][1]=='F'&&linevec[4][1]=='F')
    {
      genarate_micro_op_float("mul.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("mul.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1]=="/")
  {
    if(linevec[2][1]=='T'&&linevec[3][1]=='T'&&linevec[4][1]=='T')
    {
        genarate_micro_op_int_div("div",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][1]=='F'&&linevec[3][1]=='F'&&linevec[4][1]=='F')
    {
      genarate_micro_op_float("div.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("div.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1] == "="){vector<string> parameter_mips;

void handle_param(vector<string> linevec)
{
  string param_name=linevec[2];
  parameter_mips.push_back(param_name);
  // mipsfile<<"sw "<<param_name<<"0($sp)"<<endl;
  // mipsfile<<"addiu $sp $sp - 4"<<endl;
}
void handle_refparam(vector<string> linevec)
{
  return;
}
void handle_call(vector<string> linevec)
{
  string func_name=linevec[2];
  string no_params=linevec[3];
  int no_param=0;
  stringstream temp(no_params);
  temp>>no_param;
  //cout<<no_param<<endl;
  mipsfile<<"sw $fp 0($sp)"<<endl;
  mipsfile<<"addiu $sp $sp - 4"<<endl;

  for(auto &p:parameter_mips)  //all parameters for this function
  {
    mipsfile<<"sw "<<p<<"0($sp)"<<endl;
    mipsfile<<"addiu $sp $sp - 4"<<endl;
  }

  mipsfile<<"jal "<<func_name<<":"<<endl;
  parameter_mips.clear();
}
      handle_assignment(linevec);
  }
  if(linevec[1] == "==" || linevec[1] == "!=" || linevec[1] == "<=" || linevec[1] == ">=" || linevec[1] == "<" || linevec[1] == ">"){
      handle_rel_op(linevec);
  }
  
  
  if(linevec[1]=="param")
  {
    handle_param(linevec);
  }
  if(linevec[1]=="refparam")
  {
    handle_refparam(linevec);
  }
  if(linevec[1]=="call")
  {
    handle_call(linevec);
  }

}

void generate()
{
  int index = tokenise_data_segment();
  generate_data_segment();
  fstream file;
  int line;
  mipsfile<<".text"<<endl;
  for(line = index; line < lines.size(); line++){
    vector<string> linevec = split(lines[line]);  //split
    generate_each_instruction(linevec);
  }

}

int main(int argc, char** argv)
{
  if(argc < 2){
    cout<<"give intermediate file name \n";
    exit(1);
  }
  readfile(argv[1]);  //input 3AC file
  mipsfile.open ("output.mips", ios::out | ios::trunc);
  generate();
  mipsfile.close();
  return 0;
}
