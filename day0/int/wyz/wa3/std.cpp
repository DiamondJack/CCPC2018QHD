#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	freopen("int.in","r",stdin);
	freopen("int.out","w",stdout);
	int n;
	ll tmp,mn=1LL<<50,mx=-mn;
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<=n;++i){
		scanf("%lld",&tmp);
		if (tmp<=mn) mn=tmp,x=i;
		if (tmp>=mx) mx=tmp,y=i;
	}
	printf("%lld %d %d\n",mx-mn,x,y);
	return 0;
}

