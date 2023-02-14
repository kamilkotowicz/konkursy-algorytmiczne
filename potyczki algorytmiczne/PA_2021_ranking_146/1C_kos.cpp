#include <bits/stdc++.h>
using namespace std;
const int mx=2005;
int n,k,w;
int t[mx];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>t[i];
    }
    sort(t,t+n,[](int a,int b){return a>b;});
    while(k<n){
        if(t[k]==t[k-1])++k;
        else break;
    }
    cout<<k;
    return 0;
}