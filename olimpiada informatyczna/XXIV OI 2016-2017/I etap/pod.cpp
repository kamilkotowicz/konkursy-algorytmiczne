//Kamil Kotowicz
#include<iostream>
#include<stdlib.h>

using namespace std;
int karty[1000000];
long long pref[1000000];
int poc,kon,sr,wynik,syst,zapytania,reszta;
long long ktora,suma,ileliczb;
int main(){
	ios::sync_with_stdio(false);
	cin>>syst>>zapytania;
    suma=0;
    ileliczb=0;
    for(int i=0;i<syst;++i){
		cin>>karty[i];
		suma+=(long long)((long long)(i)*(long long)(karty[i]));
		ileliczb+=karty[i];
    }
	reszta=suma%(syst-1);
    suma-=reszta;
    if(reszta!=0){
        --karty[reszta];
        --ileliczb;
    }
    pref[0]=karty[0];
    for(int i=1;i<syst;++i){
		pref[i]=pref[i-1]+karty[i];
    }

    for(int i=0;i<zapytania;++i){
		cin>>ktora;
        if(ktora>=ileliczb)cout<<-1<<endl;
        else{
			poc=0;
			kon=syst-1;
			wynik=-1;
			while(poc<=kon){
				sr=(poc+kon)/2;
				if(pref[sr]<=ktora){
					poc=sr+1;
					wynik=sr;
				}
				else{
					kon=sr-1;
				}
			}
			++ktora;
			if(wynik==-1)wynik=0;
			else if(ktora>pref[wynik]){
				++wynik;
				if(karty[wynik]==0)++wynik;
			}
			cout<<wynik<<endl;
        }
    }
}
