#include<iostream>
using namespace std;
int n,m,a,b,k,poz;
int byl[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>a>>b>>k;
    poz=a;
    while(poz>n+m)poz-=(n+m);
    for(int i=1;i<k;++i){
        //cout<<poz<<"\n";
        byl[poz]=1;
        if(poz<=n){
            for(int j=0;j<a;++j){
                ++poz;
                if(poz>n+m)poz-=n+m;
                while(byl[poz]==1){
                    ++poz;
                    if(poz>n+m)poz-=n+m;
                }
            }
        }
        else{
            for(int j=0;j<b;++j){
                ++poz;
                if(poz>n+m)poz-=n+m;
                while(byl[poz]==1){
                    ++poz;
                    if(poz>n+m)poz-=n+m;
                }
            }
        }
    }
    cout<<poz;
}