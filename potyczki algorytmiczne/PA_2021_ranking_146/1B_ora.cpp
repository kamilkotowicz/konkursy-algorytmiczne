#include <bits/stdc++.h>
using namespace std;
const int mx=5e5+5;
long long wynik,x,slot;
int n,k,ileroznych;
int bylo[mx];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>x;
        if(bylo[x]==0&&slot<k){
            wynik+=(i-slot);
            ++slot;
            bylo[x]=1;
            ++ileroznych;
        }
    }
    if(ileroznych<k)cout<<-1;
    else cout<<wynik;
    return 0;
}