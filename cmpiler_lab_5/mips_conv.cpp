#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> lines;  //3AC code lines
vector<string> data_items;
vector<string> data_size;
ofstream mipsfile;

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
        linevec.push_back(word);
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
  if(linevec.size()<=4) return;
  if(linevec[1].empty() || linevec[2].empty() || linevec[3].empty() || linevec[4].empty()){
      return;
  }
  if(linevec[1]=="+")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      genarate_micro_op_int("add",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      genarate_micro_op_float("add.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("add.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1]=="-")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      genarate_micro_op_int("sub",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      genarate_micro_op_float("sub.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("sub.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1]=="*")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      genarate_micro_op_int("mul",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      genarate_micro_op_float("mul.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("mul.s",linevec[2],linevec[3],linevec[4]);
    }
  }
  if(linevec[1]=="/")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
        genarate_micro_op_int_div("div",linevec[2],linevec[3],linevec[4]);
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      genarate_micro_op_float("div.s",linevec[2],linevec[3],linevec[4]);
    }
    else{
      genarate_micro_op_float_int("div.s",linevec[2],linevec[3],linevec[4]);
    }
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
