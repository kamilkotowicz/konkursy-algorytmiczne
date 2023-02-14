#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,poz;
const int mx=5e5+5;
int lewo[mx],prawo[mx];//1-lewo 2-prawo
int odw[mx],sl[mx],sp[mx];
int l,p,chcem,gdzie;
vector<int>ruchy;
long long wynik;
void brut(){
    vector<int>v;
    long long wyn=9e18;
    vector<int>best;
    int ppoz=poz;
    for(int i=1;i<=n;++i){
        v.push_back(i);
    }
    do{
        if(v[0]==ppoz){
            long long w=0;
            for(int i=1;i<=v.size();++i){
                if(v[i]>v[i-1]){
                    w+=prawo[i-1];
                }
                else{
                    w+=lewo[i-1];
                }
            }
            if(w<wyn){
                wyn=w;
                best.clear();
                best.resize(n);
                for(int i=0;i<n;++i){
                    best[i]=v[i];
                }
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<wyn<<"\n";
    for(int i=0;i<n;++i){
        cout<<best[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>poz;
    ruchy.push_back(poz);
    for(int i=0;i<n-1;++i){
        cin>>lewo[i]>>prawo[i];
    }
    if(n<=10){
        brut();
        return 0;
    }
    odw[poz]=1;
    l=1;
    p=n;
    for(int i=0;i<n-1;++i){
        while(odw[l]){
            ++l;
        }
        while(odw[p]){
            --p;
        }
        if(lewo[i]<prawo[i]){
            chcem=1;
        }
        else{
            chcem=2;
        }
        if(chcem==1){
            if(l>poz)chcem=2;
        }
        else{
            if(p<poz)chcem=1;
        }
        if(chcem==1){
            if(lewo[i+1]<prawo[i+1]){//ruch w lewo jak najbardziej w prawo
                gdzie=poz-1;
                while(odw[gdzie])--gdzie;
            }
            else{//ruch w lewo jak najbardziej w lewo
                gdzie=l;
            }
            wynik+=lewo[i];
        }
        else{
            if(lewo[i+1]<prawo[i+1]){//ruch w prawo jak nabardziej w prawo
                gdzie=p;
            }
            else{//ruch w prawo jak najbardziej w lewo
                gdzie=poz+1;
                while(odw[gdzie])++gdzie;
            }
            wynik+=prawo[i];
        }
        ruchy.push_back(gdzie);
        odw[gdzie]=1;
        poz=gdzie;
    }
    cout<<wynik<<"\n";
    for(int i=0;i<ruchy.size();++i){
        cout<<ruchy[i]<<" ";
    }
}