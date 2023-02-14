#include<iostream>
using namespace std;
int n,x,wynik,poz;
int zlicz[300000];
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
    for(int i=0;i<n;++i){
        read(&x);
        //cin>>x;
        ++zlicz[x];
    }
    wynik=0;
    for(int i=0;i<=201718;++i){
        zlicz[i+1]+=zlicz[i]/2;
        if(zlicz[i]>0)wynik=i;
    }
    poz=201719;
    if(zlicz[poz]>0){
        while(zlicz[poz]>0){
            zlicz[poz+1]+=zlicz[poz]/2;
            ++poz;
        }
        cout<<poz-1;
    }
    else{
        cout<<wynik;
    }
}