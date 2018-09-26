#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define MAXN 1024
#define MAXM 16384
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
class ZKW
{
public:
	int first[MAXN],targ[MAXM<<2],nxt[MAXM<<2],flow[MAXM<<2],cost[MAXM<<2],cnte;
	long long d[MAXN],inf;
	bool vis[MAXN],inq[MAXN];
	int s,t;
	ZKW()
	{
		memset(first,0,sizeof first);
		cnte=2;
	}
	void AddEdge(int u,int v,int f,int c)
	{
		targ[cnte]=v;flow[cnte]=f;cost[cnte]=c;nxt[cnte]=first[u];first[u]=cnte++;swap(u,v);
		targ[cnte]=v;flow[cnte]=0;cost[cnte]=-c;nxt[cnte]=first[u];first[u]=cnte++;
	}
	bool SPFA()
	{
		memset(d,127,sizeof d);
		memset(&inf,127,sizeof(long long));
		d[t]=0;
		queue<int> Q;
		Q.push(t);inq[t]=1;
		while(!Q.empty())
		{
			int x=Q.front();Q.pop();inq[x]=0;
			for(int i=first[x];i;i=nxt[i])
			{
				if(!flow[i^1])continue;
				if(d[targ[i]]>d[x]+cost[i^1])
				{
					d[targ[i]]=d[x]+cost[i^1];
					if(!inq[targ[i]])Q.push(targ[i]);
				}
			}
		}
		return d[s]!=inf;
	}
	long long DFS(int x,long long maxflow=2147483647)
	{
		if(x==t||!maxflow)return maxflow;
		if(vis[x])return 0;
		vis[x]=1;
		long long ret=0,f;
		for(int i=first[x];i;i=nxt[i])
		{
			if(flow[i]&&d[targ[i]]==d[x]-cost[i]&&(f=DFS(targ[i],min(maxflow,(long long)flow[i]))))
			{
				flow[i]-=f;
				flow[i^1]+=f;
				maxflow-=f;
				ret+=f;
				if(!maxflow)break;
			}
		}
		return ret;
	}
	long long Solve(int source,int tank,long long fund)
	{
		s=source;
		t=tank;
		long long ret=0;
		while(SPFA())
		{
			memset(vis,0,sizeof vis);
			long long f=DFS(s,fund/d[s]);
			fund-=f*d[s];
			ret+=f;
			if(fund<d[s])break;
			//printf("%lld %lld %lld %lld\n",d[s],f,ret,fund);
		}
		return ret;
	}
}zkw;
int n,m;
long long f;
int main()
{
	n=read();m=read();scanf("%lld",&f);
	for(int i=0;i<m;i++)
	{
		int u=read(),v=read(),f=read(),c=read();
		zkw.AddEdge(u,v,f,c);
		zkw.AddEdge(v,u,f,c);
	}
	printf("%lld\n",zkw.Solve(1,n,f));
}
/*
6 6 12
1 2 5 0
2 3 5 1
2 4 5 1
3 5 5 1
4 5 5 1
5 6 5 0
*/