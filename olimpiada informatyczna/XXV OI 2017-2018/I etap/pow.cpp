//Kamil Kotowicz
#include <iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;
struct krawedz{
long long a,b,c;
};
krawedz kr[1001000];
int unia[1001000];
long long iloczyn[1001000];
int poziom[1001000];
long long a,b,c;
int n,m,k,wsk,fa,fb;
long long wynik;
const long long mod=1000000007;
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
inline void read(long long *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
int FIND(int a){
    if(unia[a]!=a)unia[a]=FIND(unia[a]);
    return unia[a];
}
void UNION(int a,int b){
    int x=FIND(a);
    int y=FIND(b);
    unia[x]=y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read(&m);
    read(&n);
    read(&k);
    //cin>>m>>n>>k;
    for(int i=0;i<m;++i){
        for(int j=0;j<n-1;++j){
            a=i*n+j;
            b=i*n+j+1;
            read(&c);
            //cin>>c;
            kr[wsk].a=a;
            kr[wsk].b=b;
            kr[wsk].c=c;
            ++wsk;
        }
    }
    for(int i=0;i<m-1;++i){
        for(int j=0;j<n;++j){
            a=i*n+j;
            b=i*n+j+n;
            read(&c);
            //cin>>c;
            kr[wsk].a=a;
            kr[wsk].b=b;
            kr[wsk].c=c;
            ++wsk;
        }
    }
    for(int i=0;i<m*n;++i){
        unia[i]=i;
    }
    sort(kr,kr+wsk,[](krawedz x,krawedz y){return x.c<y.c;});
    for(int i=0;i<wsk;++i){
        a=kr[i].a;
        b=kr[i].b;
        c=kr[i].c;
        if(iloczyn[a]==0)iloczyn[a]=c+1;
        else iloczyn[a]=min(iloczyn[a],c+1);
        if(iloczyn[b]==0)iloczyn[b]=c+1;
        else iloczyn[b]=min(iloczyn[b],c+1);
    }
    for(int i=0;i<wsk;++i){
        a=kr[i].a;
        b=kr[i].b;
        c=kr[i].c;
        fa=FIND(a);
        fb=FIND(b);
        if(fa!=fb){
            if(poziom[fa]!=0){
                iloczyn[fa]+=c-poziom[fa]+1;
                iloczyn[fa]%=mod;
            }
            if(poziom[fb]!=0){
                iloczyn[fb]+=c-poziom[fb]+1;
                iloczyn[fb]%=mod;
            }
            UNION(a,b);
            iloczyn[fb]*=iloczyn[fa];
            iloczyn[fb]%=mod;
            poziom[fb]=c+1;
        }
    }
    fa=FIND(kr[0].a);
    wynik=iloczyn[fa]+k-poziom[fa]+1;
    wynik%=mod;
    cout<<wynik;
}