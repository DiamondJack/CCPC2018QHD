#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef double db;
 
const db EPS = 1e-8;
 
inline int sign(db a) {
    return a < -EPS ? -1 : a > EPS;
}
 
inline int cmp(db a, db b){
    return sign(a-b);
}

struct P {
    db x, y;
    P operator+(P p) { return {x + p.x, y + p.y}; }
    P operator-(P p) { return {x - p.x, y - p.y}; }
    P operator*(db d) { return {x * d, y * d}; }
    P operator/(db d) { return {x / d, y / d}; }
    bool operator<(P p) const { 
        int c = cmp(x, p.x);
        if (c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    db dot(P p) { return x * p.x + y * p.y; }
    db det(P p) { return x * p.y - y * p.x; }
    db distTo(P p) { return (*this-p).abs(); }
    db alpha() const { return atan2(y, x); }
    void read() { cin>>x>>y; }
    db abs() { return sqrt(abs2());}
    db abs2() { return x * x + y * y; }
    P rot90() { return {-y,x};}
    P unit() { return *this/abs(); }
    int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

int n,m,k;

db area(vector<P> ps){
    db ret = 0; rep(i,0,ps.size()) ret += ps[i].det(ps[(i+1)%ps.size()]); 
    return ret/2;
}

int main(int argc,char*argv[]){
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	k = atoi(argv[3]);

	int R = atoi(argv[4]);

	int L = atoi(argv[5]);

	cout<<n<<" "<<m<<" "<<k<<endl;

	assert(n % 2 == 0);

	vector<P> vec;
	rep(i,0,n/2){
		for(;;){
			int x = rand() % 21 - 10;
			int y = rand() % 21 - 10;			
			if(!x && !y) continue;
			vec.pb({x,y});
			vec.pb({-x,-y});
			break;
		}
	}

	sort(vec.begin(), vec.end(),[](P a, P b){ return a.alpha() < b.alpha(); } );

	P st = {0,0};
	vector<P> ps = {st};

	rep(i,0,vec.size() - 1){
		st = st + vec[i];
		ps.pb(st);
	}

	db min_x = 1e100,min_y = 1e100;
	for(auto p : ps)
		min_x = min(min_x,p.x), min_y = min(min_y,p.y);

	for(auto& p : ps)
		p.x -= min_x - 1, p.y -= min_y - 1;

	rep(i,0,n)
		printf("%d %d\n",(int)(round(ps[i].x)),(int)(round(ps[i].y)) );

	rep(i,0,m){
		int x = rand() % R + 1;
		printf("%d %d\n",x,x*2);
	}
	return 0;
}