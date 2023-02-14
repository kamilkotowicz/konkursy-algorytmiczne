#include<iostream>
#include<vector>
using namespace std;
int n,m,a,b,nr;
vector<int>graf[51000],graf2[51000],d[51000];
vector<int>vv,stos;
vector<vector<int>>spojne;
int dp[51000],odw[51000];
int gdzie[51000];
inline void dfs(int w){
    odw[w]=1;
    for(int i=0;i<graf[w].size();++i){
        int x=graf[w][i];
        if(!odw[x]){
            dfs(x);
        }
    }
    stos.push_back(w);
}
inline void dfs2(int w){
    odw[w]=1;
    vv.push_back(w);
    for(int i=0;i<graf2[w].size();++i){
        int x=graf2[w][i];
        if(!odw[x]){
            dfs2(x);
        }
    }
}
inline void dfs3(int w){
    odw[w]=1;
    dp[w]=spojne[w].size()-1;
    for(int i=0;i<d[w].size();++i){
        int x=d[w][i];
        if(!odw[x]){
            dfs3(x);
        }
        dp[w]+=dp[x]+1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        graf[a].push_back(b);
        graf2[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        if(!odw[i])dfs(i);
    }
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    nr=-1;
    for(int i=stos.size()-1;i>=0;--i){
        int x=stos[i];
        if(!odw[x]){
            ++nr;
            vv.resize(0);
            dfs2(x);
            spojne.push_back(vv);
        }
    }
    for(int i=0;i<spojne.size();++i){
        for(int j=0;j<spojne[i].size();++j){
            gdzie[spojne[i][j]]=i;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<graf[i].size();++j){
            int x=graf[i][j];
            if(gdzie[i]!=gdzie[x]){
                d[gdzie[i]].push_back(gdzie[x]);
            }
        }
    }
    for(int i=0;i<spojne.size();++i){
        odw[i]=0;
    }
    for(int i=0;i<spojne.size();++i){
        if(odw[i]==0){
            dfs3(i);
        }
    }
    for(int i=1;i<=n;++i){
        cout<<dp[gdzie[i]]<<"\n";
    }
}