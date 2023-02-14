//Kamil Kotowicz
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k,a,b,c,skok,wsk1,wsk2,ile;
vector<int>poczatki;
vector<int>konce;
struct akcja{
int dlskoku,start,koniec,reszta;
};
int zlicz[101000];
akcja zap[101000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<k;++i){
        cin>>a>>b>>c;
        zap[i].start=a;
        zap[i].reszta=a%c;
        if(zap[i].reszta==0)zap[i].reszta=c;
        zap[i].koniec=a+b*c;
        zap[i].dlskoku=c;
    }
    sort(zap,zap+k,[](akcja a,akcja b){if(a.dlskoku<b.dlskoku)return true;if(a.dlskoku>b.dlskoku)return false;return a.reszta<b.reszta;});
    for(int i=0;i<k;++i){
        poczatki.resize(0);
        poczatki.resize(0);
        konce.resize(0);
        poczatki.push_back(zap[i].start);
        konce.push_back(zap[i].koniec);
        while((zap[i].dlskoku==zap[i+1].dlskoku)&&(zap[i].reszta==zap[i+1].reszta)){
            poczatki.push_back(zap[i+1].start);
            konce.push_back(zap[i+1].koniec);
            ++i;
        }
        sort(poczatki.begin(),poczatki.end());
        sort(konce.begin(),konce.end());
        poczatki.push_back(2000000000);
        konce.push_back(2000000000);
        skok=zap[i].dlskoku;
        wsk1=0;
        wsk2=0;
        ile=0;
        for(int poz=zap[i].reszta;poz<=n;poz+=skok){
            while(poczatki[wsk1]<=poz){
                ++wsk1;
            }
            while(konce[wsk2]<=poz){
                ++wsk2;
            }
            ile=wsk1-wsk2;
            zlicz[poz]+=ile;
        }
    }
    for(int i=1;i<=n;++i){
        cout<<zlicz[i]<<" ";
    }
    return 0;
}
