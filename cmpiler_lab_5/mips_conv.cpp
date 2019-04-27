#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> lines;  //3AC code lines

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

void generate()
{
  fstream file;
  //file.open ("output.mips", ios::out | ios::in );
  //file << text << endl;
  int line;
  for(line = 0; line < lines.size(); line++){
    vector<std::string> linevec = split(lines[line]);  //split
  }
}

int main(int argc, char** argv)
{
  readfile(argv[1]);
  generate();
  return 0;
}
