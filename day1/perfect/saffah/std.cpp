#include <bits/stdc++.h>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)
#define foreach(x, y) for(__typeof(y.begin()) x = y.begin(); x != y.end(); ++x)
using namespace std;

int read()
{
	int x; scanf("%d", &x); return x;
}
void write(int x)
{
	printf("%d\n", x);
}

vector<int> adj[1000007];

#define answer(x) do{write(x); goto gg;}while(0)

int dfs(int x, int p, int sons)
{
	int dep = -1, s = 0;
	foreach(it, adj[x]) if(*it != p)
	{
		int d = dfs(*it, x, sons);
		++s;
		if(dep == -1) dep = d;
		else if(dep != d) throw 233;
	}
	if(s && s != sons) throw 233;
	return dep + 1;
}

int main()
{
	int T = read();
	while(T--)
	{
		int n = read();
		f(i, 1, n) adj[i].clear();
		g(i, 1, n)
		{
			int x = read(), y = read();
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int maxd = 0, root = 0;
		f(i, 1, n) maxd = max(maxd, (int) adj[i].size());
		if(maxd <= 2) answer(1);
		if(maxd == n - 1) answer(n - 1);
		f(i, 1, n) if((int) adj[i].size() == maxd - 1)
		{
			if(root) answer(-1);
			else root = i;
		}
		if(!root) answer(-1);
		try
		{
			dfs(root, 0, maxd - 1);
			answer(maxd - 1);
		}
		catch(int)
		{
			answer(-1);
		}
	gg:;
	}
	return 0;
}
