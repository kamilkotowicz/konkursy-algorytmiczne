#include <iostream>
using namespace std;
long long n;
long long tab[25],dp[25];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int sz=0;
    while(n>0){
        tab[sz]=n%10;
        n/=10;
        ++sz;
    }
    for(int i=0;i<sz;++i){
        if(i==0)dp[i]=tab[i]+1;
        else if(i==1){
            dp[i]=(tab[i]+1)*dp[i-1];
            if(tab[i]==1)dp[i]+=9-tab[i-1];
        }
        else{
            dp[i]=(tab[i]+1)*dp[i-1];
            if(tab[i]==1)dp[i]+=(9-tab[i-1])*dp[i-2];
        }
    }
    cout<<dp[sz-1];
}