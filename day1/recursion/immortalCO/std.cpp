#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
const char Table1[] = "00037477707344474043343730330407010E750A717E457A414E354A313E053A0C0F080B7C7F787B4C4F484B3C3F383B0DD209667D6279964D9249263D2239D6D0D3646760639497909324272023D4D7D1DE65DA616E956A919E259A212ED52ADCDFD8DB6C6F686B9C9F989B2C2F282BDDC2D9B66DB269869D8299F62DF229C6C0C3B4B7B0B384878083F4F7F0F3C4C7C1CEB5CAB1BE85BA818EF58AF1FEC5FACCCFC8CBBCBFB8BB8C8F888BFCFFF8FBCD12C9A6BDA2B9568D5289E6FDE2F9161013A4A7A0A354575053E4E7E0E31417111EA51AA1AE55AA515EE55AE1EE15EA1C1F181BACAFA8AB5C5F585BECEFE8EB1D021976AD72A9465D425936ED32E906";
const char Table2[] = "00000000000000000000AAAAAAAAAAAA00000000000000000000AA00AAAAAAAA000000000000000000000000AAAAAAAA00550000000000FF00FF00AAAAAAAAFF555500000000FFFFFFFFAAAAAAAAFFFF555500550000FF00FFFFAAFFAAAAFFAA5555555500000000FFFFFFFFAAAAAAAA555555FF00FF00FFFFFFFFFFAAFFAAFF5555FFFFFFFFFFFFFFFFFFFFFFFFFFFF5555FF55FFFFFFFFFFFFFFFFFFFFFFFF55555555FFFFFFFFFFFFFFFFFFFFFFFF555555FFFFFFFF55FF55FFFFFFFFFFFF5555FFFFFFFF55555555FFFFFFFFFFFF5555FF55FFFF55FF5555FF55FFFFFFFF55555555FFFFFFFF55555555FFFFFFFF55555555FF55FF55555555FFFFFFFFFF";
int fromHex(char c) {return '0' <= c && c <= '9' ? c - '0' : 10 + c - 'A';}
unsigned char Tval[16][16];
bool Tmov[16][16][2][2][2];

const int MAX_L = 19;
int N[MAX_L], M[MAX_L], pwr[MAX_L], Nt, Mt;
int decomp(ll x, int X[], int &t) {
	int L = 0;
	if(x >= 0) {
		t = 0;
		for(int i = 0; i < MAX_L; ++i) X[i] = 0;
		while(x) {X[++L] = x & 15; x >>= 4;}
	} else {
		t = 1;
		for(int i = 0; i < MAX_L; ++i) X[i] = 15;
		while(~x) {X[++L] = x & 15; x >>= 4;}
	}
	return L;
}

int add(int x, int v) {x += v; return x >= mod ? x - mod : x;}
int sub(int x, int v) {x -= v; return x < 0 ? x + mod : x;}
void Add(int &x, int v) {x = add(x, v);}

struct Data{
	int sum, cnt;
	void operator += (const Data& D) {Add(sum, D.sum); Add(cnt, D.cnt);}
	Data connect(int x) const {return (Data) {add(sum, (ll) cnt * x % mod), cnt};}
};
struct Value{Data val[2][2][2][2];}	f[MAX_L][2][2], E, I;
int vis[MAX_L][2][2], timer;

void range(int x, bool f, bool t, int &l, int &r) {
	if(f) {l = 0; r = 15; return;}
	if(!t) {l = 0; r = x;}
	else {l = x; r = 15;}
}

