#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return (ll) a * b % mod; }

int calc(int n, int m) {
	if (!(n or m)) return 0;
	int res = 0;
	if ((n + m) & 1) {
		res = 1;
		n--;
	}
	return add(mul(calc((m - n) / 2, (-m - n) / 2), 2), res);
}

int main() {
//	freopen(".in", "r", stdin);
	int T, l, r, u, d;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int ans = 0;
		cin >> l >> r >> u >> d;
		for (int j = l; j <= r; ++j) {
			for (int k = u; k <= d; ++k) {
				ans = add(ans, calc(j, k));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
