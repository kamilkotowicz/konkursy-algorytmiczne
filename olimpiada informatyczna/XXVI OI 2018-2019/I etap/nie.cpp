#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int mx=1000005;
const int lit=4;
const int alfa=500;
vector<int>wynik;
vector<pair<int,int>>stos;
string s1,s2;
int n,m,wsk1,wsk2,co,k1,k2,w1,w2,bf,bs;
int t1[mx],t2[mx],dol[mx],gora[mx],prawy[lit][mx],prawy2[lit][mx];
int liczba[alfa];
char znak[lit]={'A','C','G','T'};
void preprocess(){
    liczba['A']=0;
    liczba['C']=1;
    liczba['G']=2;
    liczba['T']=3;
    for(int i=0;i<s1.size();++i){
        t1[i+1]=liczba[s1[i]];
    }
    n=s1.size();
    for(int i=0;i<s2.size();++i){
        t2[i+1]=liczba[s2[i]];
    }
    m=s2.size();
    t1[0]=0;
    t2[0]=0;
    for(int i=0;i<lit;++i){
        prawy[i][n]=(t1[n]==i) ? n : -1;
        for(int j=n-1;j>=0;--j){
            prawy[i][j]=(t1[j]==i) ? j : prawy[i][j+1];
        }
        prawy2[i][m]=(t2[m]==i) ? m : -1;
        for(int j=m-1;j>=0;--j){
            prawy2[i][j]=(t2[j]==i) ? j : prawy2[i][j+1];
        }
    }
}
int solve(int a,int b,int c,int d){
    if(a>b||c>d)return 0;
    int wynik=stos.size();
    w1=a;
    w2=c;
    while(w1<=b&&w2<=d){
        co=prawy2[t1[w1]][w2];
        if(co!=-1&&co<=d){
            w2=co;
            dol[w1]=w2;
            gora[w2]=w1;
            stos.push_back({w1,w2});
            ++w1;
            ++w2;
        }
        else{
            ++w1;
        }
    }
    k1=b;
    k2=d;
    wynik=stos.size()-wynik;
    while(stos.size()>0){
        bf=stos.back().first;
        bs=stos.back().second;
        if(bf<a||bs<c)break;
        if(solve(bf+1,k1,bs+1,k2)!=0)continue;
        while(t1[k1]!=t2[bs])--k1;
        while(t2[k2]!=t1[bf])--k2;
        dol[bf]=0;
        gora[bs]=0;
        dol[k1]=k2;
        gora[k2]=k1;
        --k1;
        --k2;
        stos.pop_back();
    }
    return wynik;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>s1>>s2;
    preprocess();
    int x=solve(0,n,0,m);
    for(int i=1;i<=n;++i){
        if(dol[i]!=0){
            cout<<znak[t1[i]];
        }
    }
}