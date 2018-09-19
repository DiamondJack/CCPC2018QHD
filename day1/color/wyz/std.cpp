#include <bits/stdc++.h>

using namespace std;

string st;
int n;
string name[3]={"alice","bob","yazid"};
string Name[3]={"Alice","Bob","Yazid"};
string color[3]={"red","green","blue"};

vector<string> ans;

void work(){
	cin>>st;
	n=st.length();
	int a[3]={0,1,2};
	ans.clear();
	do{
		int b[3]={0,1,2};
		do{
			// printf("%d %d %d    %d %d %d\n",a[0],a[1],a[2],b[0],b[1],b[2]);
			string tmp="";
			string res="";
			for (int i=0;i<3;++i){
				tmp+=name[a[i]]+"is"+color[b[i]];
				res+=Name[a[i]]+" is "+color[b[i]]+".";
			}
			int m=tmp.length();
			int j=0;
			for (int i=0;i<n&&j<m;++i){
				if (st[i]==tmp[j])
					++j;
			}
			// cout<<res<<' '<<j<<endl;
			if (j==m) ans.push_back(res);
		} while (next_permutation(b,b+3));
	} while (next_permutation(a,a+3));
	if (int(ans.size())==0){
		puts("No solution.");
	}
	else{
		sort(ans.begin(),ans.end());
		cout<<*ans.begin()<<endl;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while (T--) work();
	return 0;
}
