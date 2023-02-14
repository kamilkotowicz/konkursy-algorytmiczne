#include <bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
int n,x,lewy,prawy,dl,l,p,k;
int poz[mx];
long long wyn;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        poz[x]=i;
    }
    wyn=1;
    dl=1;
    lewy=poz[n];
    prawy=poz[n];
    for(int dl=2;dl<=n;++dl){
        if(dl%2==0){
            lewy=min(lewy,poz[n-dl/2]);
            prawy=max(prawy,poz[n-dl/2]);
        }
        k=dl-(prawy-lewy+1);
        if(k<0)continue;
        l=lewy;
        p=n-1-prawy;
        l=min(l,k);
        p=min(p,k);
        wyn+=(long long)(l+p-k+1);
    }
    cout<<2*n+1<<" "<<wyn;
    return 0;
}