#include<cstdio>
#include<cassert>
#include<algorithm>
#include<ctime>
#define Mod 998244353
using namespace std;
int a[200100];
int n,Q;
int CLK;
int idx,b;
long long ANS=-1;
long long pai[200100];
long long p2[200100];
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
	if(ANS==-1)
	{
		ANS=0;
		for(i=1;i<=n;++i)
		{
			A=1;
			for(j=i;j<=n;++j)
			{
				A=A*a[j]%Mod;
				ANS+=A*p2[n-j+i-3+(i==1)+(j==n)]%Mod;
				if(ANS>=Mod)
					ANS-=Mod;
			}
		}
	}
	else
	{
		R=0;
		A=0;
		B=0;
		R=1;
		for(i=idx;i;--i)
		{
			R=R*a[i]%Mod;
			A+=p2[i-2+(i==1)]*R%Mod;
			if(A>=Mod)
				A-=Mod;
		}
		R=1;
		for(i=idx;i<=n;++i)
		{
			B+=p2[n-i-1+(i==n)]*R%Mod;
			if(B>=Mod)
				B-=Mod;
			R=R*a[i+1]%Mod;
		}
		R=A*B%Mod;
		ANS+=w*R;
		if(ANS<0)
			ANS+=Mod;
		if(ANS>=Mod)
			ANS-=Mod;
	}
}
int main()
{
	freopen("../data/1.in","r",stdin);
	freopen("1.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	assert(1<=n&&n<=200000);
	p2[0]=1;
	for(i=1;i<=n;++i)
		p2[i]=p2[i-1]*2%Mod;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		assert(0<=a[i]&&a[i]<Mod);
	}
	scanf("%d",&Q);
	solve(0,0);
	printf("%lld\n",ANS);
	assert(0<=Q&&Q<=200000);
	for(i=1;i<=Q;++i)
	{
		scanf("%d%d",&idx,&b);
		assert(1<=idx&&idx<=n);
		assert(0<=b&&b<Mod);
		solve(-1,idx);
		a[idx]=b;
		solve(1,idx);
		printf("%lld\n",ANS);
	}
	return 0;
} 
