//Kamil Kotowicz
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
pair<pair<int,int>,int>pr[1001000];
priority_queue<pair<pair<int,int>,int>>q;
int n,k,war,wynik;
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
pair<pair<int,int>,int>qt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    read(&n);
    read(&k);
    //cin>>n>>k;
    for(int i=0;i<n;++i){
        read(&pr[i].first.first);
        read(&pr[i].first.second);
        //cin>>pr[i].first.first>>pr[i].first.second;
        pr[i].second=i+1;
    }
    sort(pr,pr+n,[](pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){return a.first.second>b.first.second;});
    for(int i=0;i<k-1;++i){
        q.push(make_pair(make_pair(pr[i].first.first,pr[i].first.second),pr[i].second));
    }
    for(int i=k-1;i<n;++i){
        q.push(make_pair(make_pair(pr[i].first.first,pr[i].first.second),pr[i].second));
        qt=q.top();
        q.pop();
        war=pr[i].first.second-qt.first.first;
        wynik=max(wynik,war);
    }
    while(!q.empty())q.pop();
    for(int i=0;i<k-1;++i){
        q.push(make_pair(make_pair(pr[i].first.first,pr[i].first.second),pr[i].second));
    }
    for(int i=k-1;i<n;++i){
        q.push(make_pair(make_pair(pr[i].first.first,pr[i].first.second),pr[i].second));
        qt=q.top();
        war=pr[i].first.second-qt.first.first;
        if(war==wynik){
            break;
        }
        q.pop();
    }
    cout<<wynik<<"\n";
    while(!q.empty()){
        cout<<q.top().second<<" ";
        q.pop();
    }
}