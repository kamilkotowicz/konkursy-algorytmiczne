#include <iostream>
using namespace std;
#ifdef _WIN32
#define getc_unlocked getc
#endif
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
int n,k,x,wyn;
int main(){
    ios::sync_with_stdio(false);
    wyn=2e9;
    read(&n);
    read(&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            read(&x);
            if(((j+1)*(i+1-j)<=k)&&x<wyn)wyn=x;
        }
    }
    cout<<wyn;
}