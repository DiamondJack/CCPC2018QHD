#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
	int n;
	ll tmp,mn=1LL<<50,mx=-mn;
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<=n;++i){
		scanf("%lld",&tmp);
		if (tmp>mx) mx=tmp,x=i;
		if (tmp<mn) mn=tmp,y=i;
	}
	printf("%lld %d %d\n",mx-mn,x,y);
	return 0;
}

