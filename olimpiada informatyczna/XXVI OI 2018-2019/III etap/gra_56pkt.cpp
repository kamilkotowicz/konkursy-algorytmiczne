#include <iostream>
#include<vector>
#include "gralib.hpp"
using namespace std;
int n,m,k,suma,najwd;
const int mx=250005;
const int niesk=2e9;
vector<int>dzielniki[mx];
double dp[mx];
double akt;
int main(){
    ios::sync_with_stdio(false);
    for(int i=1;i<=250;++i){
        for(int j=i;j<=250000;j+=i){
            dzielniki[j].push_back(i);
        }
        dzielniki[0].push_back(i);
    }
    for(int q=0;q<100;++q){
        suma=0;
        n=dajN();
        k=dajK();
        m=dajM();
        //n=100;
        //k=10;
        //m=100;
        najwd=1;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                if(i<=k){
                    if(i>najwd)najwd=i;
                }
                if(n/i<=k){
                    if(n/i>najwd)najwd=n/i;
                }
            }
        }
        dp[n]=0;
        for(int i=n-1;i>=0;--i){
            if(i>=n-5)akt=k;
            else akt=(dp[i+1]+dp[i+2]+dp[i+3]+dp[i+4])/4;
            for(int it=0;it<40;++it){
                dp[i]=0;
                double ile=0;
                for(int j=0;j<dzielniki[i].size();++j){
                    int dziel=dzielniki[i][j];
                    if(dziel>k)break;
                    dp[i]+=(min(akt,dp[i+dziel]))/k;
                    ile+=1.0;
                }
                dp[i]+=(double)(k-ile)/k*akt;
                dp[i]+=1.0;
                akt=dp[i];
            }
        }
        while(suma<n){
            //int x=rand()%k+1;
            int x=nastepna();
            if(suma+x>n||suma%x!=0)continue;
            if(dp[suma+x]<dp[suma]){
                zwieksz();
                suma+=x;
            }
        }
        koniec();
    }
}