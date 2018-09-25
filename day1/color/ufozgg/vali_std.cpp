#include<cstdio>
#include<cassert>
#include<cstring>
#include<string>
#include<iostream>
using namespace std; 
int t,len;
char w[1000];
void solve()
{
	int i[3],j[3],k,s;
	string rlt="";
	string person[3]={"alice","bob","yazid"};
	string Person[3]={"Alice","Bob","Yazid"};
	string color[3]={"blue","green","red"};
	for(i[0]=0;i[0]<3;++i[0])
	for(i[1]=0;i[1]<3;++i[1])
	for(i[2]=0;i[2]<3;++i[2])
	if(i[1]!=i[0]&&i[0]+i[1]+i[2]==3)
	for(j[0]=0;j[0]<3;++j[0])
	for(j[1]=0;j[1]<3;++j[1])
	for(j[2]=0;j[2]<3;++j[2])
	if(j[1]!=j[0]&&j[0]+j[1]+j[2]==3)
	{
		string ans="",cmp="";
		for(k=0;k<3;++k)
		{
			ans+=Person[i[k]]+" is "+color[j[k]]+".";
			cmp+=person[i[k]]+"is"+color[j[k]];
		}
		s=0;
		for(k=0;k<len&&s<cmp.size();++k)
			if(w[k]==cmp[s])
				++s;
		if(s==cmp.size())
		{
			if(rlt>ans||rlt=="")
				rlt=ans;
		}
	}
	if(rlt=="")
		cout<<"No solution."<<endl;
	else
		cout<<rlt<<endl;
}
int main()
{
	int i,j;
	scanf("%d\n",&t);
	assert(t<=500);
	for(;t;--t)
	{
		gets(w);
		len=strlen(w);
		assert(len<=600);
		for(i=0;i<len;++i)
			assert('a'<=w[i]&&w[i]<='z');
		solve();
	}
	return 0;
} 
