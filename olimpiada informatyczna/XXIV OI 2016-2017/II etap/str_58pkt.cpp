//Kamil Kotowicz
#include <iostream>
#include<vector>
using namespace std;
vector<int>graf[501000];
int odw[501000];
int n,a,b,wynik,ujemna,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    cin>>m;
    wynik=1;
    for(int i=0;i<m;++i){
        cin>>a;
        ujemna=0;
        if(a<0){
            a*=-1;
            ujemna=1;
        }
        odw[a]=1-odw[a];
        if(ujemna==0){
            for(int j=0;j<graf[a].size();++j){
                if(odw[graf[a][j]]==1)--wynik;
            }
            wynik+=graf[a].size()-1;
        }
        else{
            for(int j=0;j<graf[a].size();++j){
                if(odw[graf[a][j]]==1)++wynik;
            }
            wynik+=1-graf[a].size();
        }
        cout<<wynik<<"\n";
    }
    return 0;
}

