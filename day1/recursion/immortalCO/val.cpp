#include "../../../testlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
	registerValidation(argc, argv);
	int T = inf.readInt(1, 1000, "T");
	inf.readEoln();
	while(T--) {
		inf.readLong(0, 1000000000000000000ll, "u");
		inf.readSpace();
		inf.readLong(0, 1000000000000000000ll, "d");
		inf.readEoln();
	}
	inf.readEof();
}