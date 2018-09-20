#include <bits/stdc++.h>
using namespace std;
#define RG register
#define For(i, a, b) for(RG int i = a, ___u = b; i <= ___u; ++i)
#define Dor(i, a, b) for(RG int i = b, ___d = a; i >= ___d; --i)
#define Rep(i, a, b) for(RG int i = a, ___u = b; i != ___u; ++i)
#define rep Rep
#define down Dor
#define bin(x) (1 << (x))
#define len(x) ((int) (x).size())
#define cmax(i, j) ((i) < (j) ? (i) = (j), 1 : (0))
#define cmin(i, j) ((i) > (j) ? (i) = (j), 1 : (0))
#define dmax(i, j) ((j) < (i) ? (i) : (j))
#define dmin(i, j) ((i) < (j) ? (i) : (j))
#define diff(i, j) ((i) > (j) ? (i) - (j) : (j) - (i))
#define dabs(i) ((i) > 0 ? (i) : -(i))
#define dsqr(x) ((x) * (x))
#define lowbit(i) ((i) & -(i))
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;

namespace bgggay {

	const int MAX_N = 1 << 18 | 1;
	const int mod = 998244353, G = 3;
	using poly = vector<int>;

	constexpr int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	constexpr int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	constexpr int mul(int a, int b) { return (ll) a * b % mod; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
	constexpr int polish(int n) {return (n == 1) ? 1 : bin(32 - __builtin_clz(n - 1));}

	poly p[MAX_N];
	vector<int> e[MAX_N];


	int a, b, x, y;

	int eval(poly p, int x) {
		int v = 1, y = 0;
		for(auto a : p) {
			y = add(y, mul(a, v));
			v = mul(v, x);
		}
		return y;
	}

	bool dfs_path(int i, int g, int f) {
		bool on = 0;
		if(i == g) on = 1;
		else for(auto x : e[i]) if(x != f && dfs_path(x, g, i)) {
			on = 1; break;
		}
		if(on) y = (ll) y * eval(p[i], x) % mod;
		return on;
	}


	void __main__() {
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int T; cin >> T;
		while(T--) {
			int N, M; 
			cin >> N >> M;
			For(i, 1, N) {
				p[i].clear();
				e[i].clear();
				int n; cin >> n; n += 1;
				while(n--) {int x; cin >> x; p[i].push_back(x);}
			}
			For(i, 2, N) {
				int x, y;
				cin >> x >> y;
				e[x].push_back(y);
				e[y].push_back(x);
			}
			For(i, 1, M) {
				cin >> a >> b >> x;
				y = 1;
				dfs_path(a, b, 0);
				cout << y << '\n';
			}
			
		}
	}
}

int main() {
	bgggay::__main__();
}
