#include <bits/stdc++.h>
using namespace std;
#define RG register
#define For(i, a, b) for(RG int i = a, ___u = b; i <= ___u; ++i)
#define Dor(i, a, b) for(RG int i = b, ___d = a; i >= ___d; --i)
#define Rep(i, a, b) For(i, a, (b) - 1)
#define rep Rep
#define down(i, b, a) Dor(i, a, (b) - 1)
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
	int qx[MAX_N], qy[MAX_N];
	vector<pair<int, int>> q[MAX_N];

	int dep[MAX_N], max_dep, fa[MAX_N], htop[MAX_N], size[MAX_N];
	int dfs_init(int i, int f) {
		int cnt = 1, max = 0, cho = 0;
		fa[i] = f; dep[i] = dep[f] + 1; htop[i] = 0;
		cmax(max_dep, dep[i]);
		for(auto k : e[i]) if(k != f) {
			int tmp = dfs_init(k, i);
			cnt += tmp; if(cmax(max, tmp)) cho = k;
		}
		htop[cho] = -1;
		size[i] = cnt;
		return cnt;
	}
	void dfs_make(int i) {
		htop[i] = (htop[i] ? htop[fa[i]] : i);
		for(auto k : e[i]) if(htop[k] <= 0) dfs_make(k);
	}
	int lca(int x, int y) {
		while(htop[x] != htop[y])
			dep[htop[x]] > dep[htop[y]]
				? x = fa[htop[x]] : y = fa[htop[y]];
		return dep[x] < dep[y] ? x : y;
	}

	namespace fft {
		class BGG_NTT_WORKER {
		private :
			int init_n;
			int w[2][2 * MAX_N];
			void fft(int a[], int n, int w[]) {
				init(n);
				for (int i = 0, j = 0; i < n; ++i) {
					if (i < j) std::swap(a[i], a[j]);
					for (int l = n / 2; (j ^= l) < l; l /= 2);
				}
				int *r = w + 1;
				for (int i = 2, m = 1; i <= n; r += m, m = i, i *= 2) {
					for (int j = 0; j < n; j += i) 
					{
						int *a_j_m = a + j + m, *a_j = a + j, t;
						for (int k = 0; k < m; ++k) {
							t 			= mul(a_j_m[k], r[k]);
							a_j_m[k] 	= sub(a_j[k], t);
							a_j[k] 		= add(a_j[k], t);
						}
					}
				}
			}
			void fft(int a[], int b[], int n, int w[]) {
				init(n);
				for (int i = 0, j = 0; i < n; ++i) {
					if (i < j) {std::swap(a[i], a[j]); std::swap(b[i], b[j]);}
					for (int l = n / 2; (j ^= l) < l; l /= 2);
				}
				int *r = w + 1;
				for (int i = 2, m = 1; i <= n; r += m, m = i, i *= 2) {
					for (int j = 0; j < n; j += i) 
					{
						int *a_j_m = a + j + m, *a_j = a + j, ta;
						int *b_j_m = b + j + m, *b_j = b + j, tb;
						for (int k = 0; k < m; ++k) {
							ta 			= mul(a_j_m[k], r[k]);
							a_j_m[k] 	= sub(a_j[k], ta);
							a_j[k] 		= add(a_j[k], ta);
							tb 			= mul(b_j_m[k], r[k]);
							b_j_m[k] 	= sub(b_j[k], tb);
							b_j[k] 		= add(b_j[k], tb);
						}
					}
				}
			}
		public :
			void init(int n) {
				if(n <= init_n) return;
				init_n = n;
				int a = qpow(G, (mod - 1) / n), b = mod_inv(a), h = n >> 1;
				w[0][h] = 1; w[1][h] = 1;
				rep (i, h + 1, n) {
					w[0][i] = mul(w[0][i - 1], a);
					w[1][i] = mul(w[1][i - 1], b);
				}
				down (i, h, 1) {
					w[0][i] = w[0][i << 1];
					w[1][i] = w[1][i << 1];
				}
			}
			void dft(int a[], int n) {
				fft(a, n, w[0]);
			}
			void dft(int a[], int b[], int n) {
				fft(a, b, n, w[0]);
			}
			void idft(int a[], int n) {
				fft(a, n, w[1]);
				int r = mod_inv(n);
				rep (i, 0, n) a[i] = mul(a[i], r);
			}
			void idft(int a[], int b[], int n) {
				fft(a, b, n, w[1]);
				int r = mod_inv(n);
				rep (i, 0, n) {a[i] = mul(a[i], r); b[i] = mul(b[i], r);}
			}
			void poly_mul(int n_a, int n_b, int a[], int b[], int c[])
			{
				int n = bin(32 - __builtin_clz(n_a + n_b - 1));
				fft(a, b, n, w[0]);
				rep (i, 0, n) c[i] = mul(a[i], b[i]);
				idft(c, n);
			}
		}	bgg;
		
		void poly_inv(int n, const int a[], int b[]) {
			if (n == 1) {
				b[0] = mod_inv(a[0]);
				return ;
			}
			static int c[MAX_N];
			int m = (n + 1) / 2;
			poly_inv(m, a, b);
			int T = bin(32 - __builtin_clz(n + n));
			memcpy(c, a, n << 2);
			memset(c + n, 0, (T - n) << 2);
			memset(b + m, 0, (T - m) << 2);
			bgg.dft(b, c, T);
			rep (i, 0, T) b[i] = mul(b[i], sub(2, mul(b[i], c[i])));
			bgg.idft(b, T);
		}
		void rev_copy(int n, const int a[], int b[]) {
			rep (i, 0, n) b[i] = a[n - i - 1];
		}
		void reverse(int n, int a[]) {
			int t;
			rep (i, 0, n / 2) { t = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = t; }
		}
		void poly_mul(int n, int m, const int a[], const int b[], int c[]) {
			static int X[MAX_N], Y[MAX_N];
			int T = bin(32 - __builtin_clz(n + m));
			memcpy(X, a, n << 2); memset(X + n, 0, (T - n) << 2);
			memcpy(Y, b, m << 2); memset(Y + m, 0, (T - m) << 2);
			bgg.dft(X, Y, T);
			rep (i, 0, T) X[i] = mul(X[i], Y[i]);
			bgg.idft(X, T);
			memcpy(c, X, (n + m - 1) << 2);
		}
		void poly_div(int n, int m, const int A[], const int B[], int D[], int R[]) {
			while (n and !A[n - 1]) --n;
			while (m and !B[m - 1]) --m;
			if (n < m) {
				if (D) D[0] = 0;
				memcpy(R, A, n << 2);
				memset(R + n, 0, (m - n) << 2);
				return ;
			}

			static int X[MAX_N], Y[MAX_N];
			int t = n - m + 1, Tn = bin(32 - __builtin_clz(t * 2));

			memset(X, 0, Tn << 2); rev_copy(m, B, X);  poly_inv(t, X, Y);
			memset(Y + t, 0, (Tn - t) << 2);
			rev_copy(n, A, X);
			memset(X + t, 0, (Tn - t) << 2);
			bgg.dft(X, Y, Tn);
			rep (i, 0, Tn) X[i] = mul(X[i], Y[i]); 
			bgg.idft(X, Tn); 
			reverse(t, X);

			if (D) memcpy(D, X, n << 2); 
			if (!R) return ;

			Tn = bin(32 - __builtin_clz(n));
			memset(X + t, 0, (Tn - t) << 2);
			memcpy(Y, B, m << 2); 
			memset(Y + m, 0, (Tn - m) << 2); 
			bgg.dft(X, Y, Tn);
			rep (i, 0, Tn) X[i] = mul(X[i], Y[i]); 
			bgg.idft(X, Tn);
			rep (i, 0, m) R[i] = sub(A[i], X[i]);
			while (m and !R[m - 1]) --m;
		}
		void maintain(poly &pol) { while (pol.size() > 1u and !pol.back()) pol.pop_back(); }
	}

	poly operator * (const poly &a, const poly &b) {
		using namespace fft;
		poly c(len(a) + len(b));
		poly_mul(len(a), len(b), a.data(), b.data(), c.data());
		maintain(c); return c;
	}
	poly operator % (const poly &a, const poly &b) {
		using namespace fft;
		poly c(len(b));
		poly_div(len(a), len(b), a.data(), b.data(), 0, c.data());
		maintain(c); 
		return c;
	}

	struct Data {
		poly p;
		vector<int> q;
	}	data[MAX_N * 40], *data_mem, *T[MAX_N << 1];
	int stack[MAX_N];

	void save(int i) {
		T[i] = new (data_mem++) Data{T[i << 1]->p * T[i << 1 | 1]->p, poly()};
	}
	void build(int i, int l, int r) {
		T[i] = 0;
		if(l != r) {
			int m = (l + r) >> 1;
			build(i << 1, l, m);
			build(i << 1 | 1, m + 1, r);
		}
	}
	int PN, top, ql, qv, lim;
	void insert(int i, int l, int r) {
		if(l == r) 
			T[i] = new (data_mem++) Data {p[stack[l]], poly()};
		else {
			int m = (l + r) >> 1;
			(top <= m) ? insert(i << 1, l, m) : insert(i << 1 | 1, m + 1, r);
			// if(r == top && l > 1 && !T[i - 1]) save(i - 1);
			if(r == top && r - l + 1 <= lim) save(i);
		}
	}
	void remove(int i, int l, int r) {
		T[i] = 0;
		if(l != r) {
			int m = (l + r) >> 1;
			(top <= m) ? remove(i << 1, l, m) : remove(i << 1 | 1, m + 1, r);
		}
	}
	void query(int i, int l, int r) {
		if(ql <= l && r <= top && T[i]) 
			return T[i]->q.push_back(qv);
		int m = (l + r) >> 1;
		if(ql <= m) query(i << 1, l, m);
		if(m < top) query(i << 1 | 1, m + 1, r);
	}

	void dfs_work(int i) {
		stack[++top] = i;
		lim = size[i];
		insert(1, 1, PN);
		for(auto Q : q[i]) {
			ql = Q.first;
			qv = Q.second;
			query(1, 1, PN);
		}
		for(auto x : e[i]) if(x != fa[i]) dfs_work(x);
		remove(1, 1, PN);
		--top;
	}

	int val[MAX_N], *ans[MAX_N];
	poly pre[MAX_N << 1];
	void prepare(int i, int l, int r) {
		if(l == r) 
			pre[i] = poly{sub(0, val[l]), 1};
		else {
			int m = (l + r) >> 1;
			prepare(i << 1, l, m);
			prepare(i << 1 | 1, m + 1, r);
			pre[i] = pre[i << 1] * pre[i << 1 | 1];
		}
	}
	void solve(int i, int l, int r, poly p) {
		p = p % pre[i];
		if(l == r) {
			*ans[l] = mul(*ans[l], p[0]);
			return;
		}
		int m = (l + r) >> 1;
		solve(i << 1, l, m, p);
		solve(i << 1 | 1, m + 1, r, move(p));
	}


	void __main__() {
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int T; cin >> T;
		for(int __ = 1; __ <= T; ++__) {
			int N, M; 
			cin >> N >> M;
			For(i, 1, N) {
				p[i].clear();
				e[i].clear();
				q[i].clear();
				int n; cin >> n; n += 1;
				while(n--) {int x; cin >> x; p[i].push_back(x);}
			}
			For(i, 2, N) {
				int x, y;
				cin >> x >> y;
				e[x].push_back(y);
				e[y].push_back(x);
			}
			max_dep = 0;
			dfs_init(1, 0);
			dfs_make(1);
			For(i, 1, M) {
				int x, y, z;
				cin >> x >> y >> qx[i];
				qy[i] = 1;
				z = lca(x, y);
				if(x == z) swap(x, y);
				q[x].push_back({dep[z], i});
				if(y != z) q[y].push_back({dep[z] + 1, i});
				qy[i] = 1;
			}
			data_mem = data;
			build(1, 1, PN = polish(max_dep));
			dfs_work(1);
			for(Data *d = data; d != data_mem; ++d) if(!d->q.empty()) {
				Rep(i, 0, d->q.size()) {
					val[i] = qx[d->q[i]];
					ans[i] = qy + d->q[i];
				}
				prepare(1, 0, d->q.size() - 1);
				solve(1, 0, d->q.size() - 1, d->p);
			}
			For(i, 1, M) cout << qy[i] << '\n';
		}
	}
}

int main() {
	bgggay::__main__();
}
