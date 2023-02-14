#include <bits/stdc++.h>
using namespace std;
int n,zera,jedynki,bilans,ile,ile2;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='0')++zera;
        else ++jedynki;
    }
    bilans=jedynki-zera;
    if(bilans>4*n||bilans<(-2)*n)cout<<"NIE";
    else{
        while(bilans>0){
            if(bilans%4==2){
                cout<<"g";
                bilans-=2;
            }
            else{
                cout<<"o";
                bilans-=4;
            }
            ++ile;
        }
        while(bilans<0){
            cout<<"a";
            bilans+=2;
            ++ile;
        }
        ile2=n-ile;
        for(int i=0;i<ile2;++i){
            cout<<"c";
        }
    }

    return 0;
}