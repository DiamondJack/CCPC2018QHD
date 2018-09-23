#include <bits/stdc++.h>
#define ll long long
#define N 50005
#define K 505
#define P 1000000007

using namespace std;
inline int read(){
	int ret=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while ('0'<=ch&&ch<='9'){
		ret=ret*10-48+ch;
		ch=getchar();
	}
	return ret;
}

struct edge{
	int adj,next;
	edge(){}
	edge(int _adj,int _next):adj(_adj),next(_next){}
} e[N*2];
int n,g[N],m;
void AddEdge(int u,int v){
	e[++m]=edge(v,g[u]);g[u]=m;
	e[++m]=edge(u,g[v]);g[v]=m;
}

#define inc(x,y,mod) if(((x)+=(y))>=mod)(x)-=mod
#define dec(x,y,mod) if(((x)-=(y))<0)(x)+=mod

int k;
void multiply(int *u,int *v){
	int res[K],to;
	memset(res,0,sizeof(res));
	for (int i=0;i<k;++i)for (int j=0;(to=j)<k;++j){
		inc(to,i,k);
		res[to]=(1LL*u[i]*v[j]+res[to])%P;
	}
	for (int i=0;i<k;++i) inc(u[i],res[i],P);
}

int dp[N][K];

int a[N];
int fa[N];
void dfs(int u){
	dp[u][a[u]]=1;
	for (int i=g[u];i;i=e[i].next){
		int v=e[i].adj;
		if (fa[u]==v) continue;
		fa[v]=u;
		dfs(v);
		multiply(dp[u],dp[v]);
	}
}

int main(){
	n=read();k=read();
	for (int i=1;i<=n;++i) a[i]=read();
	memset(g,0,sizeof(g));m=1;
	for (int i=1;i<n;++i) AddEdge(read(),read());
	fa[1]=0;
	memset(dp,0,sizeof(dp));
	dfs(1);
	for (int i=1;i<k;++i){
		int res=0;
		for (int u=1;u<=n;++u) inc(res,dp[u][i],P);
		printf("%d\n",res);
	}
	return 0;
}
