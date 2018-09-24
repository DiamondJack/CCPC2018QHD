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
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = (ll) x * x % mod) if (n & 1) r = (ll) r * x % mod; return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
} using namespace MATH_CAL;

int f[2][3][3][3][3], g[2][3][3][3][3];		// 0 / 1 / 2 : your - lim + 1
vector<pair<ll, ll> > vec;

inline int sign(ll x) { return x < 0 ? -1 : (x > 0); }
inline int val(int x, int y) { return x == 0 ? y : -y; }

void Solve() {
	memset(f, 0, sizeof f);
	memset(g, 0, sizeof g);
	vec.clear();

	ll lim_X, lim_Y, N;
	cin >> lim_X >> lim_Y;
	N = max(lim_X, lim_Y);

	ll nx = 1, ny = 0;

	while (max(abs(nx), abs(ny)) <= N * 10) {
		vec.pb(mp(nx, ny));
		ll tx = -nx - ny;
		ll ty = nx - ny;
		nx = tx;
		ny = ty;
	}

	ll Lim = 1;
	while (Lim * 2 <= N * 10) Lim <<= 1;

	static int h[2][3][3], r[2][3][3];

	int t = 0, d = 0;
	int flag1 = 0, flag2 = 0;

	f[t][2][2][1][1] = 1;

	while (Lim > 0) {
		memset(h[d], 0, sizeof(h[d]));
		memset(r[d], 0, sizeof(r[d]));
		h[d][1][1] = 1;

		while (!vec.empty() and max(abs(vec.back().fi), abs(vec.back().se)) == Lim) {
			int u = sign(vec.back().fi), v = sign(vec.back().se);
			vec.pop_back();
			int w = qpow(2, vec.size());
			memset(h[d ^ 1], 0, sizeof(h[d ^ 1]));
			memset(r[d ^ 1], 0, sizeof(r[d ^ 1]));
			rep (i, 0, 3) rep (j, 0, 3) {
				if (r[d][i][j]) {
					int x = r[d][i][j];
					Add(r[d ^ 1][i][j], x);
					Add(r[d ^ 1][i + u][j + v], x);
				}
				if (h[d][i][j]) {
					int x = h[d][i][j];
					Add(h[d ^ 1][i][j], x);
					Add(h[d ^ 1][i + u][j + v], x);
					Add(r[d ^ 1][i + u][j + v], mul(x, w));
				}
			}
			d ^= 1;
		}

		int w1 = (lim_X & Lim) > 0;
		int w2 = (lim_Y & Lim) > 0;

		memset(f[t ^ 1], 0, sizeof(f[t ^ 1]));
		memset(g[t ^ 1], 0, sizeof(g[t ^ 1]));

		rep (_i, 0, 3) rep (_j, 0, 3) rep (a, -1, 2) rep (b, -1, 2) {
			rep (i, 0, 3) rep (j, 0, 3) {
				int x, y, vx, vy;
				if (_i == 2) {
					x = (i == 1) ? 2 : (i > 0);
					if (x == 2) {
						vx = 0;
					} else {
						vx = val(x, flag1) + val(x, w1) + (i - 1);
					}
				} else {
					x = _i;
					vx = (a * 2) + (i - 1) + val(x, w1);
				}
				if (_j == 2) {
					y = (j == 1) ? 2 : (j > 0);
					if (y == 2) {
						vy = 0;
					} else {
						vy = val(y, flag2) + val(y, w2) + (j - 1);
					}
				} else {
					y = _j;
					vy = (b * 2) + (j - 1) + val(y, w2);
				}

				if (x == 2) assert(vx == 0);
				if (y == 2) assert(vy == 0);
				if ( (x == 0 and vx < -1) or (x == 1 and vx > 1) or (y == 0 and vy < -1) or (y == 1 and vy > 1) ) continue ;

				upmin(vx, 1);
				upmax(vx, -1);
				upmin(vy, 1);
				upmax(vy, -1);

				Add(f[t ^ 1][x][y][vx + 1][vy + 1], mul(f[t][_i][_j][a + 1][b + 1], h[d][i][j]));
				Add(g[t ^ 1][x][y][vx + 1][vy + 1], mul(f[t][_i][_j][a + 1][b + 1], r[d][i][j]));
				Add(g[t ^ 1][x][y][vx + 1][vy + 1], mul(g[t][_i][_j][a + 1][b + 1], h[d][i][j]));
			}
		}

		t ^= 1;
		Lim /= 2;
		if (w1) flag1 = 2;
		if (w2) flag2 = 2;
	}

	int ans = 0;

	rep (i, 0, 3) rep (j, 0, 3) rep (a, 0, 3) rep (b, 0, 3) {
		if ( (i == 0 and a == 0) or (i == 1 and a == 2) or (j == 0 and b == 0) or (j == 1 and b == 2) ) {
			continue ;
		}
		Add(ans, g[t][i][j][a][b]);
	}

	cout << ans << endl;
}

int main() {
//	freopen(".in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) Solve();
	return 0;
}
