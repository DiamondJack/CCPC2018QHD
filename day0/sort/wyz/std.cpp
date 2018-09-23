#include <bits/stdc++.h>
#define N 2003

using namespace std;
inline int read(){
	int ret=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while ('0'<=ch&&ch<='9'){
		ret=ret*10-48+ch;
		ch=getchar();
	}
	return ret;
}

int n;
int a[N];
typedef set<int> set0;

set0 s;


int main(){
	s.clear();
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=1;i<n;++i)
		if (a[i]>a[i+1]) s.insert(i);
	s.insert(n);
	for (int Q=read();Q--;){
		int l=read(),r=read();
		for (set0::iterator it=s.lower_bound(l);(*it)<r;it=s.lower_bound(l)){
			int pos=*it;
			s.erase(it);
			swap(a[pos],a[pos+1]);
			if (pos>1&&a[pos-1]<=a[pos+1]&&a[pos-1]>a[pos])  s.insert(pos-1);
			if (pos+1<n&&a[pos]<=a[pos+2]&&a[pos+1]>a[pos+2])s.insert(pos+1);
		}
	}
	for (int i=1;i<n;++i) printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}

