#include<cstdio>
#include<cassert>
#include<algorithm>
#define Mod 998244353
using namespace std;
int a[200100];
int n,Q;
int idx,b;
int ANS=-1;
int pai[200100],dp[200100];
int p2[200100];
int poww(int x,int y)
{
	if(y==0)
		return 1;
	long long ret=poww(x,y>>1);
	if(y&1)
		return ret*ret%Mod*x%Mod;
	return ret*ret%Mod;
}
int anti(int x)
{
	return poww(x,Mod-2);
}
void solve(int w,int idx)
{
	int i,j;
	long long R,A,B;
		pai[0]=1;
		for(i=1;i<=n;++i)
			pai[i]=(long long)pai[i-1]*a[i]%Mod;
	if(ANS==-1)
	{
		ANS=0;
		for(i=1;i<=n;++i)
			for(j=i;j<=n;++j)
			{
				ANS=ANS+(long long)pai[j]*anti(pai[i-1])%Mod*p2[n-j+i-3+(i==1)+(j==n)]%Mod;
				if(ANS>=Mod)
					ANS-=Mod;
			}
	}
	else
	{
		R=0;
		A=0;
		B=0;
		for(i=1;i<=idx;++i)
		{
			A+=(long long)p2[i-2+(i==1)]*anti(pai[i-1])%Mod;
			if(A>=Mod)
				A-=Mod;
		}
		for(i=idx;i<=n;++i)
		{
			B+=(long long)p2[n-i-1+(i==n)]*pai[i]%Mod;
			if(B>=Mod)
				B-=Mod;
		}
		R=(long long)A*B%Mod;
		ANS+=w*R;
		if(ANS<0)
			ANS+=Mod;
		if(ANS>=Mod)
			ANS-=Mod;
	}
}
int main()
{
	//freopen("../down/2.in","r",stdin);
	int i,j;
	scanf("%d",&n);
	assert(1<=n&&n<=200000);
	p2[0]=1;
	for(i=1;i<=n;++i)
		p2[i]=p2[i-1]*2%Mod;
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		assert(0<=a[i]&&a[i]<Mod);
	}
	scanf("%d",&Q);
	solve(0,0);
	printf("%d\n",ANS);
	assert(0<=Q&&Q<=200000);
	for(i=1;i<=Q;++i)
	{
		scanf("%d%d",&idx,&b);
		assert(1<=idx&&idx<=n);
		assert(0<=b&&b<Mod);
		solve(-1,idx);
		a[idx]=b;
		solve(1,idx);
		printf("%d\n",ANS);
	}
	return 0;
} 
