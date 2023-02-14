#include <bits/stdc++.h>
using namespace std;
const int mx=5e5+5;
int n;
long long t[mx],dp[mx];
long long pref[mx];
map<long long,long long>pd;
long long znajdz(long long minp){
    auto it=pd.lower_bound(minp);
    if(it==pd.end())return -1;
    return (*it).second;
}
void dodaj(long long p,long long d){
    auto it=pd.lower_bound(p);
    if(it==pd.end()){
        pd[p]=d;
    }
    else{
        if((*it).second>=d)return;
        pd[p]=d;
    }
    it=pd.find(p);
    if(it==pd.begin())return;
    auto poprz=it;
    --poprz;
    while((*poprz).second<=d){
        pd.erase(poprz);
        if(it==pd.begin())return;
        poprz=it;
        --poprz;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
        pref[i]=pref[i-1]+(long long)t[i];
    }
    if(t[n]<0)dp[n]=-1;
    else dp[n]=0;
    dodaj(pref[n-1],dp[n]);
    for(int i=n-1;i>=1;--i){
        if(pref[n]-pref[i-1]<0){
            dp[i]=-1;
        }
        else{
            dp[i]=znajdz(pref[i-1])+1;
        }
        dodaj(pref[i-1],dp[i]);
    }
    cout<<n-1-dp[1];
}