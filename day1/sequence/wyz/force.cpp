#include <bits/stdc++.h>

using namespace std;
const int P=998244353;
/* int fast_pow(int x,int y,int mod=P){
	int ret=1;
	while (y){
		if (y&1) ret=1LL*ret*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return ret;
} */

const int N=200005;
int bin[N];
int a[N],n;

int calcAns(){
	int ret=0;
	for (int l=1;l<=n;++l){
		int now=1;
		for (int r=l;r<=n;++r){
			now=1LL*now*a[r]%P;
			if (now==0) break;
			int k=n-r+l-3;
			if (l==1) ++k;
			if (r==n) ++k;
			ret=(ret+1LL*now*bin[k])%P;
			// printf("%d %d  %d %d \n",l,r,now,k);
		}
	}
	return ret;
}

int main(int argc,char** argv){
	bool pseq=false;
	for (int i=0;i<argc;++i){
		if (string(argv[i])=="-pseq") pseq=true;
	}
	scanf("%d",&n);
	bin[0]=1;
	for (int i=1;i<=n;++i) bin[i]=2LL*bin[i-1]%P;
	for (int i=1;i<=n;++i)
		scanf("%d",a+i);
	printf("%d\n",calcAns());
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,val;
		scanf("%d%d",&x,&val);
		a[x]=val;
		if (pseq){
			for (int i=1;i<=n;++i) printf("%d ",a[i]);
			puts("");
		}
		printf("%d\n",calcAns());
	}
	return 0;
}
