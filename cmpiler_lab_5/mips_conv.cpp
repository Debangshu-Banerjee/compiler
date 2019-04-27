#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> lines;  //3AC code lines

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
  fin.open(filename);
  while(fin.good()){
    getline(fin,line);
    if(line != ""){
      lines.push_back(line);
    }
  }
  fin.close();
}

void generate_data_segment(){


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
  generate_data_segment();
  fstream file;
  int line;
  for(line = 0; line < lines.size(); line++){
    vector<string> linevec = split(lines[line]);  //split
    generate_each_instruction(linevec);
  }
}

int main(int argc, char** argv)
{
  readfile(argv[1]);  //input 3AC file
  mipsfile.open ("output.mips", ios::out | ios::trunc);
  generate();
  mipsfile.close();
  return 0;
}
