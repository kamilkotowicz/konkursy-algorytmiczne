#include<iostream>
#include<vector>
using namespace std;
int n,m,p,a,b;
const int mx=1e5+5;
vector<int>g[mx];
int odw[mx],odl[mx];
int ojciec[mx][20];
inline void bfs(int a){
    vector<int>v;
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    v.push_back(a);
    odl[a]=0;
    odw[a]=1;
    for(int i=0;i<v.size();++i){
        int w=v[i];
        for(int j=0;j<g[w].size();++j){
            int x=g[w][j];
            if(!odw[x]){
                odw[x]=1;
                odl[x]=odl[w]+1;
                v.push_back(x);
            }
        }
    }
}
inline void brut(){
    for(int i=0;i<m;++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<p;++i){
        cin>>a>>b;
        bfs(a);
        cout<<odl[b]<<"\n";
    }
}
void dfs(int w){
    odw[w]=1;
    for(int i=0;i<g[w].size();++i){
        int x=g[w][i];
        if(!odw[x]){
            odl[x]=odl[w]+1;
            ojciec[x][0]=w;
            dfs(x);
        }
    }
}
inline void preprocess(){
    dfs(1);
    ojciec[1][0]=1;
    for(int i=1;i<20;++i){
        for(int j=1;j<=n;++j){
            ojciec[j][i]=ojciec[ojciec[j][i-1]][i-1];
        }
    }
}
inline int lca(int a,int b){
    if(odl[a]>odl[b]){
        for(int i=19;i>=0;--i){
            if(odl[ojciec[a][i]]>=odl[b]){
                a=ojciec[a][i];
            }
        }
    }
    if(odl[b]>odl[a]){
        for(int i=19;i>=0;--i){
            if(odl[ojciec[b][i]]>=odl[a]){
                b=ojciec[b][i];
            }
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;--i){
        if(ojciec[a][i]!=ojciec[b][i]){
            a=ojciec[a][i];
            b=ojciec[b][i];
        }
    }
    return ojciec[a][0];
}
inline int odleglosc(int a,int b){
    int c=lca(a,b);
    return odl[a]-odl[c]+odl[b]-odl[c];
}
inline void drzewo(){
    for(int i=0;i<m;++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    preprocess();
    for(int i=0;i<p;++i){
        cin>>a>>b;
        cout<<odleglosc(a,b)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>p;
    if(m!=n-1)brut();
    else drzewo();

}