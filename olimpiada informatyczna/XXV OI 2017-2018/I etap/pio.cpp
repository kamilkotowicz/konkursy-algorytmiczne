//Kamil Kotowicz
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<long long,long long>>v1,v2,v3,v4;
vector<pair<long long,long long>>punkty;
vector<pair<long long,long long>>kopia;
long long poczatki[5];
long long konce[5];
long long gora,dol,lewo,prawo,poc,kon,x,y,wx,wy,wyn,sr,nx,ny,xx2,yy2,koniec;
long long n,a,b;
long long prefx[501000];
long long prefy[501000];
long long sz,cc,cn,cp,pk,kk,ccc0,ccc1;
long long wynik;
#ifdef _WIN32
#define getc_unlocked getc
#endif
inline void read(long long *n)
{
    register char c = 0,
  znak_liczby=1;
    while (c < 33) c=getc_unlocked(stdin);

    if(c==45) {znak_liczby=-1;  c=getc_unlocked(stdin);}
    (*n) = 0;

  while (c>32) {(*n)=(*n)*10LL + c-48; c=getc_unlocked(stdin);}

    (*n)*=znak_liczby;
}
inline void zlacz(vector<pair<long long,long long>>& v){
    kopia.resize(0);
    for(int i=0;i<v.size();++i){
        if(i>0&&v[i-1].first*v[i].second==v[i-1].second*v[i].first){
            kopia.back().first+=v[i].first;
            kopia.back().second+=v[i].second;
        }
        else{
            kopia.push_back(make_pair(v[i].first,v[i].second));
        }
    }
    v=kopia;
}
inline bool jest(long long a,long long b,long long c,long long d){
    return a*d-b*c>=0;
}
int main(){
    ios::sync_with_stdio(false);
    read(&n);
    //cin>>n;
    for(int i=0;i<n;++i){
        read(&a);
        read(&b);
        //cin>>a>>b;
        if(a>0){
            if(b>0)v1.push_back(make_pair(a,b));
            else if(b<0)v4.push_back(make_pair(a,b));
            else prawo+=a;
        }
        else if(a<0){
            if(b>0)v2.push_back(make_pair(a,b));
            else if(b<0)v3.push_back(make_pair(a,b));
            else lewo+=a;
        }
        else{
            if(b>0)gora+=b;
            if(b<0)dol+=b;
        }
    }
    sort(v1.begin(),v1.end(),[](pair<long long,long long>a,pair<long long,long long>b){return a.second*b.first<b.second*a.first;});
    sort(v2.begin(),v2.end(),[](pair<long long,long long>a,pair<long long,long long>b){return a.second*b.first<b.second*a.first;});
    sort(v3.begin(),v3.end(),[](pair<long long,long long>a,pair<long long,long long>b){return a.second*b.first<b.second*a.first;});
    sort(v4.begin(),v4.end(),[](pair<long long,long long>a,pair<long long,long long>b){return a.second*b.first<b.second*a.first;});
    zlacz(v1);
    zlacz(v2);
    zlacz(v3);
    zlacz(v4);
    for(int i=0;i<v1.size();++i){
        punkty.push_back(make_pair(v1[i].first,v1[i].second));
    }
    if(gora!=0){
        punkty.push_back(make_pair(0,gora));
    }
    for(int i=0;i<v2.size();++i){
        punkty.push_back(make_pair(v2[i].first,v2[i].second));
    }
    if(lewo!=0){
        punkty.push_back(make_pair(lewo,0));
    }
    for(int i=0;i<v3.size();++i){
        punkty.push_back(make_pair(v3[i].first,v3[i].second));
    }
    if(dol!=0){
        punkty.push_back(make_pair(0,dol));
    }
    for(int i=0;i<v4.size();++i){
        punkty.push_back(make_pair(v4[i].first,v4[i].second));
    }
    if(prawo!=0){
        punkty.push_back(make_pair(prawo,0));
    }
    sz=punkty.size();
    if(sz==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<sz;++i){
        punkty.push_back(make_pair(punkty[i].first,punkty[i].second));
    }
    prefx[0]=punkty[0].first;
    prefy[0]=punkty[0].second;
    for(int i=1;i<punkty.size();++i){
        prefx[i]=prefx[i-1]+punkty[i].first;
    }
    for(int i=1;i<punkty.size();++i){
        prefy[i]=prefy[i-1]+punkty[i].second;
    }
    for(poc=0;poc<sz;++poc){
        if(kon<poc)++kon;
        while(jest(punkty[poc].first,punkty[poc].second,punkty[kon].first,punkty[kon].second)){
            if(kon==poc+sz)break;
            if(poc==0){
                wx=prefx[kon];
                wy=prefy[kon];
            }
            else{
                wx=prefx[kon]-prefx[poc-1];
                wy=prefy[kon]-prefy[poc-1];
            }
            wynik=max(wynik,wx*wx+wy*wy);
            ++kon;
        }
        --kon;
        if(poc==0){
            wx=prefx[kon];
            wy=prefy[kon];
        }
        else{
            wx=prefx[kon]-prefx[poc-1];
            wy=prefy[kon]-prefy[poc-1];
            wynik=max(wynik,wx*wx+wy*wy);
        }
    }
    cout<<wynik;
}