//Kamil Kotowicz
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
int n,minw,roz;
struct wierzcholek{
    int f,s,co;
};
struct krawedz{
    int a,b,c;
};
wierzcholek d[501000];
vector<krawedz>wynik;
int rozd[1001000];
int rozu[1001000];
krawedz www;
int main(){
    ios::sync_with_stdio(false);
    read(&n);
    //cin>>n;
    for(int i=2;i<n;++i){
        read(&d[i].f);
        //cin>>d[i].f;
    }
    for(int i=2;i<n;++i){
        read(&d[i].s);
        //cin>>d[i].s;
        d[i].co=i;
    }
    sort(d,d+n,[](wierzcholek a,wierzcholek b){if(a.f+a.s!=b.f+b.s)return a.f+a.s<b.f+b.s;return a.f<b.f;});
    if(n==2){
        cout<<"TAK\n";
        cout<<1<<" "<<2<<" "<<1;
        return 0;
    }
    d[0].co=1;
    d[1].co=n;
    minw=d[2].f+d[2].s;
    rozd[minw]=1;
    rozu[minw]=n;
    for(int i=2;i<n;++i){
        if(d[i].f+d[i].s==minw){
            roz=d[i].s-d[i].f;
            if(roz>=0){
                if(rozd[roz]==0){
                    rozd[roz]=d[i].co;
                    www.a=d[i].co;
                    if(i==2){
                        www.b=1;
                        www.c=d[i].f;
                    }
                    else{
                        www.b=d[i-1].co;
                        www.c=d[i].f-d[i-1].f;
                    }
                    wynik.push_back(www);
                }
                else{
                    goto przypadek2;
                }
            }
            else{
                roz*=-1;
                if(rozu[roz]==0){
                    rozu[roz]=d[i].co;
                    www.a=d[i].co;
                    if(i==2){
                        www.b=1;
                        www.c=d[i].f;
                    }
                    else{
                        www.b=d[i-1].co;
                        www.c=d[i].f-d[i-1].f;
                    }
                    wynik.push_back(www);
                }
                else{
                    goto przypadek2;
                }
            }
            if(i+1==n||d[i+1].f+d[i+1].s!=minw){
                www.a=d[i].co;
                www.b=n;
                www.c=d[i].s;
                wynik.push_back(www);
            }
        }
        else{
            roz=d[i].s-d[i].f;
            if(roz>=0){
                //do jedynki lub srodek
                if(roz==minw){
                    www.a=d[i].co;
                    www.b=1;
                    www.c=d[i].f;
                    wynik.push_back(www);
                }
                else if(roz<minw&&rozd[roz]!=0){
                    www.a=d[i].co;
                    www.b=rozd[roz];
                    www.c=d[i].f-((minw-roz)/2);
                    wynik.push_back(www);
                }
                else{
                    goto przypadek2;
                }
            }
            else{
                //do n lub srodek
                roz*=-1;
                if(roz==minw){
                    www.a=d[i].co;
                    www.b=n;
                    www.c=d[i].s;
                    wynik.push_back(www);
                }
                else if(roz<minw&&rozu[roz]!=0){
                    www.a=d[i].co;
                    www.b=rozu[roz];
                    www.c=d[i].f-(minw+roz)/2;
                    wynik.push_back(www);
                }
                else{
                    goto przypadek2;
                }
            }
        }
    }
    cout<<"TAK\n";
    for(int i=0;i<wynik.size();++i){
        cout<<wynik[i].a<<" "<<wynik[i].b<<" "<<wynik[i].c<<"\n";
    }
    return 0;
    przypadek2:
    wynik.resize(0);
    roz=d[2].f-d[2].s;
    if(roz<0)roz*=-1;
    www.a=1;
    www.b=n;
    www.c=roz;
    wynik.push_back(www);
    minw=roz;
    for(int i=2;i<n;++i){
        roz=d[i].s-d[i].f;
        if(roz==0){
            cout<<"NIE";
            return 0;
        }
        else if(roz>0){
            if(roz==minw){
                www.a=d[i].co;
                www.b=1;
                www.c=d[i].f;
                wynik.push_back(www);
            }
            else{
                cout<<"NIE";
                return 0;
            }
        }
        else{
            roz*=-1;
            if(roz==minw){
                www.a=d[i].co;
                www.b=n;
                www.c=d[i].s;
                wynik.push_back(www);
            }
            else{
                cout<<"NIE";
                return 0;
            }
        }
    }
    cout<<"TAK\n";
    for(int i=0;i<wynik.size();++i){
        cout<<wynik[i].a<<" "<<wynik[i].b<<" "<<wynik[i].c<<"\n";
    }
}