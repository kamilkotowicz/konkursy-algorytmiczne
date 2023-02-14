#include <bits/stdc++.h>
using namespace std;
int n;
string s;
unordered_map<string,int>mapa;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        ++mapa[s];
    }
    if(mapa.size()!=15){
        cout<<"NIE";
        return 0;
    }
    for(auto i:mapa){
        if(i.first[0]=='5'&&i.second==1){
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
}