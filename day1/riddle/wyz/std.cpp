#include <bits/stdc++.h>

using namespace std;
const int N=16;
const int M=(1<<16);
typedef long long ll;
inline int bin(int x){return (1<<x);}
inline int lowbit(int x){return x&-x;}
#define pb push_back
inline vector<int> subset(int s){
	vector<int> ret,bits;
	for (;s;s^=lowbit(s)) bits.pb(lowbit(s));
	for (int mask=bin(bits.size())-1;mask>=0;--mask){
		int now=0;
		for (int i=int(bits.size())-1;i>=0;--i)if (mask&bin(i))
			now^=bits[i];
		ret.pb(now);
	}
	return ret;
}
int n;
int a[N];
ll dp[M],f[M];
int sum[M];
void work(){
	scanf("%d",&n);
	assert(0<=n&&n<=15);
	for (int i=0;i<n;++i){
		scanf("%d",a+i);
		assert(0<=a[i]&&a[i]<=2000);
	}
	memset(sum,0,sizeof(sum));
	for (int mask:subset(bin(n)-1))
		for (int i=0;i<n;++i)if (mask&bin(i))
			sum[mask]+=a[i];
	ll ans=0;
	memset(f,0,sizeof(f));
	for (int riddle:subset(bin(n)-1)){
		// if (riddle%1000==0) printf("%d\n",riddle);
		// printf("%d\n",riddle);
		int item=((bin(n)-1)^riddle);
		vector<int> ss=subset(item);
		for (int mask:ss) dp[mask]=0;
		dp[0]=1;
		for (int i=0;i<n;++i)if (riddle&bin(i)){
			for (int now:ss)if (sum[now]==a[i]){
				for (int mask:subset(item^now)){
					// printf("sum[%d]==a[%d]\n",now,a[i]);
					f[mask^now]+=dp[mask];
				}
			}
			for (int mask:ss){
				dp[mask]=f[mask];
				f[mask]=0;
			}
		}
		for (int mask:ss) ans+=dp[mask];
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	assert(0<=T&&T<=5);
	for (int i=0;i<T;++i){
		work();
	}
	return 0;
}
