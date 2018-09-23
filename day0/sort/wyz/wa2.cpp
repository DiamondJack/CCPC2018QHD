#include <bits/stdc++.h>
#define N 2005

using namespace std;

int n,a[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	int Q;
/*	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		sort(a+l+1,a+r+1);
	}*/
	sort(a+1,a+n+1);
	for (int i=1;i<n;++i) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
