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
	struct STnode{
		int l,r;
		int sum;int tag;
	} t[N*4];
	void PushUp(int x){
		t[x].sum=(t[x<<1].sum+t[x<<1^1].sum)%P;
	}
	void mult(int x,int k){
		t[x].tag=1LL*t[x].tag*k%P;
		t[x].sum=1LL*t[x].sum*k%P;
	}
	void PushDown(int x){
		if (t[x].l==t[x].r) t[x].tag=1;
		if (t[x].tag!=1){
			mult(x<<1,t[x].tag);
			mult(x<<1^1,t[x].tag);
			t[x].tag=1;
		}
	}
	void build(int x,int l,int r,int* seq){
		t[x].l=l;t[x].r=r;t[x].tag=1;
		if (l==r){
			t[x].sum=seq[l];
			return;
		}
		int mid=(l+r)/2;
		build(x<<1,l,mid,seq);
		build(x<<1^1,mid+1,r,seq);
		PushUp(x);
	}
	void multiply(int x,int l,int r,int k){
		PushDown(x);
		if (l<=t[x].l&&t[x].r<=r){mult(x,k);return;}
		int mid=(t[x].l+t[x].r)>>1;
		if (l<=mid) multiply(x<<1,l,r,k);
		if (r>mid) multiply(x<<1^1,l,r,k);
		PushUp(x);
	}
	int qsum(int x,int l,int r){
		PushDown(x);
		if (l<=t[x].l&&t[x].r<=r) return t[x].sum;
		int mid=(t[x].l+t[x].r)>>1;
		if (r<=mid) return qsum(x<<1,l,r);
		if (l>mid) return qsum(x<<1^1,l,r);
		return qsum(x<<1,l,r)+qsum(x<<1^1,l,r);
	}
} f,g;
// f[i]=pre(i)*pow(2,max(n-i-1,0))
// g[i]=inv(pre(i-1))*pow(2,max(i-2,0))
// ans=sum(g[j]*f[i]) 1<=j<=i<=n

int a[N],n;
bool isZero[N];
int ans;
int _f[N],_g[N];
void init(){
	int sg=0;
	a[0]=1;
	_f[0]=fast_pow(2,n-1);
	_g[0]=1;
	for (int i=1;i<=n;++i){
		_f[i]=1LL*_f[i-1]*a[i]%P;
		if (i+1<=n) _f[i]=1LL*_f[i]*inv2%P;
		_g[i]=1LL*_g[i-1]*inv(a[i-1])%P;
		if (i>2) _g[i]=2LL*_g[i]%P;
		inc(sg,_g[i]);
		if (isZero[i]) sg=0;
		inc(ans,1LL*sg*_f[i]);
	}
	f.build(1,1,n,_f);
	g.build(1,1,n,_g);
}

set<int> zero;
void modify(int x,int val){
	if (val==0&&isZero[x]) return;
	int u=*(--zero.lower_bound(x));
	int v=*zero.upper_bound(x);
	if (val==0){
		dec(ans,1LL*f.qsum(1,x,v-1)*g.qsum(1,u+1,x));
		isZero[x]=true;
		zero.insert(x);
	}
	else if (isZero[x]){
		f.multiply(1,x,n,inv(a[x])*val);
		g.multiply(1,x+1,n,a[x]*inv(val));
		inc(ans,1LL*f.qsum(1,x,v-1)*g.qsum(1,u+1,x));
		isZero[x]=false;
		zero.erase(zero.find(x));
		a[x]=val;
	}
	else{
		dec(ans,1LL*f.qsum(1,x,v-1)*g.qsum(1,u+1,x));
		f.multiply(1,x,n,inv(a[x])*val);
		g.multiply(1,x+1,n,a[x]*inv(val));
		inc(ans,1LL*f.qsum(1,x,v-1)*g.qsum(1,u+1,x));
		a[x]=val;
	}
}

int main(){
	scanf("%d",&n);
	zero.clear();
	zero.insert(0);zero.insert(n+1);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		if (a[i]==0){
			a[i]=1;
			isZero[i]=true;
			zero.insert(i);
		}
		else isZero[i]=false;
	}
	init();
	printf("%d\n",ans);

	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,val;
		scanf("%d%d",&x,&val);
		modify(x,val);
		printf("%d\n",ans);
	}
	return 0;
}
