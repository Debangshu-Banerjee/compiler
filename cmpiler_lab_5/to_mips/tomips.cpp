#include <bits/stdc++.h>
#include "ASMGenerator.h"

using namespace std;


int main()
{

  ASMGenerator asmGenerator;
  asmGenerator.setTACFileName("test.tac");
  asmGenerator.setASMFileName("test.s");
  asmGenerator.build();
}
