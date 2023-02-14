#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int mx=5003;
int n;
int t[mx],dp[mx][mx],suf[mx][mx];
main(){
    ios::sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>t[i];
    }
    sort(t+1,t+n+1);
    t[n+1]=INT_MAX;
    for(int i=n;i>=0;--i){
        int kon=i;
        for(int j=0;j<=t[n];++j){
            while(t[i]+j>=t[kon+1]-1){
                ++kon;
            }
            if(kon==i)dp[i][j]=1;
            else if(j+t[i]<=t[n])dp[i][j]=(1+suf[i+1][j+t[i]]-suf[kon+1][j+t[i]]+mod)%mod;
            else dp[i][j]=(1+suf[i+1][t[n]]-suf[kon+1][t[n]]+mod)%mod;
            suf[i][j]=(dp[i][j]+suf[i+1][j])%mod;
        }
    }
    cout<<(dp[0][0]-1+mod)%mod;
}