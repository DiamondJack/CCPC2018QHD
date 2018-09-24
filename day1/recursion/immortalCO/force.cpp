#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
map<pair<int,int>, pair<bool,bool>> rec;

bool debug, notable;
long long X,Y,Z;
long long F(long long x, long long y, int d) {
	#if 0
	// if(!notable) printf("%lld %lld %d\n",x,y,d);
	if(!notable && d >= 8) return 0;
	if(d && d % 8 == 0) {
		long long D = 4;
		long long wx = (X>>D);// + ((X>>D<<D)!=X);
		long long wy = (Y>>D);// + ((Y>>D<<D)!=Y);
		int aa = int((X>>(D-4))&15) + ((X>>D)&1)*16;
		int bb = int((Y>>(D-4))&15) + ((Y>>D)&1)*16;
		rec[make_pair(aa,bb)] = make_pair(bool(x-wx),bool(y-wy));
		// printf("%02X%02X -> %lld%lld\n",aa,bb, x-wx, y-wy);
		if(debug) printf("f %lld %lld %lld %lld\n",x,y,wx,wy);
		// assert(x==wx && y==wy);
		X=x;Y=y;
	}
	//printf("#%d:\t(%d\t%d\t)\t%d%d\t%d\t[%c]\n",d,x,y,x&1,y&1,((x ^ y) & 1), " *"[x>=0&&y>=0]); 
	//printf("%d%d -> %d%d\n", (x&3),(y&3), ((x - y) >> 1)&1, ((x + y) >> 1)&1);
	#endif
	if(!x && !y) return 0;
	long long ans = 2 * F(- ((x - y) >> 1), - ((x + y) >> 1), d + 1) + ((x ^ y) & 1);	
	ans %= mod;
	if(d%8==0 && debug) printf("ret f(%lld, %lld) = %lld\n",x,y,ans%256);
	return ans;
}
long long f(long long x,long long y){
	X=x;Y=y;Z=0;return F(x,y,0);
}

long long rndll() {
	return (rand() % 10000000) * 10000000ll + rand() % 10000000;
}

int pre[16][16];
long long g(long long a, long long b) {
	long long ans = 0, bit = 1;
	while(a || b) {
		int x = a & 15, y = b & 15;
		(ans += pre[x][y] * bit) %= mod;
		(bit *= 256) %= mod;
		//printf("%lld %lld\n",a,b);
		pair<bool, bool> p = rec[make_pair(int(a & 31), int(b & 31))];
		a = (a >> 4) + p.first;
		b = (b >> 4) + p.second;
	}
	return ans;
}

int main() {
	// for(int a = 0; a < 16; ++a)
	// 	for(int b = 0; b < 16; ++b) {
	// 		pre[a][b] = f(a, b);
	// 		assert(pre[a][b]<256);
	// 		// printf("%02X", pre[a][b]);
	// 	}
	// puts("");
	notable=1;
	// for(int i=1;;++i) {
	// 	if(rec.size() >= 1024u) break;
	// 	f(rndll(), rndll());
	// }
	// for(int a = 0; a < 16; ++a)
	// 	for(int b = 0; b < 16; ++b) {
	// 		int o = 0;
	// 		for(int c=0;c<=1;++c)for(int d=0;d<=1;++d) {
	// 			auto x = rec[make_pair(a+c*16,b+d*16)];
	// 			if(!a) assert(!x.first);
	// 			if(!b) assert(!x.second);
	// 			int v=x.second*2+x.first;
	// 			o += v << (2 * (c*2+d));
	// 		}
	// 		assert(o<256);
	// 		printf("%02X", o);
	// 	}
	// puts("");
	// // for(auto x : rec) printf("%X", x.second.second<<1|x.second.first);
	// // puts("");
	// // return 0;
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// long long a,b;
	// while(cin>>a>>b) {
	// 	cout<<f(a,b)<<endl;
	// }
	// return 0;
	
	//cout << f(101,100) << endl << g(101,100) << endl;
	//debug=1;
	// for(int i=1;i<=100000;++i) {
	// 	long long x=rndll()-5e13,y=rndll()-5e13;
	// 	printf("#%d: %lld %lld %lld %lld\n",i,x,y,f(x,y),g(x,y));
	// 	//break;
	// 	assert(f(x,y)==g(x,y));
	// }
	/*for(int i=1;i<=100000;++i) {
		// if(rec.size() >= 1024u) break;
		f(rndll(), rndll());
	}
	for(auto x : rec) printf("%02X%02X -> %d%d\n",x.first.first,x.first.second,x.second.first,x.second.second);*/
	// f(5464545688121,465847123246778445);
	// f(3,1000000);
	// f(1000,1000);
	// for(int i=-1;i<=1;++i) {
	// 	for(int j=-1;j<=1;++j)
	// 		// f(i,j);
	// 		cout << f(i,j) << ' ';
	// 	cout<<endl;
	// }
	// long long a, b;
	int T;
	cin >> T;
	long long l, r, s, t;
	while (T--) {
		long long ans=0;
		for(long long x = l; x <= r; ++x)
			for(long long y = s; y <= t; ++y) {
				//printf("f(%lld, %lld) = %lld\n",x,y,f(x,y));
				(ans += f(x,y)) %= mod;
			}
		cout<<ans<<endl;
	}
}
