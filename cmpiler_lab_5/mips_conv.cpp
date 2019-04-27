#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> lines;  //3AC code lines

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
  fin.open(filename);
  while(fin.good()){
    getline(fin,line);
    if(line != ""){
      lines.push_back(line);
    }
  }
  fin.close();
  //cout<<lines.size()<<endl;
}

void generate_data_segment(){


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
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_int_count();mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_int_count();mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_int_count();mipsfile<<"add "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_float_count();mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_float_count();mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_float_count();mipsfile<<"add "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }

  }
  if(linevec[1]=="-")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_int_count();mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_int_count();mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_int_count();mipsfile<<"sub "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_float_count();mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_float_count();mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_float_count();mipsfile<<"sub "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
  }
  if(linevec[1]=="*")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_int_count();mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_int_count();mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_int_count();mipsfile<<"mult "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_float_count();mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_float_count();mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_float_count();mipsfile<<"mult "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
      mipsfile<<"sw $f"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
  }
  if(linevec[1]=="/")
  {
    if(linevec[2][0]=='T'&&linevec[3][0]=='T'&&linevec[4][0]=='T')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_int_count();mipsfile<<"lw $t"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_int_count();mipsfile<<"lw $t"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_int_count();mipsfile<<"div "<<"$t"<<sixth<<" "<<"$t"<<frth<<" "<<"$t"<<fifth<<endl;
      mipsfile<<"sw $t"<<sixth<<" 0($t"<<thrd<<")"<<endl;
    }
    else if(linevec[2][0]=='F'&&linevec[3][0]=='F'&&linevec[4][0]=='F')
    {
      int first=gen_int_count();mipsfile<<"la $t"<<first<<" "<<linevec[2]<<endl;
      int secnd=gen_int_count();mipsfile<<"la $t"<<secnd<<" "<<linevec[3]<<endl;
      int thrd=gen_int_count();mipsfile<<"la $t"<<thrd<<" "<<linevec[4]<<endl;
      int frth=gen_float_count();mipsfile<<"lw $f"<<frth<<" "<<"0($t"<<first<<")"<<endl;
      int fifth=gen_float_count();mipsfile<<"lw $f"<<fifth<<" "<<"0($t"<<secnd<<")"<<endl;
      int sixth=gen_float_count();mipsfile<<"div "<<"$f"<<sixth<<" "<<"$f"<<frth<<" "<<"$f"<<fifth<<endl;
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
  generate_data_segment();
  fstream file;
  int line;
  for(line = 0; line < lines.size(); line++){
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
  readfile(argv[1]);  //input 3AC file
  mipsfile.open ("output.mips", ios::out | ios::trunc);
  generate();
  mipsfile.close();
  return 0;
}
