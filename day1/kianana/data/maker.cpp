#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
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
int k,n,m;
int a[35][15];
bool check()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if ((j>=2)&&(j<=m-1)&&(a[k-n+i][j]==a[k-n+i][j-1])&&(a[k-n+i][j]==a[k-n+i][j+1]))return 1;
			if ((i>=2)&&(i<=n-1)&&(a[k-n+i][j]==a[k-n+i-1][j])&&(a[k-n+i][j]==a[k-n+i+1][j]))return 1;
		}
	return 0;
}
int main()
{
	freopen("1.in","w",stdout);
	srand(time(NULL));
	puts("10");
	for (int T=1;T<=10;T++)
	{
		k=30;n=rand()%6+5;m=rand()%6+5;
		printf("%d %d %d\n",k,n,m);
		for (int i=1;i<=k;i++)
			for (int j=1;j<=m;j++)
				a[i][j]=rand()%6+'A';
		while (check())
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=m;j++)
					a[k-n+i][j]=rand()%6+'A';
		}
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=m;j++)
				printf("%c",a[i][j]);
			puts("");
		}
	}
	return 0;
}

