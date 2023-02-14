#include <bits/stdc++.h>
using namespace std;
const int mx=105;
int n,k,akt;
int l[mx],p[mx];
int main(){
    ios::sync_with_stdio(false);
    cin>>k;
    akt=1;
    n=2;
    while(k>1){
        l[akt]=akt+1;
        p[akt]=akt+2;
        l[akt+1]=akt+2;
        if(k%2==0)p[akt+1]=-1;
        n+=2;
        akt+=2;
        k/=2;
    }
    p[akt]=-1;
    for(int i=1;i<=n;++i){
        if(l[i]==0)l[i]=n;
        if(p[i]==0)p[i]=n;
    }
    l[n]=p[n]=-1;
    cout<<n<<"\n";
    for(int i=1;i<=n;++i){
        cout<<l[i]<<" "<<p[i]<<"\n";
    }
}