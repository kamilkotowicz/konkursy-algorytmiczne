#include <bits/stdc++.h>
using namespace std;
const int mx=5e5+5;
int n,w,l,p,sr;
pair<long long,int>t[mx];
char krol[mx];
int dziala(int poz){
    long long suma=t[poz].first;
    for(int i=0;i<n;++i){
        if(i==poz)continue;
        if(suma>t[i].first){
            suma+=t[i].first;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>t[i].first;
        t[i].second=i;
    }
    sort(t,t+n);
    w=n;//minimalny indeks dla ktorego dziala
    l=0;
    p=n-1;
    while(l<=p){
        sr=(l+p)/2;
        if(dziala(sr)==1){
            w=sr;
            p=sr-1;
        }
        else{
            l=sr+1;
        }
    }
    for(int i=0;i<w;++i){
       krol[t[i].second]='N';
    }
    for(int i=w;i<n;++i){
        krol[t[i].second]='T';
    }
    for(int i=0;i<n;++i){
        cout<<krol[i];
    }
    return 0;
}