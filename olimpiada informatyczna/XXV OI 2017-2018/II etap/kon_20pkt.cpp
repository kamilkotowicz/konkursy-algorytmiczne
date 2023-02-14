#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
set<pair<int,int>>secik;
const int niesk=2000000000;
const int mod=1000000007;
int t,n,m,a,b,akt,wynik;
vector<pair<int,int>>v;
long long dpd,aaa,bbb;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    for(int zap=0;zap<t;++zap){
        v.resize(0);
        cin>>m>>n;
        for(int i=0;i<n;++i){
            cin>>a>>b;
            v.push_back(make_pair(b,a));
        }
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){if(a.first!=b.first)return a.first<b.first;return a.second>b.second;});
        akt=-1;
        wynik=0;
        for(int i=0;i<v.size();++i){
            if(v[i].second>=akt){
                ++wynik;akt=max(v[i].first,akt);
            }
        }
        cout<<wynik<<" 0\n";
    }
}