#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const int md = int(1e9) + 7;

const int MAX_N = int(5e4) + 10;
const int MAX_K = 500 + 10;

vector<int> E[MAX_N];

int n,k;

int val[MAX_N];

bool del[MAX_N];

int size[MAX_N],opt[MAX_N],seq[MAX_N],pt;

void dfs(int u,int fa){
	size[u] = 1; opt[u] = 0; seq[pt++] = u;
	for(auto v : E[u]) if(v != fa && !del[v]){
		dfs(v,u);
		size[u] += size[v];
		opt[u] = max(opt[u],size[v]);
	}
}

int L[MAX_N],R[MAX_N];

void dfs2(int u,int fa){
	L[u] = pt;
	seq[pt++] = u;
	for(auto v : E[u]) if(v != fa && !del[v])
		dfs2(v,u);
	R[u] = pt;
}

static int dp[MAX_N][MAX_K];

inline void add(int&x,int c){
	x+=c; if(x>=md) x -= md;
}

int ans[MAX_K];

void solve(int x){
	pt = 0; dfs(x,-1);

	int rt = -1;

	rep(i,0,pt){
		int u = seq[i];
		opt[u] = max(opt[u], pt - opt[u]);
		if(rt == -1 || opt[u] < opt[rt])
			rt = u;
	}

	pt = 0; dfs2(rt,-1);

	rep(i,0,pt+1) memset(dp[i],0,sizeof(int) * k);

	dp[0][0] = 1;

	rep(i,0,pt){
		int u = seq[i];
		int nj = (0 + val[u]) % k;
		rep(j,0,k){
			add(dp[R[u]][j],dp[i][j]);
			add(dp[i+1][nj],dp[i][j]);
			++nj; if(nj==k) nj=0;
		}
	}

	rep(j,1,k)
		add(ans[j],dp[pt][j]);

	del[rt] = 1;

	for(auto v:E[rt]) if(!del[v])
		solve(v);
}

int main(){
	cin>>n>>k;

	rep(i,0,n) scanf("%d",val+i);

	rep(_,0,n-1){
		int a,b; scanf("%d%d",&a,&b),--a,--b;
		E[a].pb(b), E[b].pb(a);
	}

	solve(0);

	rep(j,1,k)
		printf("%d\n",ans[j]);

	return 0;
}