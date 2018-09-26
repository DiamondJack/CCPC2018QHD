#include "../../../testlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
	registerValidation(argc, argv);
	int N = inf.readInt(1, 1000, "N"); inf.readSpace();
	int M = inf.readInt(1, 10000, "M"); inf.readSpace();
	inf.readLong(1, 1000000000000000000ll, "F"); inf.readEoln();
	while(M--) {
		inf.readInt(1, N, "x"); inf.readSpace();
		inf.readInt(1, N, "y"); inf.readSpace();
		inf.readInt(0, 1e3, "f"); inf.readSpace();
		inf.readInt(0, 1e6, "c"); inf.readEoln();
	}
	inf.readEof();
}
