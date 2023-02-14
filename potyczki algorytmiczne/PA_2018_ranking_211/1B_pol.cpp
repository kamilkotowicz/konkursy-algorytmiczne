#include<iostream>
using namespace std;
string s;
const int maxn=2e5+5;
long long n,sam[500],przyrost,dp[maxn],poc;
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    n=s.size();
    if(n<3)cout<<0;
    else{
        sam['a']=sam['e']=sam['i']=sam['o']=sam['u']=sam['y']=1;
        for(long long i=2;i<n;++i){
            if((sam[s[i]]==sam[s[i-1]])&&(sam[s[i-1]]==sam[s[i-2]])){
                przyrost+=i-poc-1;
                poc=i-1;
            }
            dp[i]=dp[i-1]+przyrost;
        }
        cout<<dp[n-1];
    }
}