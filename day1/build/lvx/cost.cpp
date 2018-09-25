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
	const int mod = 1e9 + 7;
	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
	inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
}

const int inf = 0x3f3f3f3f;
const int MAX_N = 1005;
const int MAX_M = 10005;

class Network {
private :
	struct edge {
		int to, c, w;
		edge *rev, *nxt;
	};
	edge poolEdge[MAX_M * 4], *poolCur = poolEdge;
	edge *head[MAX_N], *pa[MAX_N];
	ll d[MAX_N];
	int N, S, T;
public :
	bool spfa() {
		static bool inq[MAX_N];
		static int que[MAX_N], l, r;
		memset(d, 0x3f, sizeof(ll) * (N + 1));
		l = r = 0;
		d[S] = 0;
		que[r++] = S;
		inq[S] = 1;
		while (l != r) {
			int u = que[l++];
			inq[u] = 0;
			(l == MAX_N) and (l = 0);
			for (edge *p = head[u]; p; p = p->nxt) {
				if (p->c and upmin(d[p->to], d[u] + p->w)) {
					pa[p->to] = p;
					if (!inq[p->to]) {
						que[r++] = p->to;
						(r == N) and (r = 0);
						inq[p->to] = 1;
					}
				}
			}
		}
		return d[T] < inf;
	}

	void init(int n) {
		N = n;
		poolCur = poolEdge;
		for (int i = 0; i <= n; ++i) head[i] = NULL;
	}

	inline void addEdge(int x, int y, int c, int w) {
		*poolCur = {y, c, w, poolCur + 1, head[x]}; head[x] = poolCur++;
		*poolCur = {x, 0, -w, poolCur - 1, head[y]}; head[y] = poolCur++;
	}

	void augment(int &flow, ll &cost) {
		int a = min((d[T] == 0 ? inf : cost / d[T]), ll(inf));
		for (edge *p = pa[T]; p; p = pa[p->rev->to]) upmin(a, p->c);
		for (edge *p = pa[T]; p; p = pa[p->rev->to]) {
			p->c -= a;
			p->rev->c += a;
		}
		flow += a;
		cost -= (ll) a * d[T];
	}

	int run(int s, int t, ll flow) {
		S = s, T = t;
		int ans = 0;
		while (spfa()) {
			if (flow < d[t]) break ;
			augment(ans, flow);
		}
		return ans;
	}
} my;

int main() {
#ifdef LX_JUDGE
	freopen(".in", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int n, m;
	ll flow;
	cin >> n >> m >> flow;
	my.init(n);
	rep (i, 0, m) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		my.addEdge(x, y, u, v);
	}
	printf("%d\n", my.run(1, n, flow));
	return 0;
}
