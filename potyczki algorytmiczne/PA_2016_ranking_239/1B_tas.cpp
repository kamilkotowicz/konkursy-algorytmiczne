#include<iostream>
#include<cstdio>
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
using namespace std;
int a,b,ile;
int tab[1048576];
inline void read(int *n)
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
int main(){
	ios::sync_with_stdio(false);

	//cin>>a>>b;
	read(&a);
	read(&b);
	ile=1<<a;
	for(int i=0;i<ile;++i){
		read(&tab[i]);
		//cin>>tab[i];
	}
	if(b%2==0){
		for(int i=0;i<ile;++i){
			cout<<tab[i]<<" ";
		}
	}	else{
		for(int i=ile-1;i>=0;--i){
			cout<<tab[i]<<" ";
		}
	}
}
