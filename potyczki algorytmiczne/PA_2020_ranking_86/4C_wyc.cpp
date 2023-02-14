#include <bits/stdc++.h>
using namespace std;
const int mx=2005;
const int maxk=1e6+3;
int n,m,k,nr;
long long a,b,dobre,zle;
string s[mx];
int dp[mx][mx],odw[mx][mx];
vector<long long>v;
vector<pair<pair<int,int>,int>>kolejka[2];
long long minx,ile,akt;
void oblicz(){
    nr=0;
    kolejka[nr].push_back({{n-1,m-1},0});
    while(kolejka[0].size()>0||kolejka[1].size()>0){
        for(int i=0;i<kolejka[nr].size();++i){
            int x=kolejka[nr][i].first.first;
            int y=kolejka[nr][i].first.second;
            int z=kolejka[nr][i].second;
            if(odw[x][y])continue;
            odw[x][y]=1;
            dp[x][y]=z;
            if(x-1>=0&&s[x-1][y]!='X'&&odw[x-1][y]==0)kolejka[nr].push_back({{x-1,y},z});
            if(y-1>=0&&s[x][y-1]!='X'&&odw[x][y-1]==0)kolejka[nr].push_back({{x,y-1},z});
            if(x+1<n&&s[x+1][y]!='X'&&odw[x+1][y]==0)kolejka[1-nr].push_back({{x+1,y},z+1});
            if(y+1<m&&s[x][y+1]!='X'&&odw[x][y+1]==0)kolejka[1-nr].push_back({{x,y+1},z+1});
        }
        kolejka[nr].clear();
        nr=1-nr;
    }
    zle=dp[0][0];
    dobre=zle+n+m-2;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    oblicz();
    minx=LONG_LONG_MAX;
    ile=0;
    for(int i=0;i<k;++i){
        cin>>a>>b;
        akt=dobre*a+zle*b;
        if(akt<minx){
            minx=akt;
            ile=1;
        }
        else if(akt==minx)++ile;
    }
    cout<<minx<<" "<<ile;
}