#include<iostream>
#include<vector>
//#include<fstream>
using namespace std;
int n,m,a,b;
const int mx=1e6+5;
vector<pair<int,int>>g[mx],graf[mx];
int low[mx],odw[mx],in[mx],t,most[mx];//trzyma numery krawedzi ktore sa mostami
int wynik[mx];
void dfs(int w,int kr){
    odw[w]=1;
    ++t;
    in[w]=t;
    low[w]=in[w];
    for(int i=0;i<g[w].size();++i){
        int x=g[w][i].first;
        int y=g[w][i].second;
        if(!odw[x]){
            dfs(x,y);
            low[w]=min(low[w],low[x]);
        }
        else if(y!=-kr){
            low[w]=min(low[w],in[x]);
        }
    }
    if(low[w]==in[w])most[abs(kr)]=1;
}
void zbuduj(int w){
    odw[w]=1;
    for(int i=0;i<g[w].size();++i){
        int x=g[w][i].first;
        int y=g[w][i].second;
        if(most[abs(y)]==0){
            graf[w].push_back({x,y});
        }
        if(!odw[x]){
            zbuduj(x);
        }
    }
}
void oblicz(int w,int kr){
    odw[w]=1;
    for(int i=0;i<graf[w].size();++i){
        int x=graf[w][i].first;
        int y=graf[w][i].second;
        if(y!=-kr&&wynik[abs(y)]==0){
            if(y>=0)wynik[y]=1;//>
            else wynik[-y]=2;//<
        }
        if(!odw[x]){
            oblicz(x,y);
        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //fin.open("/home/zawodnik/ocen3.in");
    //fin>>n>>m;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        //fin>>a>>b;
        cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,-i});
    }
    for(int i=1;i<=n;++i){
        if(!odw[i]){
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    for(int i=1;i<=n;++i){
        if(!odw[i]){
            zbuduj(i);
        }
    }
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    int spojne=0;
    for(int i=1;i<=n;++i){
        if(!odw[i]){
            ++spojne;
            oblicz(i,0);
        }
    }
    cout<<spojne<<"\n";
    for(int i=1;i<=m;++i){
        if(wynik[i]<2)cout<<'>';
        else cout<<'<';
    }
}