#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define N 15
#define lowbit(x) ((x)&(-(x)))
using namespace std;
inline int read()
{
	int num=0,sgn=1;
	char ch=getchar();
	while (ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if (ch=='-')sgn=-1,ch=getchar();
	while (ch>='0'&&ch<='9')num*=10,num+=ch-'0',ch=getchar();
	return num*sgn;
}
int T,cnt[1<<N];
int n,a[N+1],s[1<<N];
int pre[N+1][1<<N];
int f[1<<N];
void solve(int id,int mx,int st,int toy)
{
	if (id==n)
	{
		if (toy<=(1<<mx))
		{
			f[st|toy]+=f[toy]*pre[mx][st];
			if (st==(1<<mx))f[st|toy]+=f[toy];
		}
		return;
	}
	if (!(toy&(1<<id)))
		solve(id+1,id,st|(1<<id),toy);
	solve(id+1,mx,st,toy);
}
int main()
{
	for (int i=1;i<(1<<N);i++)
		cnt[i]=cnt[i>>1]+(i&1);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if (n==1)
		{
			puts("1");
			continue;
		}
		sort(a,a+n);
		memset(s,0,sizeof(s));
		for (int i=1;i<(1<<n);i++)
			for (int j=i;j;j^=lowbit(j))
				s[i]=s[i^(lowbit(j))]+a[cnt[lowbit(j)-1]];
		memset(pre,0,sizeof(pre));
		pre[0][0]=1;
		for (int i=0;i<n;i++)
			for (int j=1;j<(1<<i);j++)
				if (a[i]==s[j])
				{
					pre[i][j|(1<<i)]=1;
					if (j==lowbit(j))pre[i][j|(1<<i)]++;
				}
		memset(f,0,sizeof(f));
		f[0]=1;
		for (int i=0;i<(1<<n);i++)
			solve(0,0,0,i);
		printf("%d",f[(1<<n)-1]);
		if (T)puts("");
	}
	return 0;
}

