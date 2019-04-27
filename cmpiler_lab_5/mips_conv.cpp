#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> lines;  //3AC code lines
vector<string> data_items;
vector<string> data_size;
ofstream mipsfile;

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
    mipsfile <<".data"<< endl;
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
}

int gen_int_count()
{
  static int ct=-1;
  ct++;
  return ct;
}

int gen_float_count()
{
  static int ct=-1;
  ct++;
  return ct;
}

void generate_each_instruction(vector<string> linevec)
{
  //mipsfile << text << endl;
  if(linevec.size()<=1) return;
  if(linevec[1]=="+")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"add "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"add "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }

  }
  if(linevec[1]=="-")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"sub "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"sub "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
  }
  if(linevec[1]=="*")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"mult "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"mult "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
  }
  if(linevec[1]=="/")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"div "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=0;mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=1;mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=2;mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=3;mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=4;mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=5;mipsfile<<"div "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
  }
  if(linevec[1]=="=")
  {

  }
  if(linevec[1]=="==")
  {

  }
  if(linevec[1]==">")
  {

  }
  if(linevec[1]==">=")
  {

  }
  if(linevec[1]=="goto")
  {
    //cout<<"goto";
  }

}

void generate()
{
  int index=tokenise_data_segment();
  generate_data_segment();
  fstream file;
  int line;
  for(line = index; line < lines.size(); line++){
    vector<string> linevec = split(lines[line]);  //split
    //cout<<linevec.size()<<endl;
    generate_each_instruction(linevec);
  }
  // vector<string> ff=split(lines[0]);
  // for(int i=0;i<ff.size();++i)
  // {
  //   cout<<ff[i]<<endl;
  // }
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
