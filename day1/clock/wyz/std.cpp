#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int a,b;
		if (scanf("%d%d",&a,&b)==EOF){
			cerr<<"Unexpected EOF"<<endl;
			return 0;
		}
		int ans=b-a;
		if (a<=11&&b>=12) --ans;
		if (a<=23&&b==24) --ans;
		printf("%d\n",ans);
		assert(0<=a&&a<b&&b<=24);
	}
	assert(scanf("%d",&T)==EOF);
	return 0;
}
