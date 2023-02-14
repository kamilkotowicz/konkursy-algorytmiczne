#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
struct punkt{
    int wsp,kolor;
};
const int mx=1e6+5;
const long long mod=2877629297581607;
punkt tabx[mx],taby[mx];
long long pot[mx];
int strona[mx];
long long wynx,wyny,wyn,hasz;
int n,x,y,xp,xk,yp,yk,ile_dodac,skad;
map<long long,int>mapa;

long long najdluzszy(punkt* tx,int dlugosc){
    for(int i=0;i<n;++i)strona[i]=0;
    hasz=0;
    mapa.clear();
    for(int i=1;i<n;++i){
        ile_dodac=tx[i].wsp-tx[i-1].wsp;
        skad=tx[i].kolor;
        if(ile_dodac!=0){
            mapa[hasz]+=ile_dodac;
        }
        if(strona[skad]==0){
            strona[skad]=1;
            hasz+=pot[skad];
            if(hasz>=mod)hasz-=mod;
        }
        else{
            strona[skad]=0;
            hasz-=pot[skad];
            if(hasz<0)hasz+=mod;
        }
    }
    ile_dodac=tx[0].wsp+dlugosc-tx[n-1].wsp;
    skad=tx[0].kolor;
    if(ile_dodac!=0)mapa[hasz]+=ile_dodac;
    long long wyn=0;
    for(auto it=mapa.begin();it!=mapa.end();++it){
        int akt=(*it).second;
        if(akt>wyn)wyn=akt;
    }
    return wyn;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>x>>y;
    for(int i=0;i<n;++i){
        cin>>xp>>yp>>xk>>yk;
        tabx[2*i]={xp,i};
        tabx[2*i+1]={xk,i};
        taby[2*i]={yp,i};
        taby[2*i+1]={yk,i};
    }
    n*=2;
    pot[0]=1;
    for(int i=1;i<n;++i){
        pot[i]=29*pot[i-1];
        pot[i]%=mod;
    }
    sort(tabx,tabx+n,[](punkt a,punkt b){return a.wsp<b.wsp;});
    sort(taby,taby+n,[](punkt a,punkt b){return a.wsp<b.wsp;});
    wynx=najdluzszy(tabx,x);
    wyny=najdluzszy(taby,y);
    wyn=wynx*wyny;
    cout<<wyn;
}