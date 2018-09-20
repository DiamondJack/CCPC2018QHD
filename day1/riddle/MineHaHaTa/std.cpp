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
int main()
{
	for (int i=1;i<(1<<N);i++)
		cnt[i]=cnt[i>>1]+(i&1);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(s,0,sizeof(s));
		for (int i=0;i<(1<<n);i++)
			for (int j=i;j;j^=lowbit(j))
				s[i]=s[i^(lowbit(j))]+a[cnt[lowbit(j)-1]+1];
	}
	return 0;
}

