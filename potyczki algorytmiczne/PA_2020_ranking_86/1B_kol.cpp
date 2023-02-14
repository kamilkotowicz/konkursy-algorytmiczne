#include <bits/stdc++.h>
using namespace std;
const int BASE=(1<<20);
int n,m,a,b,c,wyn;
int d[2*BASE][4];
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
void wstaw(int l,int p,int k){
    a+=BASE;
    b+=BASE;
    ++d[a][k];
    if(a!=b)++d[b][k];
    while (a/2!=b/2) {
        if (a %2==0)++d[a + 1][k];
		if (b % 2 == 1)++d[b - 1][k];
		a /= 2;
		b /= 2;
	}
}
int policz(int a,int k){
	int wynik = 0;
	a += BASE;
	while (a > 0) {
		wynik += d[a][k];
		a /= 2;
	}
	return wynik;
}
int main(){
    ios::sync_with_stdio(false);
    read(&n);
    read(&m);
    //cin>>n>>m;
    for(int i=0;i<m;++i){
        read(&a);
        read(&b);
        read(&c);
        //cin>>a>>b>>c;
        wstaw(a,b,c);
    }
    for(int i=1;i<=n;++i){
        if(policz(i,1)>=1&&policz(i,2)>=1&&policz(i,3)<1)++wyn;
    }
    cout<<wyn;
}