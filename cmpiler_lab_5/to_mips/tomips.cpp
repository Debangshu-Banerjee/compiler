#include <bits/stdc++.h>
#include "ASMGenerator.h"

using namespace std;


int main(int argc, char** argv)
{

  ASMGenerator asmGenerator;
  asmGenerator.setTACFileName(argv[1]);
  std::ofstream ofs;
  ofs.open("output.s", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  asmGenerator.setASMFileName("output.s");
  asmGenerator.build();
}
