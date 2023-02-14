#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m,m2,a,b,c,wsk;
long long jest,potrz;
const int mx=1e5+5;
struct szklanka{
    long long poj,temp;
};
szklanka bylo[mx],bedzie[mx];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    for(int z=0;z<t;++z){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a>>b>>c;
            bylo[i]={a,b};
            bedzie[i]={a,c};
        }
        sort(bylo,bylo+n,[](szklanka a,szklanka b){return a.temp<b.temp;});
        sort(bedzie,bedzie+n,[](szklanka a,szklanka b){return a.temp<b.temp;});
        m=n;
        m2=n;
        wsk=0;
        jest=0;
        potrz=0;
        for(int i=0;i<m2;++i){
            potrz+=bedzie[i].poj*bedzie[i].temp;
            long long zost=bedzie[i].poj;
            while(zost>0){
                while(bylo[wsk].poj==0){
                    ++wsk;
                    if(wsk==m){
                        cout<<"NIE\n";
                        goto dalej;
                    }
                }
                if(bylo[wsk].poj>=zost){
                    jest+=zost*bylo[wsk].temp;
                    bylo[wsk].poj-=zost;
                    zost=0;
                }
                else{
                    jest+=bylo[wsk].poj*bylo[wsk].temp;
                    zost-=bylo[wsk].poj;
                    bylo[wsk].poj=0;
                }
            }
            if(jest>potrz){
                cout<<"NIE\n";
                goto dalej;
            }
        }
        if(jest!=potrz){
            cout<<"NIE\n";
            goto dalej;
        }
        cout<<"TAK\n";
        dalej:;
    }
    return 0;
}