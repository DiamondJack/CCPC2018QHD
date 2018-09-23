#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int a,b;
		scanf("%d%d",&a,&b);
		int ans=b-a;
		if (a<=11&&b>=12) --ans;
		if (a<=23&&b==24) --ans;
		printf("%d\n",ans);
	}
	return 0;
}
