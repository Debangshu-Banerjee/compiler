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
  string tok;
  stringstream ss(line);
  vector<std::string> linevec;
  while(getline(ss, tok,' ')) {
      linevec.push_back(tok);
  }
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

void generate_each_instruction(vector<string> linevec)
{

  //mipsfile << text << endl;
  if(linevec[1]=="+")
  {

  }
  if(linevec[1]=="-")
  {

  }
  if(linevec[1]=="*")
  {

  }
  if(linevec[1]=="/")
  {

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

}

void generate()
{
  int index = tokenise_data_segment();
  generate_data_segment();
  fstream file;
  int line;
  /*for(line = index; line < lines.size(); line++){
    vector<string> linevec = split(lines[line]);  //split
    generate_each_instruction(linevec);
  }*/
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
