#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

const int _K=50268147,_B=6082187,_P=100000007;
int _X;
inline int get_rand(int _l,int _r){
	_X=((long long)_K*_X+_B)%_P;
	return _X%(_r-_l+1)+_l;
}
int n,m,seed;
int c[N];
void Init(){
	scanf("%d%d%d",&n,&m,&seed);
	_X=seed;
	for (int i=1;i<=n;++i)
		c[i]=get_rand(1,m);
}

void print(){
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;++i) printf("%d ",c[i]);puts("");
}


ll sum[N],cnt[N],sum2[N];

void work(){
	ll ans=0;
	memset(cnt,0,sizeof(cnt));
	memset(sum,0,sizeof(sum));
	memset(sum2,0,sizeof(sum2));
	for (int i=1;i<=n;++i){
		ans+=cnt[c[i]]*i*i-2LL*sum[c[i]]*i+sum2[c[i]];
		++cnt[c[i]];
		sum[c[i]]+=i;
		sum2[c[i]]+=1LL*i*i;
	}
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while (T--){
		Init();
//		print();
		work();
	}
	return 0;
}
