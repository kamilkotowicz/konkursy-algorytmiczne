#include <bits/stdc++.h>
using namespace std;
vector<int>dp,suma,pref,dp2;
int n,m;
long long mod;
void oblicz_dp(int nr){
    if(nr==m){
        dp.clear();
        dp.resize(n+2);
        dp[1]=1;
        for(int i=2;i<=n;++i){
            dp[i]=(dp[i-1]+i)%mod;
        }
        return;
    }
    dp2.resize(n+2);
    for(int i=1;i<=n;++i){
        dp2[i]=dp[i];
    }
    dp.clear();
    dp.resize(n+2);
    if(n==1)dp[1]=1;
    else dp[1]=(dp2[n]-dp2[n-1]+mod)%mod;
    for(int i=2;i<=n;++i){
        dp[i]=(dp[i-1]-pref[i]+mod)%mod;
        long long mn=((long long)dp2[n-i]*(long long)i)%mod;
        dp[i]=(dp[i]-mn+mod)%mod;
        mn=((long long)dp2[n]*(long long)i)%mod;
        dp[i]=(dp[i]+mn)%mod;
    }
    dp2.clear();
}
void oblicz_pref(){
    pref.clear();
    pref.resize(n+2);
    pref[1]=0;
    for(int i=2;i<=n;++i){
        pref[i]=(pref[i-1]+dp[i-1])%mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>m>>n>>mod;
    for(int i=m;i>=1;--i){
        oblicz_dp(i);
        oblicz_pref();
    }
    cout<<dp[n]%mod;
}