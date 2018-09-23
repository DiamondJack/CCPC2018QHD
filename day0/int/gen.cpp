#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	srand((unsigned int)time(0));
	const ll mx=2148473647LL;
	const ll inf=2147483647;
	const int maxn=1e4;
	char fname[23];
	int testcase=50;
	for (int T=1;T<=testcase;++T){
		sprintf(fname,"data/%d.in",T);
		freopen(fname,"w",stdout);
		int n;
		if (1){
			ll mn=0;
			ll range=inf;
			if (T>22) range=rand()%100;
			if (T<=10){
				if (T==1) mn=mx-inf;
				else if (T==2) mn=-mx;
				else if (T&1) mn=rand()%(mx-inf)+1;
				else mn=-mx+rand()%(mx-inf);
			}
			else if (T&1) mn=-rand();
			else mn=-rand()%100;
			n=maxn-rand()%2*rand()%233;
			printf("%d\n",n);
			for (int i=1;i<=n;++i){
				ll now=mn+1LL*rand()*rand()%(1LL+range);
				if (range==inf&&rand()%1000==0) now=mn+rand()%2*rand()%(mx-inf);
				if (range==inf&&rand()%1000==0) now=mn+inf-rand()%2*rand()%(mx-inf);
				printf("%lld",now);
				if (i==n) puts("");
				else putchar(' ');
			}
		}
	}
	return 0;
}
