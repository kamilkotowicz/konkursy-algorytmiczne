#include <bits/stdc++.h>
using namespace std;
const int mx=1e5+5;
set<pair<int,int>>odw;
vector<pair<pair<int,int>,int>>kolejka;
int ma,mb,mc,a,b,c,suma;
int x,y,z,t;
int przel_x_y,przel_x_z,przel_y_x,przel_y_z,przel_z_x,przel_z_y;
int dp[mx];
inline void dodaj(int nx,int ny,int nt){
    auto it=odw.find({nx,ny});
    if(it==odw.end())kolejka.push_back({{nx,ny},nt});
}
int main(){
    ios::sync_with_stdio(false);
    cin>>ma>>mb>>mc>>a>>b>>c;
    suma=a+b+c;
    for(int i=0;i<=mc;++i){
        dp[i]=INT_MAX;
    }
    kolejka.push_back({{a,b},0});
    for(int i=0;i<kolejka.size();++i){
        int x=kolejka[i].first.first;
        int y=kolejka[i].first.second;
        int t=kolejka[i].second;
        odw.insert({x,y});
        int z=suma-x-y;
        dp[x]=min(dp[x],t);
        dp[y]=min(dp[y],t);
        dp[z]=min(dp[z],t);
        przel_x_y=min(x,mb-y);
        przel_x_z=min(x,mc-z);
        przel_y_x=min(y,ma-x);
        przel_y_z=min(y,mc-z);
        przel_z_x=min(z,ma-x);
        przel_z_y=min(z,mb-y);
        dodaj(x-przel_x_y,y+przel_x_y,t+1);
        dodaj(x-przel_x_z,y,t+1);
        dodaj(x+przel_y_x,y-przel_y_x,t+1);
        dodaj(x,y-przel_y_z,t+1);
        dodaj(x+przel_z_x,y,t+1);
        dodaj(x,y+przel_z_y,t+1);
    }
    for(int i=0;i<=mc;++i){
        if(dp[i]==INT_MAX)cout<<-1<<" ";
        else cout<<dp[i]<<" ";
    }
    return 0;
}