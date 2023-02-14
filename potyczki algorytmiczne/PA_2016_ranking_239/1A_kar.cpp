#include<iostream>
using namespace std;
int zap,talie,warunki,a,b,x,wynik;
int tab[100001];
int zlicz[100001];
char ch;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>zap;
	for(int i=0;i<zap;++i){
        cin>>talie>>warunki;
        for(int j=0;j<warunki;++j){
			cin>>a>>ch>>b;
			if(ch=='<')x=1;
            else x=0;
            if(x>tab[b])tab[b]=x;
            ++zlicz[b];
        }
        wynik=2;
        for(int j=1;j<=talie;++j){
            if(tab[j]==0){
				if(zlicz[j]<talie)wynik=1;
				else{
					wynik=0;
					break;
				}
            }

        }
        if(wynik==0)cout<<"WYGRANA\n";
        else if(wynik==1)cout<<"REMIS\n";
        else cout<<"PRZEGRANA\n";
        for(int j=0;j<100001;++j){
			tab[j]=0;
			zlicz[j]=0;
        }
	}
}
