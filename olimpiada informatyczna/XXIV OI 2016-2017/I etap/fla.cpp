//Kamil Kotowicz
#include <iostream>
using namespace std;
struct przeszkoda{
int poz,dol,gora,minh,maxh;
};
int main()
{
	ios::sync_with_stdio(false);
	int ileprzeszkod,meta;
	int nieudane=0;
	cin>>ileprzeszkod>>meta;
	przeszkoda* prz=new przeszkoda[ileprzeszkod];
	for(int i=0;i<ileprzeszkod;++i){
        cin>>prz[i].poz>>prz[i].dol>>prz[i].gora;
        if(prz[i].poz>meta)ileprzeszkod=i;
	}
	int i=ileprzeszkod-1;
	if(i==-1){
        cout<<0;
        delete[] prz;
        return 0;
	}
	int minh=prz[i].dol+1;
	if((minh+prz[i].poz)%2==1)++minh;
	int maxh=prz[i].gora-1;
	if((maxh+prz[i].poz)%2==1)--maxh;
	prz[i].minh=minh;
	prz[i].maxh=maxh;
	if(minh>maxh)nieudane=1;
	int kand=ileprzeszkod-1;
	for(int i=ileprzeszkod-2;i>=0;--i){
        int minh=prz[i].dol+1;
        if((minh+prz[i].poz)%2==1)++minh;
        int maxh=prz[i].gora-1;
        if((maxh+prz[i].poz)%2==1)--maxh;
        prz[i].minh=max(minh,prz[i+1].minh+prz[i].poz-prz[i+1].poz);
        prz[i].maxh=min(maxh,prz[i+1].maxh+prz[i+1].poz-prz[i].poz);
        if(prz[i].minh+prz[i].poz>prz[kand].minh+prz[kand].poz)kand=i;
        if(prz[i].minh>prz[i].maxh){
			nieudane=1;
			break;
        }
	}
	minh=prz[0].minh-prz[0].poz;
	maxh=prz[0].maxh+prz[0].poz;
	if(minh>0||maxh<0)nieudane=1;
	if(nieudane==1){
		cout<<"NIE";
	}
	else{
        cout<<max((prz[kand].poz+prz[kand].minh)/2,0);
	}
    delete[] prz;
}
