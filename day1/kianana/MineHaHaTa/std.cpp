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
struct exchange
{
	int u1,v1,u2,v2;
	int rank;
	exchange(){}
	exchange(int _u1,int _v1,int _u2,int _v2,int _rk)
	{u1=_u1;v1=_v1;u2=_u2;v2=_v2;rank=_rk;}
}mx,tmp;
bool operator<(exchange A,exchange B)
{
	if (A.rank!=B.rank)return A.rank<B.rank;
	if (A.v1+A.v2!=B.v1+B.v2)return (A.v1+A.v2)<(B.v1+B.v2);
	return (A.u1+A.u2)>(B.u1+B.u2);
}
bool operator>(exchange A,exchange B)
{
	if (A.rank!=B.rank)return A.rank>B.rank;
	if (A.v1+A.v2!=B.v1+B.v2)return (A.v1+A.v2)>(B.v1+B.v2);
	return (A.u1+A.u2)<(B.u1+B.u2);
}
int T;
int k,n,m;
char s[15];
int area[35][15],sp[35][15];
int times,score;
void print()
{
	puts("\n##########\n");
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=m;j++)
			putchar('A'+area[i][j]-1);
		puts("");
	}
	puts("\n##########\n");
}
void find()
{
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			if ((sp[k-n+i][j]==3)&&(sp[k-n+i+1][j]==3))
			{
				tmp=exchange(k-n+i,j,k-n+i+1,j,6);
				if (tmp>mx)mx=tmp;
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++)
			if ((sp[k-n+i][j]==3)&&(sp[k-n+i][j+1]==3))
			{
				tmp=exchange(k-n+i,j,k-n+i,j+1,6);
				if (tmp>mx)mx=tmp;
			}
	if (mx.rank==6)return;
}
void remove(int times)
{
	bool rm[15][15];
	memset(rm,0,sizeof(rm));
	if (mx.rank==6)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				rm[i][j]=1;
	}
	else if (mx.rank==5)
	{
		int color;
		if (sp[mx.u1][mx.v1]!=3)color=area[mx.u1][mx.v1];
		else color=area[mx.u2][mx.v2];
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (area[k-n+i][j]==color)
					rm[i][j]=1;
		rm[mx.u1-k+n][mx.v1]=rm[mx.u2-k+n][mx.v2]=1;
	}
	else
	{
		for (int i=2;i<n;i++)
			for (int j=2;j<m;j++)
			{
				if ((area[k-n+i][j]==area[k-n+i][j-1])&&(area[k-n+i][j]==area[k-n+i][j+1]))
				{
					rm[i][j]=1;
					rm[i][j-1]=1;
					rm[i][j+1]=1;
				}
				if ((area[k-n+i][j]==area[k-n+i-1][j])&&(area[k-n+i][j]==area[k-n+i+1][j]))
				{
					rm[i][j]=1;
					rm[i-1][j]=1;
					rm[i+1][j]=1;
				}
			}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (rm[i][j])continue;
			for (int p=1;p<=n;p++)
				if (rm[p][j]&&(sp[k-n+p][j]==1))rm[i][j]=1;
			for (int p=1;p<=m;p++)
				if (rm[i][p]&&(sp[k-n+i][p]==2))rm[i][j]=1;
		}
	int new_area[35][15],new_sp[35][15];
	memset(new_area,0,sizeof(new_area));
	memset(new_sp,0,sizeof(new_sp));
	if (mx.v1>=2&&mx.v1<=m-1)
	{
		if ((area[mx.u1][mx.v1]==area[mx.u1][mx.v1-1])&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1-2])
		&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1+1])&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1+2]))
		{
			new_sp[mx.u1][mx.v1-2]=3;
		}
		else if ((area[mx.u1][mx.v1]==area[mx.u1][mx.v1-1])
		&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1+1])&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1+2]))
		{
			new_area[mx.u1][mx.v1-1]=area[mx.u1][mx.v1];
			new_sp[mx.u1][mx.v1-1]=1;
		}
		else if ((area[mx.u1][mx.v1]==area[mx.u1][mx.v1-1])&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1-2])
		&&(area[mx.u1][mx.v1]==area[mx.u1][mx.v1+1]))
		{
			new_area[mx.u1][mx.v1-2]=area[mx.u1][mx.v1];
			new_sp[mx.u1][mx.v1-2]=1;
		}
	}
	if (mx.u1>=k-n+2&&mx.u1<=k-1)
	{
		if ((area[mx.u1][mx.v1]==area[mx.u1-1][mx.v1])&&(area[mx.u1][mx.v1]==area[mx.u1-2][mx.v1])
		&&(area[mx.u1][mx.v1]==area[mx.u1+1][mx.v1])&&(area[mx.u1][mx.v1]==area[mx.u1+2][mx.v1]))
		{
			new_sp[mx.u1+2][mx.v1]=3;
		}
		else if ((area[mx.u1][mx.v1]==area[mx.u1-1][mx.v1])
		&&(area[mx.u1][mx.v1]==area[mx.u1+1][mx.v1])&&(area[mx.u1][mx.v1]==area[mx.u1+2][mx.v1]))
		{
			new_area[mx.u1+2][mx.v1]=area[mx.u1][mx.v1];
			new_sp[mx.u1+2][mx.v1]=2;
		}
		else if ((area[mx.u1][mx.v1]==area[mx.u1-1][mx.v1])&&(area[mx.u1][mx.v1]==area[mx.u1-2][mx.v1])
		&&(area[mx.u1][mx.v1]==area[mx.u1+1][mx.v1]))
		{
			new_area[mx.u1+1][mx.v1]=area[mx.u1][mx.v1];
			new_sp[mx.u1+1][mx.v1]=2;
		}
	}
	if (mx.v2>=2&&mx.v2<=m-1)
	{
		if ((area[mx.u2][mx.v2]==area[mx.u2][mx.v2-1])&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2-2])
		&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2+1])&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2+2]))
		{
			new_sp[mx.u2][mx.v2-2]=3;
		}
		else if ((area[mx.u2][mx.v2]==area[mx.u2][mx.v2-1])
		&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2+1])&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2+2]))
		{
			new_area[mx.u2][mx.v2-1]=area[mx.u2][mx.v2];
			new_sp[mx.u2][mx.v2-1]=1;
		}
		else if ((area[mx.u2][mx.v2]==area[mx.u2][mx.v2-1])&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2-2])
		&&(area[mx.u2][mx.v2]==area[mx.u2][mx.v2+1]))
		{
			new_area[mx.u2][mx.v2-2]=area[mx.u2][mx.v2];
			new_sp[mx.u2][mx.v2-2]=1;
		}
	}
	if (mx.u2>=k-n+2&&mx.u2<=k-1)
	{
		if ((area[mx.u2][mx.v2]==area[mx.u2-1][mx.v2])&&(area[mx.u2][mx.v2]==area[mx.u2-2][mx.v2])
		&&(area[mx.u2][mx.v2]==area[mx.u2+1][mx.v2])&&(area[mx.u2][mx.v2]==area[mx.u2+2][mx.v2]))
		{
			new_sp[mx.u2+2][mx.v2]=3;
		}
		else if ((area[mx.u2][mx.v2]==area[mx.u2-1][mx.v2])
		&&(area[mx.u2][mx.v2]==area[mx.u2+1][mx.v2])&&(area[mx.u2][mx.v2]==area[mx.u2+2][mx.v2]))
		{
			new_area[mx.u2+2][mx.v2]=area[mx.u2][mx.v2];
			new_sp[mx.u2+2][mx.v2]=2;
		}
		else if ((area[mx.u2][mx.v2]==area[mx.u2-1][mx.v2])&&(area[mx.u2][mx.v2]==area[mx.u2-2][mx.v2])
		&&(area[mx.u2][mx.v2]==area[mx.u2+1][mx.v2]))
		{
			new_area[mx.u2+1][mx.v2]=area[mx.u2][mx.v2];
			new_sp[mx.u2+1][mx.v2]=2;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (rm[i][j])
			{
				score+=times*(sp[k-n+i][j]?3:1);
				area[k-n+i][j]=sp[k-n+i][j]=0;
			}
	for (int i=k-n+1;i<=k;i++)
		for (int j=1;j<=m;j++)
			if (rm[i-k+n][j])
			{
				area[i][j]=new_area[i][j];
				sp[i][j]=new_sp[i][j];
			}
}
void fall()
{
	for (int p=1;p<=k;p++)
		for (int i=1;i<k;i++)
			for (int j=1;j<=m;j++)
				if ((area[i+1][j]==0)&&(sp[i+1][j]==0))
				{
					area[i+1][j]=area[i][j];
					area[i][j]=0;
					sp[i+1][j]=sp[i][j];
					sp[i][j]=0;
				}
}
bool empty()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!area[k-n+i][j])return 1;
	return 0;
}
bool check()
{
	for (int i=2;i<n;i++)
		for (int j=2;j<m;j++)
		{
			if ((area[k-n+i][j]==area[k-n+i-1][j])&&(area[k-n+i][j]==area[k-n+i+1][j]))return 1;
			if ((area[k-n+i][j]==area[k-n+i][j-1])&&(area[k-n+i][j]==area[k-n+i][j+1]))return 1;
		}
	return 0;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&k,&n,&m);
		memset(area,0,sizeof(area));
		for (int i=1;i<=k;i++)
		{
			scanf("%s",s+1);
			for (int j=1;j<=m;j++)
				area[i][j]=s[j]-'A'+1;
		}
		memset(sp,0,sizeof(sp));
		score=0;
		while (true)
		{
			mx=exchange(0,0,0,0,0);
			find();
			if (mx.rank==0)break;
			swap(area[mx.u1][mx.v1],area[mx.u2][mx.v2]);
			remove(times=1);
			mx=exchange(0,0,0,0,0);
			fall();
			if (empty())break;
			while (check())
			{
				times*=2;
				remove(times);
				fall();
				if (empty())break;
			}
			if (empty())break;
		}
		printf("%d\n",score);
	}
	return 0;
}

