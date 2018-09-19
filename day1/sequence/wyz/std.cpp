#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int P=998244353;
int fast_pow(int x,int y,int mod=P){
	int ret=1;
	while (y){
		if (y&1) ret=1LL*ret*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return ret;
}
int inv(int x,int mod=P){
	return fast_pow(x,mod-2);
}
void inc(int &x,int y){
	if ((x+=y)>=P) x-=P;
}
void inc(int &x,ll y){
	x=(x+y)%P;
}
void dec(int &x,int y){
	if ((x-=y)<0) x+=P;
}
void dec(int &x,ll y){
	if ((x=(x-y)%P)<0) x+=P;
}
const int inv2=(P+1)>>1;


const int N=200005;

struct SegmentTree{
} f,g;
// f[i]=pre(i)*pow(2,max(n-i-1,0))
// g[i]=inv(pre(i-1))*pow(2,max(i-2,0))
// ans=sum(g[j]*f[i]) 1<=j<=i<=n

int a[N],n;
int ans;
int _f[N],_g[N];
void init(){
	int sg=0;
	a[0]=1;
	_f[0]=fast_pow(2,n-2);
	_g[0]=1;
	for (int i=1;i<=n;++i){
		_f[i]=1LL*_f[i-1]*a[i]%P;
		if (n<i+1) _f[i]=1LL*_f[i]*inv2%P;
		_g[i]=1LL*_g[i-1]*inv(a[i-1])%P;
		if (i>2) _g[i]=2LL*_g[i]%P;
		inc(sg,_g[i]);
		inc(ans,1LL*sg*_f[i]);
	}
	f.build(1,1,n,_f);
	g.build(1,1,n,_g);
}

int modify(int x,int val){
	dec(ans,f.qsum(1,x,n)*g.qsum(1,1,x));
	f.multiply(1,x,n,inv(a[x])*val);
	g.multiply(1,x+1,n,a[x]*inv(val));
	inc(ans,f.qsum(1,x,n)*g.qsum(1,1,x));
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i);
	init();
	printf("%d\n",ans);

	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,val;
		scanf("%d%d",&x,&val);
		printf("%d\n",modify(x,val));
	}
	return 0;
}
