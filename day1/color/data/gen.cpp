#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define percent(x) (rand()%100<x)


using namespace std;

void unqPick(int *a,int l,int r){
	for (int i=l;i<=r;++i) a[i-l]=i;
	for (int k=0;k<7;++k) random_shuffle(a,a+(r-l+1));
}
void unqPick(int *a,int n){
	unqPick(a,1,n);
}
ull randULL(){return ((ull)rand()<<30)^((ull)rand()<<50)^rand();}
ll Rand(ll mod){return (unsigned long long)rand()*rand()*rand()*rand()%mod;}
const int base=2;
int Rand_log(int ub){return pow(base,1.0*rand()/RAND_MAX*(log(ub)/log(base)));}

void gen(int T,int maxn,int index){
	if (index) T-=rand()%int(sqrt(T));
	printf("%d\n",T);
	for (int t=0;t<T;++t){
		int n=maxn;
		if (index) n-=rand()%2*rand()%int(sqrt(n));
		for (int i=0;i<n;++i){
			putchar('a'+rand()%26);
		}
		puts("");
	}
}
int main(int argc,char **argv){
	unsigned int seed=argc>1?atoi(argv[1]):time(0);
	srand(seed);
	freopen("seed.txt","w",stdout);
	printf("%u\n",seed);
	fclose(stdout);
	const int start=1;
	const int cas=2;
	for (int t=0;t<cas;++t){
		char fname[23];
		int index=t+start;
		sprintf(fname,"%d.in",index);
		freopen(fname,"w",stdout);
		gen(500,600,t);
		fclose(stdout);
	}
	return 0;
}
