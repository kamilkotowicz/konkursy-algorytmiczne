#include<iostream>
#include<vector>
using namespace std;
int n,r,a,b,c,q;
const int mx=1e5+5;
const int LOG=18;
const long long niesk=9e18;
int rodzaj[mx];
long long droga[mx],gl[mx];
int ojciec[mx][LOG+1];
vector<int>v[mx];
vector<pair<int,int>>g[mx];
void dfs(int w,int oj){
    ojciec[w][0]=oj;
    for(int i=0;i<g[w].size();++i){
        int x=g[w][i].first;
        long long y=g[w][i].second;
        if(x!=oj){
            droga[x]=droga[w]+y;
            gl[x]=gl[w]+1;
            dfs(x,w);
        }
    }
}
void preprocess(){
    dfs(1,1);
    for(int j=1;j<=LOG;++j){
        for(int i=1;i<=n;++i){
            ojciec[i][j]=ojciec[ojciec[i][j-1]][j-1];
        }
    }
}
int lca(int a,int b){
    int poza=a;
    int pozb=b;
    while(gl[poza]!=gl[pozb]){
        if(gl[poza]>gl[pozb]){
            for(int i=LOG;i>=0;--i){
                int nast=ojciec[poza][i];
                if(gl[nast]>=gl[pozb]){
                    poza=nast;
                }
            }
        }
        else{
            for(int i=LOG;i>=0;--i){
                int nast=ojciec[pozb][i];
                if(gl[nast]>=gl[poza]){
                    pozb=nast;
                }
            }
        }
    }
    if(poza!=pozb){
        for(int i=LOG;i>=0;--i){
            int nasta=ojciec[poza][i];
            int nastb=ojciec[pozb][i];
            if(nasta!=nastb){
                poza=nasta;
                pozb=nastb;
            }
        }
        return ojciec[poza][0];
    }
    return poza;
}
long long odl(int a,int b){
    int l=lca(a,b);
    return droga[a]-droga[l]+droga[b]-droga[l];
}
void brut(){
    for(int i=1;i<=n;++i){
        v[rodzaj[i]].push_back(i);
    }
    for(int i=0;i<q;++i){
        cin>>a>>b>>c;
        long long wyn=niesk;
        for(int j=0;j<v[c].size();++j){
            long long w=odl(a,v[c][j])+odl(b,v[c][j]);
            if(w<wyn)wyn=w;
        }
        if(wyn!=niesk)cout<<wyn<<"\n";
        else cout<<-1<<"\n";
    }
}
void podzad4(){
    for(int i=0;i<q;++i){
        cin>>a>>b>>c;
        if(c!=rodzaj[1])cout<<-1<<"\n";
        else cout<<odl(a,b)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>r;
    for(int i=1;i<=n;++i){
        cin>>rodzaj[i];
    }
    for(int i=0;i<n-1;++i){
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    preprocess();
    cin>>q;
    if(r==1){
        podzad4();
    }
    else{
        brut();
    }
}