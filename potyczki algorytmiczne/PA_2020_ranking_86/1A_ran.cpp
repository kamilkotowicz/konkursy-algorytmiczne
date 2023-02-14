#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+2;
long long pref[sz];
long long n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>pref[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(pref[j]-pref[j-i]>pref[i]){
                cout<<"NIE";
                return 0;
            }
        }
    }
    cout<<"TAK\n"<<n<<"\n";
    for(int i=1;i<=n;++i){
        cout<<pref[i]-pref[i-1]<<" ";
    }
}