#include <bits/stdc++.h>
using namespace std;
const int p=1e6+5;
int zlicz[2*p][3];
int typ,x,y,t,wyn,n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>typ>>x>>t;
        ++zlicz[x-t+p][typ];
    }
    for(int i=-1e6+p;i<=1e6+p;++i){
        wyn+=min(zlicz[i][1],zlicz[i][2]);
    }
    cout<<wyn;
}