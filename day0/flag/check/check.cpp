#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
  registerValidation();
  int sum(0);
  int T = inf.readInt(1, 50, "T");
  inf.readEoln();
//  ensuref(T == 1, "the input data must contain only one test case");

  for (int cas = 1; cas <= T; ++ cas) {
    int n = inf.readInt(1, 500000, "n");inf.readSpace();
	int m = inf.readInt(1, 500000, "m");inf.readSpace();
	int seed = inf.readInt(0, 100000006, "seed");
	
    if(cas < T) inf.readEoln();
    
    sum += n;
//    ensuref(sum <= 1000000, "sum of n must <= 1000000");
  }
  while (!inf.eof()) inf.readEoln();
  inf.readEof();
  
  return 0;
}
