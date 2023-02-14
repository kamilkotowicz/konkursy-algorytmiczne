#include <bits/stdc++.h>
using namespace std;
const int mx=3e5+5;
string s;
int za[mx],zb[mx],zc[mx];
int a,b,c;
long long wynik;
long long solve(){
    long long w=0;
    char ost='d';
    int seria=0;
    for(int i=0;i<s.size();++i){
        if(s[i]==ost){
            ++seria;
        }
        else{
            seria=1;
            ost=s[i];
        }
        w+=seria;
    }
    return w;
}
long long solve2(char a, char b, char c){
    long long w=0;
    map<int,int>bilans;
    bilans[0]=1;
    int bil=0;
    for(int i=0;i<s.size();++i){
        if(s[i]==c){
            bilans.clear();
            bilans[0]=1;
            bil=0;
        }
        else{
            if(s[i]==a)++bil;
            else --bil;
            auto it=bilans.find(bil);
            if(it!=bilans.end()){
                w+=bilans[bil];
                ++bilans[bil];
            }
            else{
                bilans[bil]=1;
            }
        }
    }
    return w;
}
long long solve3(){
    long long w=0;
    map<pair<pair<int,int>,int>,int>mapa;
    mapa[{{0,0},0}]=1;
    int a=0,b=0,c=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='a')++a;
        else if(s[i]=='b')++b;
        else ++c;
        int m=min(min(a,b),c);
        a-=m;
        b-=m;
        c-=m;
        pair<pair<int,int>,int> klucz={{a,b},c};
        auto it=mapa.find(klucz);
        if(it!=mapa.end()){
            w+=mapa[klucz];
            ++mapa[klucz];
        }
        else{
            mapa[klucz]=1;
        }
    }
    return w;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='a')++a;
        else if(s[i]=='b')++b;
        else ++c;
        za[i]=a;
        zb[i]=b;
        zc[i]=c;
    }
    wynik+=solve();
    wynik+=solve2('a','b','c');
    wynik+=solve2('a','c','b');
    wynik+=solve2('b','c','a');
    wynik+=solve3();
    cout<<wynik;
    return 0;
}