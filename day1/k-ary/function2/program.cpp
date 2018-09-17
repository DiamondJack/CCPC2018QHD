#include <bits/stdc++.h>

#define maxn 100000

using namespace std;

const int P = 998244353, G = 3;

int add(int a, int b)
{
	return (a + b) % P;
}

int sub(int a, int b)
{
	return (a - b + P) % P;
}

int mul(int a, int b)
{
	return (long long)a * b % P;
}

int fpow(int a, int b)
{
	int c = 1;
	while (b) {
		if (b & 1) c = mul(c, a);
		a = mul(a, a);
		b >>= 1;
	}
	return c;
}

int inv(int a)
{
	return fpow(a, P - 2);
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i == n - 1]);
}

int g[maxn << 2], gi[maxn << 2];

void init()
{
	int n = 2;
	while (n < (maxn << 2)) {
		int d = n >> 1;
		int gn = fpow(G, (P - 1) /  n), g = 1;
		for (int i = 0; i < d; i++) {
			::g[d + i] = g;
			g = mul(g, gn);
		}
		gn = inv(gn);
		g = 1;
		for (int i = 0; i < d; i++) {
			::gi[d + i] = g;
			g = mul(g, gn);
		}
		n <<= 1;
	}
}

void NTT(int a[], int n, int l, int f)
{
	static int rev[maxn << 2];
	rev[0] = 0;
	for (int i = 1; i < n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l - 1);
		if (i < rev[i]) {
			swap(a[i], a[rev[i]]);
		} else assert(rev[rev[i]] == i);
	}
	for (int i = 2; i <= n; i <<= 1) {
		int d = i >> 1;
		for (int j = 0; j < n; j += i) {
		    int *g = (f == -1 ? ::gi + i / 2 : ::g + i / 2);
			for (int k = 0; k < d; k++) {
				int x = a[j + k], y = mul(*g, a[j + k + d]);
				a[j + k] = add(x, y);
				a[j + k + d] = sub(x, y);
				g++;
			}
		}
	}
	if (f == -1) {
		int ni = inv(n);
		for (int i = 0; i < n; i++) a[i] = mul(a[i], ni);
	}
}


void mul(int a[], int n, int b[], int m, int c[])
{
	static int A[maxn << 2], B[maxn << 2], C[maxn << 2];
	int len = n + m - 1, N = 1, l = 0;
	while (N < len) N <<= 1, l++;
	for (int i = 0; i < n; i++) A[i] = a[i];
	for (int i = n; i < N; i++) A[i] = 0;
	for (int i = 0; i < m; i++) B[i] = b[i];
	for (int i = m; i < N; i++) B[i] = 0;
	NTT(A, N, l, 1);
	NTT(B, N, l, 1);
	for (int i = 0; i < N; i++) C[i] = mul(A[i], B[i]);
	NTT(C, N, l, -1);
	for (int i = 0; i < len; i++) c[i] = C[i];
}

void inv(int a[], int n, int b[])
{
	static int A[maxn << 2], B[maxn << 2], C[maxn << 2];
	assert(a[0] != 0);
	int N = 1, size = 1;
	while (size < n) size <<= 1;
	for (int i = 0; i < n; i++) A[i] = a[i];
	for (int i = n; i < size; i++) A[i] = 0;
	B[0] = inv(a[0]);
	while (N < n) {
		N <<= 1;
		mul(A, N, B, N >> 1, C);
		for (int i = 0; i < N; i++) C[i] = sub(0, C[i]);
		C[0] = add(C[0], 2);
		mul(B, N >> 1, C, N, B);
	}
	for (int i = 0; i < n; i++) b[i] = B[i];
}

void diff(int a[], int n, int b[])
{
	if (n == 0) return;
	for (int i = 0; i < n - 1; i++) b[i] = mul(i + 1, a[i + 1]);
}

void inti(int a[], int n, int b[])
{
	static int inv[maxn << 2];
	static bool flag = 0;
	if (!flag) {
		flag = 1;
		inv[1] = 1;
		for (int i = 2; i < (maxn << 2); i++)
			inv[i] = sub(0, mul(inv[P % i], P / i));
	}
	for (int i = n - 1; i >= 0; i--) b[i + 1] = mul(a[i], inv[i + 1]);
}


void ln(int a[], int n, int b[])
{
	static int B[maxn << 2], da[maxn << 2];
	assert(a[0] == 1);
	int N = 1;
	while (N < 2 * n) N <<= 1;
	diff(a, n, da);
	inv(a, n, b);
	mul(da, n - 1, b, n, B);
	inti(B, n - 1, b);
	b[0] = 0;
}

void exp(int a[], int n, int b[])
{
	static int A[maxn << 2], B[maxn << 2], C[maxn << 2];
	assert(a[0] == 0);
	int size = 1;
	while (size < n) size <<= 1;
	for (int i = 0; i < n; i++) A[i] = a[i];
	for (int i = n; i < size; i++) A[i] = 0;
	B[0] = 1;
	int N = 1;
	while (N < n) {
		N <<= 1;
		ln(B, N, C);
		for (int i = 0; i < N; i++) C[i] = sub(0, C[i]);
		C[0] = add(C[0], 1);
		for (int i = 0; i < N; i++) C[i] = add(C[i], A[i]);
		mul(B, N, C, N, B);
	}
	for (int i = 0; i < n; i++) b[i] = B[i];
}

void pow(int a[], int n, int k, int b[])
{
	assert(a[0] == 1);
	ln(a, n, b);
	for (int i = 0; i < n; i++) b[i] = mul(b[i], k);
	exp(b, n, b);
}

int main()
{
	freopen("input.txt", "r", stdin);
	::init();
	static int p[maxn << 2], q[maxn << 2], f[maxn << 2], g[maxn << 2], h[maxn << 2];
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		assert(k > 0);
		n++;
		f[0] = 1;
		int N = 1;
		while (N < n) {
			N <<= 1;
			pow(f, N, k - 1, g);
			for (int i = 1; i < N; i++) p[i] = mul(g[i - 1], k);
			p[0] = P - 1;
			mul(g, N, f, N, g);
			for (int i = 1; i < N; i++) q[i] = mul(g[i - 1], k - 1);
			q[0] = P - 1;
			inv(p, N, p);
			mul(p, N, q, N, f);
		}
		diff(f, n, q);
		pow(f, n, k - 1, p);
		for (int i = n - 1; i > 0; i--) p[i] = mul(P - k, p[i - 1]);
		p[0] = 1;
		inv(p, n, p);
		mul(p, n, q, n - 1, g);
		printf("%d\n", mul(inv(f[n - 1]), g[n - 2]));
	}
	return 0;
}