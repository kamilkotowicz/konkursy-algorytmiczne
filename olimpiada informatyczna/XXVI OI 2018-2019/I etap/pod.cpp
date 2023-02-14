#include <iostream>
#include<vector>
using namespace std;
long long q,x,suma,a,b,fa,fb;
vector<char>l,p;
long long lit,co,co2,dodaj,podziel,zero,jeden,pot1,pot2;
char zn[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
'0','1','2','3','4','5','6','7','8','9'};
vector<int>lewy,prawy;
vector<pair<long long,long long>>dp;
inline void wyprowadz(int k,int kk){
    if(kk==0)co=lewy[k];
    else co=prawy[k];
    if(co==0){
        if(zero==-1){
            dp.push_back({2*dp.back().first,2*dp.back().second});
        }
        else if(zero==0){
            dp.push_back({2*dp.back().first,2*dp.back().second-1});
        }
        else{
            dp.push_back({2*dp.back().first-dp[zero-1].first,2*dp.back().second-dp[zero-1].second});
        }
        zero=dp.size()-1;
    }
    else{
        if(jeden==-1){
            dp.push_back({2*dp.back().first,2*dp.back().second});
        }
        else if(jeden==0){
            dp.push_back({2*dp.back().first,2*dp.back().second-1});
        }
        else{
            dp.push_back({2*dp.back().first-dp[jeden-1].first,2*dp.back().second-dp[jeden-1].second});
        }
        jeden=dp.size()-1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>x;
        l.clear();
        p.clear();
        lit=0;
        while(x!=1){
            suma=1;
            a=0;
            b=suma-a;
            for(;;){
                for(int j=max(1<<(a-1),0);j<(1<<a);++j){
                    lewy.clear();
                    co=j;
                    while(co>0){
                        lewy.push_back(co%2);
                        co/=2;
                    }
                    for(int jj=max(1<<(b-1),0);jj<(1<<b);++jj){
                        if(j+jj==0)continue;
                        prawy.clear();
                        co=jj;
                        while(co>0){
                            prawy.push_back(co%2);
                            co/=2;
                        }
                        dp.clear();
                        zero=-1;
                        jeden=-1;
                        dp.push_back({0,1});
                        for(int k=0;k<a;++k){
                            wyprowadz(k,0);
                        }
                        if(dp.size()>0)dp.push_back({dp.back().second,0});
                        else dp.push_back({1,0});
                        for(int k=0;k<b;++k){
                            wyprowadz(k,1);
                        }
                        fa=dp.back().first;
                        fb=dp.back().second;
                        if((x-fb)%fa==0){
                            goto dziala;
                        }
                    }
                }
                ++a;
                --b;
                if(a>b){
                    ++suma;
                    a=0;
                    b=suma-a;
                }
            }
            dziala:
                        pot1=0;
            pot2=0;
            for(int i=0;i<a;++i){
                if(lewy[i]==0)pot1=1;
                else pot2=1;
            }
            for(int i=0;i<b;++i){
                if(prawy[i]==0)pot1=1;
                else pot2=1;
            }
            if(pot1>0&&pot2>0){
                for(int i=0;i<a;++i){
                    if(lewy[i]==0)l.push_back(zn[lit]);
                    else l.push_back(zn[lit+1]);
                }
                for(int i=b-1;i>=0;--i){
                    if(prawy[i]==0)p.push_back(zn[lit]);
                    else p.push_back(zn[lit+1]);
                }
                lit+=2;
            }
            else{
                for(int i=0;i<a;++i){
                    l.push_back(zn[lit]);
                }
                for(int i=b-1;i>=0;--i){
                    p.push_back(zn[lit]);
                }
                ++lit;
            }
            x-=fb;
            x/=fa;
        }
        if(l.size()+p.size()>1000){
            cout<<"!\n";
            continue;
        }
        for(int i=0;i<l.size();++i){
            cout<<l[i];
        }
        for(int i=p.size()-1;i>=0;--i){
            cout<<p[i];
        }
        cout<<"\n";
    }
}