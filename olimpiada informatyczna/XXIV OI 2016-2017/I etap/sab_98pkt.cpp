//Kamil Kotowicz
#include<iostream>
#include<vector>
#include <cstring>
#include<iomanip>
using namespace std;
void dfs(int x,int rodzic,vector<vector<int>>& graf,vector<int>& podwl)
{
	int gs=graf[x].size();
	for(int i=0; i<gs; ++i)
	{
		dfs(graf[x][i],x,graf,podwl);
	}
	if(rodzic!=-1)podwl[rodzic]+=podwl[x]+1;
}
void dfs2(int x,vector<vector<int>>& graf,vector<int>& podwl,vector<int>& bunt,vector<int>& dolacz,double morale)
{
	if(x==0)
	{
		bunt[x]=1;
		dolacz[x]=podwl[x]+1;
	}
	double d=podwl[x];
	for(int i=0; i<graf[x].size(); ++i)
	{
		int syn=graf[x][i];
		double d2=(double)podwl[syn]+1;
		if(1.0/d>morale)
		{
			bunt[syn]=dolacz[x];
		}
		else
		{
			bunt[syn]=1;
		}
		if(d2/d>morale)
		{
			dolacz[syn]=dolacz[x];
		}
		else
		{
			dolacz[syn]=d2;
		}
		dfs2(syn,graf,podwl,bunt,dolacz,morale);
	}

}
vector<int> podwl(500000,0);
vector<int> bunt(500000,0);
vector<int> dolacz(500000,0);
vector<int>rodzice(500000,0);
int n,k,x,maxk;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	vector<vector<int>> graf(n,vector<int>());
	for(int i=1; i<n; ++i)
	{
		cin>>x;
		graf[x-1].push_back(i);
	}
	dfs(0,-1,graf,podwl);
	double poc=0;
	double kon=1;
	double morale=-1.0;
	while(poc<=kon)
	{
		morale=(poc+kon)/2;
		for(int it=0; it<n; ++it)
		{
			bunt[it]=0;
			dolacz[it]=0;
		}
		dfs2(0,graf,podwl,bunt,dolacz,morale);
		maxk=-1;
		for(int i=0; i<n; ++i)
		{
			if(bunt[i]>maxk)maxk=bunt[i];
			if(maxk>k)break;
		}
		if(maxk>k)
		{
			poc=morale+0.0000005;
		}
		else
		{
			kon=morale-0.0000005;
		}
	}
	cout<<fixed<<setprecision(8)<<morale<<endl;
}
