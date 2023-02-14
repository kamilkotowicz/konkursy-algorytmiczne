//Kamil Kotowicz
#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,x;
vector<int> trasa;
vector<int> maxtrasa;
int odl=0;
bool odw[2000];
int maxodl=0;

int badany;
int nast[2001][2001],ilenast[2001];
vector<int>ODW(2001);
vector<int>ilepoprz(2001);
int wyniki[2001][2001];
#ifdef _WIN32
#define getc_unlocked getc
#endif
void dfs(int poz,vector<vector<int>>& graf)
{
	trasa.push_back(poz);
	++odl;
	odw[poz]=true;
	for(int i=0; i<graf[poz].size(); ++i)
	{
		int x=graf[poz][i];
		if(odw[x]==false)
		{
			dfs(x,graf);
		}
	}
	if(odl>maxodl)
	{
		maxodl=odl;
		maxtrasa.resize(0);
		for(int i=0; i<trasa.size(); ++i)
		{
			maxtrasa.push_back(trasa[i]);
		}
	}
	--odl;
	trasa.pop_back();
	odw[poz]=false;

}

void brut()
{
	//vector<int> trasa;
	//vector<int> maxtrasa;
	//int odl=0;
	//bool odw[2000];
	//int maxodl=0;
	vector<vector<int>> graf(n+1,vector<int>());
	for(int i=1; i<n; ++i)
	{
		for(int j=0; j<i; ++j)
		{
			cin>>x;
			if(x==1)
			{
				graf[j+1].push_back(i+1);
			}
			else
			{
				graf[i+1].push_back(j+1);
			}
		}
	}
	for(int i=1; i<=n; ++i)
	{
		int poz=i;
		odl=0;
		maxodl=0;
		dfs(poz,graf);
		cout<<maxodl<<" ";
		for(int j=0; j<maxtrasa.size(); ++j)
		{
			cout<<maxtrasa[j]<<" ";
		}
		cout<<endl;
	}
}
vector<int> szukaj(vector<int>ilepoprz,vector<int>trasa,vector<int>odw)
{
	while(badany!=-1)
	{
		trasa.push_back(badany);
		odw[badany]=1;
		int minx=-1,minw=2000000000;
		for(int i=0; i<ilenast[badany]; ++i)
		{
			int kolejny=nast[badany][i];
			if(odw[kolejny]==0)
			{
				--ilepoprz[kolejny];
				if(ilepoprz[kolejny]<minw)
				{
					minx=kolejny;
					minw=ilepoprz[kolejny];
				}
			}
		}
		badany=minx;
	}
	return trasa;
}
void heura()
{
	//int badany;
	//int nast[2001][2001],ilenast[2001];
	//vector<int>odw(2001);
	//vector<int>ilepoprz(2001),trasa;
	//int wyniki[2001][2001];
	srand(time(NULL));
	ios::sync_with_stdio(false);
	//cin>>n;
	for(int i=2; i<=n; ++i)
	{
		for(int j=1; j<i; ++j)
		{
			cin>>x;
			if(x==1)
			{
				nast[j][ilenast[j]]=i;
				++ilenast[j];
				++ilepoprz[i];
			}
			else
			{
				nast[i][ilenast[i]]=j;
				++ilepoprz[j];
				++ilenast[i];
			}
		}
	}
	//int dl=0;
znowu:
	trasa.resize(0);
	//++dl;
	//if(dl>n)return ;
	badany=rand()%n+1;
	while(ODW[badany]==true)
	{
		badany=rand()%n+1;
	}
	ODW[badany]==true;
	trasa=szukaj(ilepoprz,trasa,ODW);
	//int ts=trasa.size();
	//cout<<endl<<ts<<endl;
	if(trasa.size()!=n)goto znowu;
	int poc=trasa[0];
	int kon=trasa[trasa.size()-1];
	if(binary_search(nast[kon],nast[kon]+ilenast[kon],poc)==false)goto znowu;
	else
	{
		for(int i=0; i<n; ++i)
		{
			trasa.push_back(trasa[i]);
		}
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				wyniki[trasa[i]][j]=trasa[i+j];
			}
		}
		for(int i=1; i<=n; ++i)
		{
			cout<<n<<" ";
			for(int j=0; j<n; ++j)
			{
				cout<<wyniki[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	if(n<=11)brut();
	else heura();

}
