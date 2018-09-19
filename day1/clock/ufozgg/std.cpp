#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b,ans,i;
	for(scanf("%d",&t);t;--t)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		for(i=a;i<b;++i)
			if(i!=11&&i!=23)
				++ans;
		printf("%d\n",ans);
	}
	
	return 0;
} 
