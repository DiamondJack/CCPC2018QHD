#include <bits/stdc++.h>
#define N 2003
#define ll long long

using namespace std;



const int inf=1e9;

int m,b[N];

void get_b(int _m){
	m=_m;
	for (int i=1;i<=m;++i) b[i]=rand()%inf+1;
}

int n,a[N];


void get_a_0(){
	sort(a+1,a+n+1,greater<int>());
}

void get_a_1(){
	for (int i=rand()%(2*n);i;--i){
		int x=rand()%(n-1)+1;
		swap(a[x],a[x+1]);
	}
}

void get_a_2(){}


int Q;

void get_q_0(){
	int lb=rand()%(int)sqrt(n)+2;
	int rb=n-rand()%(int)sqrt(n)-1;
	for (int i=1;i<=Q;++i){
		int l=lb+rand()%(rb-lb+1);
		int r=lb+rand()%(rb-lb+1);
		if (i>=Q*17/18) l=rand()%n+1,r=rand()%n+1;
		if (l>r) swap(l,r);
		printf("%d %d\n",l,r);
	}
}

void get_q_1(){
	for (int i=1;i<=Q;++i){
		int len=1;
		if (rand()%100){
			++len;
			while (len<n&&rand()%30) ++len;
		}
		int l=rand()%(n-len+1)+1,r=l+len-1;
		printf("%d %d\n",l,r);
	}
}


int main(){
	srand((unsigned int)time(0));
	const int maxn=2000;
	const int maxQ=1e6;
	char fname[23];
	int testcase=18;
	for (int T=1;T<=testcase;++T){
		sprintf(fname,"data/%d.in",T);
		freopen(fname,"w",stdout);
		n=maxn-rand()%2*rand()%66;
		Q=maxQ-rand()%2*rand()%233;
		printf("%d\n",n);
		if (T%9/3==0) get_b(n);
		if (T%9/3==1) get_b(rand()%n+1);
		if (T%9/3==2) get_b(rand()%(int)pow(n,2.0/3.0)+1);
		
		for (int i=1;i<=n;++i) a[i]=b[rand()%m+1];
		if (T%9%3==0) get_a_0();
		if (T%9%3==1) get_a_1();
		if (T%9%3==2) get_a_2();
		
		for (int i=1;i<n;++i) printf("%d ",a[i]);
		printf("%d\n",a[n]);
		
		printf("%d\n",Q);
		if (T/9) get_q_0();
		else get_q_1();
	}
	return 0;
}
