#include<iostream>
using namespace std;
const long long duzy=1e16;
const long long val=1e9;
long long dp,n,x,wynik,ilecyfr;
int cmp,roz;
inline int cyfry(long long x){
    int wynik=0;
    while(x>0){
        ++wynik;
        x/=10;
    }
    return wynik;
}
inline int porownaj(long long a,long long b){
    //1-wiekszy 0-rowny -1-mniejszy
    if(a<b)return 1;
    roz=cyfry(a)-cyfry(b);
    for(int i=0;i<roz;++i){
        a/=10;
    }
    if(a<b)return 1;
    else if(a>b)return -1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>x;
    dp=x;
    ilecyfr=cyfry(dp);
    for(long long i=1;i<n;++i){
        cin>>x;
        cmp=porownaj(dp,x);
        if(cmp==1){
            int ile=ilecyfr-cyfry(x);
            dp=x;
            wynik+=max(ile,0);
            for(int i=0;i<ile;++i){
                if(dp<duzy)dp*=10;
                else break;
            }
            ilecyfr=cyfry(x)+max(ile,0);
        }
        else if(cmp==-1){
            ++ilecyfr;
            dp=x;
            int ile=ilecyfr-cyfry(x);
            wynik+=max(ile,0);
            for(int i=0;i<ile;++i){
                if(dp<duzy)dp*=10;
                else break;
            }
        }
        else{
            if(dp>=duzy){
                wynik+=ilecyfr-cyfry(x);
            }
            else{
                if(porownaj(dp+1,x)==0){
                    wynik+=ilecyfr-cyfry(x);
                    ++dp;
                }
                else{
                    ++ilecyfr;
                    int ile=ilecyfr-cyfry(x);
                    dp=x;
                    wynik+=max(ile,0);
                    for(int i=0;i<ile;++i){
                        if(dp<duzy)dp*=10;
                        else break;
                    }
                }
            }
        }
       // cerr<<"\n "<<dp<<"\n";
    }
    cout<<wynik;
}