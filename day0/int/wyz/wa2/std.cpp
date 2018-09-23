#include <bits/stdc++.h>
#define ll unsigned int

using namespace std;


int main(){
	freopen("int.in","r",stdin);
	freopen("int.out","w",stdout);
	int n;
	ll tmp,mn=-1,mx=0;
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<=n;++i){
		scanf("%u",&tmp);
		if (tmp<mn) mn=tmp,x=i;
		if (tmp>=mx) mx=tmp,y=i;
	}
	printf("%u %d %d\n",mx-mn,x,y);
	return 0;
}

