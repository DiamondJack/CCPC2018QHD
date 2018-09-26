#include "../../../testlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
	registerValidation(argc, argv);
	int T = inf.readInt(1, 100);
	inf.readEoln();
	int C = 0;
	while(T--) {
		int N = inf.readInt(1, 100000);
		inf.readSpace();
		int M = inf.readInt(1, 50000);
		inf.readEoln();
		if(N > 1000 || M > 1000) ++C;
		for(int a = 1; a <= N; ++a) {
			int n = inf.readInt(0, 5);
			inf.readSpace();
			for(int i = 0; i <= n; ++i) {
				inf.readInt(0, 998244352);
				i == n ? void(inf.readEoln()) : void(inf.readSpace());
			}
		}
		for(int a = 1; a < N; ++a) {
			int x = inf.readInt(1, N);
			inf.readSpace();
			int y = inf.readInt(1, N);
			ensure(y == a + 1 && x < y);
			inf.readEoln();
		}
		while(M--) {
			inf.readInt(1, N);
			inf.readSpace();
			inf.readInt(1, N);
			inf.readSpace();
			inf.readInt(0, 998244352);
			inf.readEoln();
		}
	}
	ensure(C <= 3);
	inf.readEof();
}