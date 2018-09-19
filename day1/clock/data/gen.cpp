#include<cstdio>
#include<algorithm>
using namespace std;
int w[1000];
int a[1000],b[1000];
int main()
{
	int i,j,c=0,k;
	FILE* inp=fopen("1.in","w");
	FILE* oup=fopen("1.ans","w");
	for(i=0;i<=24;++i)
		for(j=i+1;j<=24;++j)
		{
			++c;
			a[c]=i;
			b[c]=j;
			w[c]=c;
		}
	random_shuffle(w+1,w+c+1);
	fprintf(inp,"%d\n",c);
	for(i=1;i<=c;++i)
	{
		int ans=0;
		fprintf(inp,"%d %d\n",a[w[i]],b[w[i]]);
		for(j=a[w[i]];j<b[w[i]];++j)
			if(j!=11&&j!=23)
				++ans;
		fprintf(oup,"%d\n",ans);
	}
	fclose(inp);
	fclose(oup);
	return 0;
} 
