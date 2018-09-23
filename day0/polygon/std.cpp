#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
 
typedef double db;

const int MAX_N = 300 + 10;
 
const db EPS = 1e-8;
 
inline int sign(db a) {
    return a < -EPS ? -1 : a > EPS;
}
 
inline int cmp(db a, db b){
    return sign(a-b);
}
 
struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) { return P(x + p.x, y + p.y); }
    P operator-(P p) { return P(x - p.x, y - p.y); }
    P operator*(db d) { return P(x * d, y * d); }
    P operator/(db d) { return P(x / d, y / d); }
    bool operator<(P p) const { 
        int c = cmp(x, p.x);
        if (c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    db dot(P p) { return x * p.x + y * p.y; }
    db det(P p) { return x * p.y - y * p.x; }
    db distTo(P p) { return (*this-p).abs(); }
    db alpha() { return atan2(y, x); }
    void read() { cin>>x>>y; }
    db abs() { return sqrt(abs2());}
    db abs2() { return x * x + y * y; }
    P rot90() { return P(-y,x);}
    P unit() { return *this/abs(); }
    int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

P isLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1 * a2 + p2 * a1) / (a1 + a2);
}

db area(vector<P> ps){
    db ret = 0; rep(i,0,ps.size()) ret += ps[i].det(ps[(i+1)%ps.size()]); 
    return abs(ret/2);
}

vector<P> convexHull(vector<P> ps) {
    int n = ps.size(); if(n <= 1) return ps;
    sort(ps.begin(), ps.end());
    vector<P> qs(n * 2); int k = 0;
    for (int i = 0; i < n; qs[k++] = ps[i++]) 
        while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
        while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
    qs.resize(k - 1);
    return qs;
}

vector<P> convexCut(const vector<P>&ps, P q1, P q2) {
    vector<P> qs;
    int n = ps.size();
    rep(i,0,n){
        P p1 = ps[i], p2 = ps[(i+1)%n];
        int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
        if(d1 >= 0) qs.pb(p1);
        if(d1 * d2 < 0) qs.pb(isLL(p1,p2,q1,q2));
    }
    return qs;
}

db intersect(vector<P> ps, vector<P> qs){
    rep(i,0,qs.size())
        ps = convexCut(ps,qs[i],qs[(i+1)%qs.size()]);
    return area(ps);
}

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    vector<P> ps(n);
    rep(i,0,n) ps[i].read();

    vector<pair<int,int> > segments;

    vector<vector<P> > polys;

    static db new_add[MAX_N][MAX_N];

    rep(i,0,m){
        int l,r;cin>>l>>r;
        segments.pb({l,r});
    }

    sort(segments.begin(), segments.end());
    m = segments.size();
    k = min(k,(int)segments.size());

    rep(i,0,m){
        vector<P> qs;
        for(auto p : ps){
            qs.pb(p * segments[i].fi);
            qs.pb(p * segments[i].se);
        }
        qs = convexHull(qs);
        polys.pb(qs);
    }

    rep(i,0,m) rep(j,i+1,m){
        new_add[i][j] = area(polys[j]) - intersect(polys[i],polys[j]);
    }

    static db dp[MAX_N][MAX_N];//i,cnt

    rep(i,0,m) rep(j,0,m+1) dp[i][j] = -1;

    rep(i,0,m) dp[i][1] = area(polys[i]);

    rep(i,0,m) rep(j,0,m) if(dp[i][j] > -0.5){
        db u = dp[i][j];
        rep(k,i+1,m)
            dp[k][j+1] = max(dp[k][j+1],u + new_add[i][k]);
    }

    db ans = 0; rep(i,0,m) ans = max(ans,dp[i][k]);
    
    printf("%0.10f\n",ans);

    return 0;
}