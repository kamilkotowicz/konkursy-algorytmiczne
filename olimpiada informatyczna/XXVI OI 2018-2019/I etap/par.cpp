#include <iostream>
using namespace std;
int q,n,m,s1,s2,kon,wyn,ktory,kon2,p,l,cykl,co;
int t[2][100005];
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n){
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}
int main(){
    ios::sync_with_stdio(false);
    read(&q);
    for(int i=0;i<q;++i){
        read(&n);
        read(&m);
        for(int j=0;j<n;++j){
            read(&(t[0][j]));
            t[0][j]&=1;
        }
        for(int j=0;j<m;++j){
            read(&(t[1][j]));
            t[1][j]&=1;
        }
        s1=0;
        s2=0;
        kon=min(n,m);
        kon2=max(n,m);
        wyn=0;
        for(int j=0;j<kon;++j){
            s1+=t[0][j];
            s1&=1;
            s2+=t[1][j];
            s2&=1;
            if(s1==s2){
                wyn=j+1;
            }
        }
        if(n<m)ktory=0;
        else ktory=1;
        co=t[ktory][0];
        l=-1;
        p=-1;
        for(int j=0;j<kon;++j){
            if(t[ktory][j]!=co){
                if(l==-1)l=j;
                p=j;
            }
        }
        if(l!=-1){
            wyn=max(wyn,max(kon-l-1,p));
        }
        ktory=1-ktory;
        l=-1;
        p=-1;
        co=t[ktory][0];
        for(int j=0;j<kon2;++j){
            if(t[ktory][j]!=co){
                if(l==-1)l=j;
                p=j;
            }
        }
        if(l!=-1){
            co=max(kon2-l-1,p);
            if(co<=kon){
                wyn=max(wyn,co);
            }
            else{
                co=kon;
                cykl=1;
                for(int j=co;j<kon2;++j){
                    if(t[ktory][j]!=t[ktory][j-co]){
                        cykl=0;
                        break;
                    }
                }
                if(cykl==0){
                    wyn=max(wyn,co);
                }
                else{
                    wyn=max(wyn,co-1);
                }
            }
        }
        cout<<wyn<<"\n";
    }
}