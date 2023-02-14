#include <iostream>
using namespace std;
int t[2000005][31];
int tab[4000005],dol[4000005],gora[4000005],poc[4000005],kon[4000005];
int jed,zer,n,m,x;
long long wynik;
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read(&m);
    read(&n);
    for(int i=0;i<n;++i){
        read(&x);
        for(int j=0;j<m;++j){
            t[i][j]=x&1;
            x>>=1;
        }
        poc[i]=i;
        kon[i]=i+n-2;
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            tab[j]=t[j][i];
        }
        for(int j=n;j<n+n;++j){
            tab[j]=tab[j-n];
        }
        jed=-1;
        zer=-1;
        for(int j=0;j<2*n;++j){
            if(tab[j]==0){
                gora[j]=jed;
                zer=j;
            }
            else{
                gora[j]=zer;
                jed=j;
            }
        }
        jed=-1;
        zer=-1;
        for(int j=2*n-1;j>=0;--j){
            if(tab[j]==0){
                dol[j]=jed;
                zer=j;
            }
            else{
                dol[j]=zer;
                jed=j;
            }
        }
        for(int j=0;j<n;++j){
            if(dol[j]!=-1){
               poc[j]=max(poc[j],dol[j]);
            }
            if(gora[j+n-1]!=-1){
                kon[j]=min(kon[j],gora[j+n-1]-1);
            }
        }
    }
    for(int i=0;i<n;++i){
        if(poc[i]<=kon[i]&&kon[i]-poc[i]<n){
            wynik+=(long long)(kon[i]-poc[i]+1);
        }
    }
    cout<<wynik/2;
}