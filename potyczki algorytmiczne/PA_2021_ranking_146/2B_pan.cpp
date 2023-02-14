#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
void solve(){
    cin>>n>>s;
    vector<int>v;
    int ind_lewy=-1,ind_prawy=-1,ind_1=-1;
    for(int i=0;i<s.size();++i){
        if(s[i]=='1'){
            if(ind_lewy==-1){
                ind_lewy=i;
            }
            else{
                int dziura=i-ind_1-1;
                if(dziura>0)v.push_back(dziura);
            }
            ind_1=i;
        }
    }
    ind_prawy=ind_1;
    if(ind_1==-1){
        cout<<0<<"\n";
        return;
    }
    int lewa_dziura=ind_lewy;
    int prawa_dziura=n-1-ind_prawy;
    int mniejsza_dziura=min(lewa_dziura,prawa_dziura);
    int wieksza_dziura=max(lewa_dziura,prawa_dziura);
    sort(v.begin(),v.end(),[](int a,int b){return a>b;});
    v.push_back(0);
    int t=0;
    int uratowani=0;
    //1
    //20
    //00110000010000010100
    for(int i=0;i<v.size();++i){
        if(wieksza_dziura>t&&2*wieksza_dziura+1>v[i]){//musi byc > a nie >= !!!!!!
            uratowani+=wieksza_dziura-t;
            ++t;
            wieksza_dziura=0;
        }
        if(mniejsza_dziura>t&&2*mniejsza_dziura+1>v[i]){//musi byc > a nie >= !!!!!!
            uratowani+=mniejsza_dziura-t;
            ++t;
            mniejsza_dziura=0;
        }
        int dl=v[i]-2*t;
        if(dl<1)break;
        if(dl==1){
            ++uratowani;
            break;
        }
        uratowani+=dl-1;
        if(dl>2)t+=2;
        else ++t;
    }
    cout<<n-uratowani<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<t;++i){
        solve();
    }
    return 0;
}