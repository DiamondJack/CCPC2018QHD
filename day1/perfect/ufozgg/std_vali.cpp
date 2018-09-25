#include<cstdio>
#include<cassert>
using namespace std;
int n;
int last[2000100],to[2000100],nex[2000100],top;
int fa[1000100],cnt[1000100],app[1000100];
int ans,K,leafdep;
int find(int now)
{
	if(fa[now]==now)
		return now;
	return fa[now]=find(fa[now]);
}
void dfs(int fa,int now,int d)
{
	int k0=0;
	for(int i=last[now];i;i=nex[i])
		if(to[i]!=fa)
		{
			++k0;
			dfs(now,to[i],d+1);
		}
	if(k0==0)
	{
		if(leafdep==-1)
			leafdep=d;
		if(leafdep!=d)
			leafdep=-2;
	}
	else
	{
		if(K==-1)
			K=k0;
		if(K!=k0)
			K=-2;
	}
}
bool check(int root)
{
	K=-1;
	leafdep=-1;
	dfs(0,root,0);
	if(K!=-2&&leafdep!=-2)
		return true;
	return false;
}
int main()
{
	int i,j,t,sumn=0,maxcnt,u,v;
	for(scanf("%d",&t);t;--t)
	{
		maxcnt=0;
		top=0;
		scanf("%d",&n);
		sumn+=n;
		assert(sumn<=1000000);
		for(i=1;i<=n;++i)
		{
			fa[i]=i;
			cnt[i]=0;
			last[i]=0;
			app[i]=0;
		}
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			assert(1<=u&&u<=n);
			assert(1<=v&&v<=n);
			++cnt[u];
			++cnt[v];
			if(cnt[u]>maxcnt)
				maxcnt=cnt[u];
			if(cnt[v]>maxcnt)
				maxcnt=cnt[v];
			assert(find(u)!=find(v));
			fa[find(u)]=v;
			++top;
			to[top]=v;
			nex[top]=last[u];
			last[u]=top;
			++top;
			to[top]=u;
			nex[top]=last[v];
			last[v]=top;
		}
		if(maxcnt<=2)
		{
			puts("1");
			continue;
		}
		for(i=1;i<=n;++i)
			if(app[cnt[i]]==0)
				app[cnt[i]]=i;
			else
				app[cnt[i]]=-1;
		ans=-1;
		for(i=1;i<=n;++i)
			if(app[cnt[i]]==i)
				if(check(i)&&(ans==-1||K<ans))
				{
					ans=K;
				}
		printf("%d\n",ans);
	}
	return 0;
}
 
