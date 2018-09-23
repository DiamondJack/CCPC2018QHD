#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int MOD = int(1e9) + 7;

const int MAX_N = int(5e4) + 10;

void addIt(int&x,int c){
	x+=c;
	if(x>=MOD)x-=MOD;
}

int n,k;

int bigrand(){
	return rand()*(RAND_MAX + 1) + rand();
}

int main(int argc,char*argv[]) {
	ios::sync_with_stdio(false);

	n = atoi(argv[1]);
	k = atoi(argv[2]);
	int seed = atoi(argv[3]);
	srand(seed);
	
	cout<<n<<" "<<k<<endl;

	rep(i,0,n) cout<<rand()%k<<(i+1==n?'\n':' ');
	
	rep(i,0,n-1){
		int u = max(0, i - bigrand()%20) + 1, v = (i+1) + 1;
		cout<<u<<" "<<v<<endl;
	}
}
