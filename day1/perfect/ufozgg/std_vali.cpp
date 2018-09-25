#include<cstdio>
#include<cassert>
using namespace std;
int n;
int fa[1000100],cnt[1000100];
int main()
{
	int i,j,t,sumn=0,maxcnt;
	for(scanf("%d",&t);t;--t)
	{
		maxcnt=0;
		scanf("%d",&n);
		sumn+=n;
		assert(sumn<=1000000);
		for(i=1;i<=n;++i)
		{
			fa[i]=0;
			cnt[i]=0;
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
		}
	}
	return 0;
}
 
