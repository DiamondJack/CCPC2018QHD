#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Rand(ll l, ll r) {
	ll tmp = (ll(rand()) << 31) ^ (rand());
	return tmp % (r - l + 1) + l;
}

ll x[] = {   0,    0,    1,    1,    213123,   4234234, 0,   1 };
ll y[] = {	1121312, 21311, 989564, 6453432, 0,   1,     0,  0 };

int main() {
	srand(981118);
	int T = 1000;
	printf("%d\n", T);
	for (int i = 0; i < T - 8; ++i) {
		ll x = Rand(1, 1e15), y = Rand(1, 1e15);
		printf("%lld %lld\n", x, y);
	}
	for (int i = 0; i < 8; ++i) printf("%lld %lld\n", x[i], y[i]);
	return 0;
}
