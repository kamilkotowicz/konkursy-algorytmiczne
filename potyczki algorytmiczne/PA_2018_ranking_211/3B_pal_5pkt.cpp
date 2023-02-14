#include<iostream>
#include<cstdio>
#include<cmath>
#define double long double
using namespace std;
int n;
char ch;
//const double N=33554432;
const double N=16;
const double eps=0.0001;
const double PI=3.1415926535897932384626433832795028841971693993751;
struct zesp{
    double re,im;
};
zesp p1,p2,podst,p3,h1,h2,podst2;
zesp dodaj(zesp a,zesp b){
    return {a.re+b.re,a.im+b.im};
}
zesp odejmij(zesp a,zesp b){
    return {a.re-b.re,a.im-b.im};
}
zesp mnoz(zesp a,zesp b){
    return {a.re*b.re-a.im * b.im,a.re*b.im+a.im*b.re};
}
zesp dziel(zesp a,zesp b){
    return{(a.re*b.re+a.im*b.im)/(b.re*b.re+b.im*b.im),(a.im*b.re-a.re*b.im)/(b.re*b.re+b.im*b.im)};
}
zesp pot(zesp a,int b){
    if(b==0)return{1,0};
    if(b==1)return a;
    zesp wyn=pot(a,b/2);
    if(b%2==0)return mnoz(wyn,wyn);
    else return mnoz(wyn,mnoz(wyn,a));
}
inline void solve(){
    p1=mnoz(p1,podst);
    p2=mnoz(p2,podst2);
    p3={ch,0};
    h1=dodaj(h1,mnoz(p1,p3));
    h2=dodaj(h2,mnoz(p2,p3));
}
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
    //cin>>n;
    read(&n);
    p1={1,0};
    p2={1,0};
    podst={cos(2.0*PI/N),sin(2.0*PI/N)};
    podst2={cos(-2.0*PI/N),sin(-2.0*PI/N)};
    if(n==0){
        ch=getchar();
        while(ch>='a'&&ch<='z'){
            ++n;
            solve();
            ch=getchar();
        }
    }
    else{
        ch=getchar();
        while(ch>='a'&&ch<='z'){
            solve();
            ch=getchar();
        }
    }
    h2=mnoz(h2,pot(podst,n+1));
    if(abs(h1.re-h2.re)<eps&&abs(h1.im-h2.im)<eps)cout<<"TAK";
    else cout<<"NIE";
}