#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n;
long long k,suma,co,sz,inw;
vector<long long>v[251000];
const int BASE=262144;
int d[2*BASE];
int nowpoz;
const long long base=1000000000000000000;
inline long long pobierz(long long n,long long poz){
    if(poz<0||poz>n*(n-1)/2)return -2;
    if(n<5){
        if(poz>=v[n].size())return -1;
        return v[n][poz];
    }
    if(poz>n*(n-1)/4)poz=n*(n-1)/2-poz;
    if(poz<v[n].size())return v[n][poz];
    return -1;
}
inline void generuj(){
    v[1]={1};
    v[2]={1,1};
    v[3]={1,2,2,1};
    v[4]={1,3,5,6,5,3,1};
    for(long long i=5;i<=250000;++i){
        suma=0;
        sz=i*(i-1)/4;
        for(long long j=0;j<i;++j){
            co=pobierz(i-1,j);
            if(co!=-1)suma+=co;
            else goto dalej;
            if(suma<=base)v[i].push_back(suma);
            else goto dalej;
        }
        for(long long j=i;j<=sz;++j){
            co=pobierz(i-1,j);
            if(co!=-1){
                suma+=co;
                suma-=pobierz(i-1,j-i);
            }
            else goto dalej;
            if(suma<=base)v[i].push_back(suma);
            else goto dalej;
        }
        dalej:
        continue;
    }
}
void dodaj(int poz){
    poz+=BASE;
    while(poz>0){
        ++d[poz];
        poz/=2;
    }
}
void usun(int poz){
    poz+=BASE;
    while(poz>0){
        --d[poz];
        poz/=2;
    }
}
int szukaj(int k){
    int poz=1;
    while(poz<BASE){
        if(d[poz*2]>=k)poz*=2;
        else{
            k-=d[poz*2];
            poz=poz*2+1;
        }
    }
    return poz-BASE;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    if(n%4>1){
        cout<<"NIE\n";
        return 0;
    }
    generuj();
    for(int i=1;i<=n;++i){
        dodaj(i);
    }
    suma=k;
    inw=0;
    sz=n*(n-1)/4;
    for(long long i=n-1;i>=0;--i){
        nowpoz=-1;
        for(long long j=0;j<=i;++j){
            long long aaa=sz-j-inw;
            long long bbb=i*(i-1)/2;
            if(aaa>bbb+1){
                j+=aaa-bbb-1;
            }
            co=pobierz(i,sz-j-inw);
            if(co==-2){
                continue;
            }
            if(co==-1){
                nowpoz=j;
                inw+=nowpoz;
                break;
            }
            else{
                if(suma-co<=0){
                    nowpoz=j;
                    inw+=nowpoz;
                    break;
                }
                else{
                    suma-=co;
                }
            }
            if(sz-j-inw<0)break;
        }
        if(nowpoz==-1&&i==n-1){
            cout<<"NIE";
            return 0;
        }
        if(i==n-1)cout<<"TAK\n";
        co=szukaj(nowpoz+1);
        usun(co);
        cout<<co<<" ";
    }
}