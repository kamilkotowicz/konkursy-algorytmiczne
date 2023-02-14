#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const long long niesk=9e18;
const int MAXN=3e5+5;
const int MAXQ=1e5+5;
const int BASE=524288;
struct drzewo{
    long long min_waga,max_waga,suma_wag,min_waga_temp,max_waga_temp,suma_wag_temp;
    int liczba_ryb,liczba_ryb_temp,zmiana;
};
drzewo d[2*BASE];
map<long long,int>mapa;
map<long long,int>indeks;
vector<long long>poc_ryby;
long long poc[MAXQ],kon[MAXQ];
int akcja[MAXQ];
long long x,akt_masa,kon_masa,nast_ryba;
int n,q,sz,zjedzone,nr_zap;
inline void wczytaj(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        poc_ryby.push_back(x);
    }
    cin>>q;
    for(int i=1;i<=q;++i){
        cin>>akcja[i]>>poc[i];
        if(akcja[i]==1)cin>>kon[i];
        else if(akcja[i]==2)mapa[poc[i]]=0;
    }
    for(int i=0;i<n;++i)++mapa[poc_ryby[i]];
}
inline void napraw_trwale(int akt){
    int l=akt*2;
    int p=akt*2+1;
    if(d[l].liczba_ryb>0){
        if(d[p].liczba_ryb>0){
            d[akt].min_waga=min(d[l].min_waga,d[p].min_waga);
            d[akt].max_waga=max(d[l].max_waga,d[p].max_waga);
        }
        else{
            d[akt].min_waga=d[l].min_waga;
            d[akt].max_waga=d[l].max_waga;
        }
    }
    else{
        if(d[p].liczba_ryb>0){
            d[akt].min_waga=d[p].min_waga;
            d[akt].max_waga=d[p].max_waga;
        }
    }
    d[akt].suma_wag=d[l].suma_wag+d[p].suma_wag;
    d[akt].liczba_ryb=d[l].liczba_ryb+d[p].liczba_ryb;
}
inline void napraw_tymczasowo(int akt){
    int l=akt*2;
    int p=akt*2+1;
    if(d[l].liczba_ryb_temp>0){
        if(d[p].liczba_ryb_temp>0){
            d[akt].min_waga_temp=min(d[l].min_waga_temp,d[p].min_waga_temp);
            d[akt].max_waga_temp=max(d[l].max_waga_temp,d[p].max_waga_temp);
        }
        else{
            d[akt].min_waga_temp=d[l].min_waga_temp;
            d[akt].max_waga_temp=d[l].max_waga_temp;
        }
    }
    else{
        if(d[p].liczba_ryb_temp>0){
            d[akt].min_waga_temp=d[p].min_waga_temp;
            d[akt].max_waga_temp=d[p].max_waga_temp;
        }
    }
    d[akt].suma_wag_temp=d[l].suma_wag_temp+d[p].suma_wag_temp;
    d[akt].liczba_ryb_temp=d[l].liczba_ryb_temp+d[p].liczba_ryb_temp;
    d[akt].zmiana=nr_zap;
}
inline void zbuduj_drzewo(){
    sz=0;
    for(auto it=mapa.begin();it!=mapa.end();++it){
        long long x=(*it).first;
        int y=(*it).second;
        indeks[x]=sz;
        int akt=sz+BASE;
        d[akt]={x,x,x*y,0,0,0,y,0,0};
        akt/=2;
        while(akt>0){
            napraw_trwale(akt);
            akt/=2;
        }
        ++sz;
    }
}
inline void zap2(){
    long long waga=poc[nr_zap];
    int akt=indeks[waga]+BASE;
    d[akt].suma_wag+=waga;
    ++(d[akt].liczba_ryb);
    d[akt].min_waga=waga;
    d[akt].max_waga=waga;
    akt/=2;
    while(akt>0){
        napraw_trwale(akt);
        akt/=2;
    }
}
inline void zap3(){
    long long waga=poc[nr_zap];
    int akt=indeks[waga]+BASE;
    d[akt].suma_wag-=waga;
    --(d[akt].liczba_ryb);
    akt/=2;
    while(akt>0){
        napraw_trwale(akt);
        akt/=2;
    }
}
inline void przepisz(int akt){
    if(d[akt].zmiana!=nr_zap){
        d[akt].min_waga_temp=d[akt].min_waga;
        d[akt].max_waga_temp=d[akt].max_waga;
        d[akt].suma_wag_temp=d[akt].suma_wag;
        d[akt].liczba_ryb_temp=d[akt].liczba_ryb;
        d[akt].zmiana=nr_zap;
    }
}
long long szukaj_wiekszej_ryby(int akt,int poc,int kon){
    if(poc>kon)return niesk;
    przepisz(akt);
    if(d[akt].liczba_ryb_temp==0)return niesk;
    if(d[akt].max_waga_temp<akt_masa)return niesk;
    if(poc==kon){
        if(d[akt].liczba_ryb_temp>0){
            if(d[akt].min_waga_temp>=akt_masa)return d[akt].min_waga_temp;
        }
        return niesk;
    }
    long long ryba1=szukaj_wiekszej_ryby(akt*2,poc,(poc+kon)/2);
    if(ryba1!=niesk)return ryba1;
    long long ryba2=szukaj_wiekszej_ryby(akt*2+1,(poc+kon)/2+1,kon);
    return ryba2;
}
void jedzonko(int akt,int poc,int kon){
    if(poc>kon)return;
    przepisz(akt);
    if(akt_masa>=kon_masa||akt_masa>nast_ryba)return;
    if(d[akt].liczba_ryb_temp==0)return;
    if(d[akt].min_waga_temp>=akt_masa)return;
    if(poc==kon){
        if(d[akt].min_waga_temp<akt_masa){
            long long delta=(min(nast_ryba+1,kon_masa)-akt_masa);
            long long waga=d[akt].min_waga_temp;
            long long ile;
            if(delta%waga==0)ile=delta/waga;
            else ile=delta/waga+1;
            if(ile>d[akt].liczba_ryb_temp)ile=d[akt].liczba_ryb_temp;
            akt_masa+=ile*waga;
            zjedzone+=ile;
            d[akt].suma_wag_temp-=ile*waga;
            d[akt].liczba_ryb_temp-=ile;
        }
        return;
    }
    if(d[akt].max_waga_temp<akt_masa){
        long long masa_po=akt_masa+d[akt].suma_wag_temp;
        if(masa_po<kon_masa&&masa_po<=nast_ryba){
            akt_masa=masa_po;
            zjedzone+=d[akt].liczba_ryb_temp;
            d[akt].suma_wag_temp=0;
            d[akt].liczba_ryb_temp=0;
            return;
        }
    }
    jedzonko(akt*2+1,(poc+kon)/2+1,kon);
    jedzonko(akt*2,poc,(poc+kon)/2);
    napraw_tymczasowo(akt);
}
inline void zap1(){
    akt_masa=poc[nr_zap];
    kon_masa=kon[nr_zap];
    zjedzone=0;
    for(;;){
        nast_ryba=szukaj_wiekszej_ryby(1,0,BASE-1);
        int bylo=zjedzone;
        jedzonko(1,0,BASE-1);
        int jest=zjedzone;
        if(bylo==jest)break;
        if(akt_masa>=kon_masa)break;
    }
    if(akt_masa<kon_masa)cout<<-1<<"\n";
    else cout<<zjedzone<<"\n";
}
 main(){
    ios::sync_with_stdio(false);
    wczytaj();
    zbuduj_drzewo();
    for(int i=1;i<=q;++i){
        nr_zap=i;
        if(akcja[i]==1)zap1();
        else if(akcja[i]==2)zap2();
        else zap3();
    }
}