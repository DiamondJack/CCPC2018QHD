#include <bits/stdc++.h>
#define N 2005

using namespace std;

int n,a[N];

pair<int,int> q[N*N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	int Q;
	scanf("%d",&Q);
	for (int i=1;i<=Q;++i)
		scanf("%d%d",&q[i].first,&q[i].second);
	sort(q+1,q+Q+1);
	int l=q[1].first,r=q[1].second;
	for (int i=2;i<=Q;++i){
		if (q[i].first>l){
			sort(a+l+1,a+r+1);
			l=q[i].first;
		}
		r=max(r,q[i].second);
	}
	for (int i=1;i<n;++i) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
