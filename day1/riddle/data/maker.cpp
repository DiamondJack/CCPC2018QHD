#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define N 15
using namespace std;
inline int read()
{
	int num=0,sgn=1;
	char ch=getchar();
	while (ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if (ch=='-')sgn=-1,ch=getchar();
	while (ch>='0'&&ch<='9')num*=10,num+=ch-'0',ch=getchar();
	return num*sgn;
}
int n,a[N+1];
char in[20];
void Fibonacci()
{
	a[1]=rand()%3+1;a[2]=rand()%3+1;
	for (int i=3;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
}
void Two()
{
	a[1]=rand()%10+1;a[2]=rand()%10+1;
	while (a[1]==a[2])a[2]=rand()%10+1;
	for (int i=3;i<=n;i++)
		if (i%2)a[i]=a[1];
		else a[i]=a[2];
}
void Three()
{
	a[1]=rand()%10+1;a[2]=rand()%10+1;
	while (a[1]==a[2])a[2]=rand()%10+1;
	a[3]=a[1]+a[2];
	for (int i=4;i<=n;i++)
		if (i%3==1)a[i]=a[1];
		else if (i%3==2)a[i]=a[2];
		else a[i]=a[3];
}
void Plus()
{
	a[1]=rand()%5+1;a[2]=rand()%5+1;
	while (a[1]==a[2])a[2]=rand()%5+1;
	for (int i=3;i<=n;i++)
		a[i]=a[rand()%(i-1)+1]+a[rand()%(i-1)+1];
}
void Random()
{
	for (int i=1;i<=n;i++)
		a[i]=rand()%10+1;
}
int main()
{
	srand(time(NULL));
	for (int test_case=1;test_case<=15;test_case++)
	{
		sprintf(in,"%d.in",test_case);
		freopen(in,"w",stdout);
		printf("5\n");
		n=test_case;
		for (int T=1;T<=5;T++)
		{
			printf("%d\n",n);
			if (T==1)Fibonacci();
			if (T==2)Two();
			if (T==3)Three();
			if (T==4)Plus();
			if (T==5)Random();
			random_shuffle(a+1,a+n+1);
			for (int i=1;i<=n;i++)
				printf("%d%c",a[i],(i==n)?'\n':' ');
		}
		fclose(stdout);
	}
	return 0;
}

