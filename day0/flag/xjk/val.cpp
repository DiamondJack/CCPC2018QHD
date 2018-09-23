#include <bits/stdc++.h>
using namespace std;
char buf[1005];
int main()
{
	for(int T,i=1;i<=2;i++)
	{
		sprintf(buf,"%d.in",i);
		FILE *fp=fopen(buf,"r");
		fscanf(fp,"%d",&T);
		if(T<1||T>50) puts("T wrong");
		for(int a,b,c,i=1;i<=T;i++)
		{
			fscanf(fp,"%d%d%d",&a,&b,&c);
			if(a<1||a>500000) puts("N wrong");
			if(b<1||b>500000) puts("M wrong");
			if(c<0||c>=1000000007) puts("seed wrong");
		}
		fclose(fp);
		printf("finish %d\n",i);
	}
}