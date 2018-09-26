#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i < _; ++i)
#define down(i, x, y) for (int i = (x) - 1, _ = (y); i >= _; --i)
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define bin(x) (1 << (x))
#define SZ(x) int((x).size())
//#define LX_JUDGE

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> Vi;
typedef long long ll;

template<typename T> inline bool upmax(T &x, T y) { return x < y ? (x = y, 1) : 0; }
template<typename T> inline bool upmin(T &x, T y) { return x > y ? (x = y, 1) : 0; }

namespace MATH_CAL {
	const int mod = 998244353;
	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
	inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
} using namespace MATH_CAL;

#define FILE_IN "1.in"
#define FILE_ANS "1.ans"

const int MAX_N = bin(18) + 1;
const int inf = 0x3f3f3f3f;

fstream fin, fans;

struct Poly {
	vector<int> P;
	void read() {
		int N;
		fin >> N;
		P.resize(N + 1);
		rep (i, 0, N + 1) fin >> P[i];
	}
	int eval(int x) {
		int res = 0;
		down (i, P.size(), 0) res = add(mul(res, x), P[i]);
		return res;
	}
} my[MAX_N];

int fa[MAX_N], dep[MAX_N];
vector<int> g[MAX_N];

void dfs(int x) {
	for (auto u : g[x]) {
		if (fa[x] == u) continue ;
		dep[u] = dep[x] + 1;
		fa[u] = x;
		dfs(u);
	}
}

int N, M;

int query(int x, int y, int v) {
	int res = 1;
	while (x != y) {
		if (dep[y] > dep[x]) swap(x, y);
		res = mul(res, my[x].eval(v));
		x = fa[x];
	}
	res = mul(res, my[x].eval(v));
	return res;
}

int tcs;

void WORK() {
	fin >> N >> M;
	printf("%d : %d, %d\n", ++tcs, N, M);
	rep (i, 1, N + 1) g[i].clear();
	rep (i, 1, N + 1) my[i].read();
	rep (i, 1, N) {
		int x, y;
		fin >> x >> y;
		g[x].pb(y); g[y].pb(x);
	}
	fa[1] = 0; dfs(1);
	bool flag = (N < 1000 and M < 1000);
	rep (i, 0, M) {
		int s, t, v;
		fin >> s >> t >> v;
		int ans = flag ? query(s, t, v) : -1;
		int res;
		fans >> res;
		assert(ans == -1 or ans == res);
	}
}

int main() {
#ifdef LX_JUDGE
	freopen(".in", "r", stdin);
#endif
	fin.open(FILE_IN);
	fans.open(FILE_ANS);
	int T;
	fin >> T;
	while (T--) WORK();
	puts("All verified");
	return 0;
}
