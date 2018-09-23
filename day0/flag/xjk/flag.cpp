#include <bits/stdc++.h>
using namespace std;
const int _K=50268147,_B=6082187,_P=100000007;
int _X;
inline int get_rand(int _l,int _r){
	_X=((long long)_K*_X+_B)%_P;
	return _X%(_r-_l+1)+_l;
}
int n,m,seed;
int c[500001];
void Init(){
	scanf("%d%d%d",&n,&m,&seed);
	_X=seed;
	for (int i=1;i<=n;++i)
		c[i]=get_rand(1,m);
}
long long num[500005],num1[500005],num2[500005];
int main()
{
	//freopen("tt.in","r",stdin);
	int T;
	for(cin>>T;T--;)
	{
		Init();
		memset(num,0,sizeof(num));
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			ans+=num[c[i]]*i*i;num[c[i]]++;
			ans-=2*num1[c[i]]*i;num1[c[i]]+=i;
			ans+=num2[c[i]];num2[c[i]]+=i*i;
		}
		cout<<ans<<endl;
	}
}