Value calc(int bit, bool freeN, bool freeM) {
	// cerr << bit << ' ' << freeN << ' ' << freeM << endl;
	if(!bit) return I;
	if(vis[bit][freeN][freeM] == timer) return f[bit][freeN][freeM];
	Value ans = E;
	int Nl, Nr, Ml, Mr;
	range(N[bit], freeN, Nt, Nl, Nr);
	range(M[bit], freeM, Mt, Ml, Mr);
	for(int Nx = Nl; Nx <= Nr; ++Nx)
		for(int Mx = Ml; Mx <= Mr; ++Mx) {
			Value d(calc(bit - 1, freeN || Nx != N[bit], freeM || Mx != M[bit]));
			for(int Nadd = 0; Nadd <= 1; ++Nadd)
				for(int Madd = 0; Madd <= 1; ++Madd) {
					int Nr = Nx + Nadd, Mr = Mx + Madd;
					Data cur = d.val[Nr & 1][Mr & 1][Nadd][Madd].connect((ll) Tval[Nr & 15][Mr & 15] * pwr[bit - 1] % mod);
					for(int Nout = 0; Nout <= 1; ++Nout)
						for(int Mout = 0; Mout <= 1; ++Mout) {							
							auto mov = Tmov[Nr & 15][Mr & 15][bool((Nr + (Nout << 4)) & 16)][bool((Mr + (Mout << 4)) & 16)];
							ans.val[Nout][Mout][mov[0] + (Nr >> 4)][mov[1] + (Mr >> 4)] += cur;
						}
					}
		}

	vis[bit][freeN][freeM] = timer;
	f[bit][freeN][freeM] = ans;
	return ans;
}  

int solve(ll a, ll b) {
	int L = max(decomp(a, N, Nt), decomp(b, M, Mt));
	++timer;
	auto ans = calc(L + 1, 0, 0);
	Data o = {0, 0};
	for(int a = 0; a <= 1; ++a) for(int b = 0; b <= 1; ++b) o += ans.val[Nt][Mt][a][b];
	return o.sum;
}

vector<ll> hx, hy;
int _ans[8][8], Hx, Hy, Px, Py;
int ans(int x, int y) {
	if(!hx[x] || !hy[y]) return 0;
	if(_ans[x][y] == -1) _ans[x][y] = solve(hx[x] - (hx[x] > 0), hy[y] - (hy[y] > 0)); 
	return _ans[x][y];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < 16; ++i) for(int j = 0; j < 16; ++j) {
		Tval[i][j] = fromHex(Table1[i * 32 + j * 2]) * 16 + fromHex(Table1[i * 32 + j * 2 + 1]);
		for(int c = 0; c <= 1; ++c) for(int d = 0; d <= 1; ++d) for(int k = 0; k <= 1; ++k)
			Tmov[i][j][c][d][k] = (fromHex(Table2[i * 32 + j * 2 + c]) >> (2 * d + k)) & 1;
	}
	pwr[0] = 1;
	for(int i = 1; i < MAX_L; ++i) pwr[i] = (ll) pwr[i - 1] * 256 % mod;
	for(int a = 0; a <= 1; ++a) for(int b = 0; b <= 1; ++b) 
		I.val[a][b][0][0].cnt = 1;

	long long l, r, u, d;
	while(cin >> l >> r >> u >> d) {
		hx = vector<ll>{l, ++r, 0ll};
		hy = vector<ll>{u, ++d, 0ll};
		sort(hx.begin(), hx.end()); hx.erase(unique(hx.begin(), hx.end()), hx.end());
		sort(hy.begin(), hy.end()); hy.erase(unique(hy.begin(), hy.end()), hy.end());
		Hx = hx.size(); Hy = hy.size();
		for(int i = 0; i < Hx; ++i) for(int j = 0; j < Hy; ++j) _ans[i][j] = -1;
		long long Ans = 0;
		for(int i = 1; i < Hx; ++i) for(int j = 1; j < Hy; ++j) {
			ll l0 = hx[i - 1], r0 = hx[i], u0 = hy[j - 1], d0 = hy[j];
			if(l <= l0 && r0 <= r && u <= u0 && d0 <= d) {
				// printf("calc %lld %lld %lld %lld\n",l,r,u,d);
				if(r0 > 0 && d0 > 0) 		Ans += ans(i, j) - ans(i - 1, j) - ans(i, j - 1) + ans(i - 1, j - 1);
				else if(r0 > 0 && u0 < 0)	Ans += ans(i, j - 1) - ans(i - 1, j - 1) - ans(i, j) + ans(i - 1, j);
				else if(l0 < 0 && d0 > 0)	Ans += ans(i - 1, j) - ans(i, j) - ans(i - 1, j - 1) + ans(i, j - 1);
				else if(l0 < 0 && u0 < 0)	Ans += ans(i - 1, j - 1) - ans(i - 1, j) - ans(i, j - 1) + ans(i, j);
			}
		}
		Ans %= mod;
		(Ans += mod) %= mod;
		cout << Ans << '\n';
	}
}