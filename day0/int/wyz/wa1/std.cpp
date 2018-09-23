#include <bits/stdc++.h>
#define ll int

using namespace std;


int main(){
	freopen("int.in","r",stdin);
	freopen("int.out","w",stdout);
	int n;
	ll tmp,mn=2147483647,mx=-2147483648;
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<=n;++i){
		scanf("%d",&tmp);
		if (tmp<mn) mn=tmp,x=i;
		if (tmp>=mx) mx=tmp,y=i;
	}
	printf("%d %d %d\n",mx-mn,x,y);
	return 0;
}

