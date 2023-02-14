#include <iostream>
using namespace std;
//#define int long long
int n,m,k,x,a,b,wynik,aw,naw;
const int mx=255;
const int mp=9;
int typek[mx];
int pot[mx][mx][70];
int dojde[mx][mx];//skad dokad
int akt[mx][mx],stare[mx][mx],nieudane[mx][mx];
main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<k;++i){
        cin>>x;
        typek[x]=1;
    }
    for(int i=0;i<m;++i){
        cin>>a>>b;
        pot[a][b][0]=1;
    }
    for(int p=1;p<mp;++p){
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                for(int k=0;k<=n;++k){
                    pot[i][j][p]+=pot[i][k][p-1]*pot[k][j][p-1];
                }
            }
        }
    }
    int p=mp-1;
    for(int i=1;i<=n;++i){
        if(typek[i]==1){
            for(int j=1;j<=n;++j){
                dojde[i][j]=pot[i][j][p];
            }
        }
    }
    int dziala=0;
    for(int i=1;i<=n;++i){
        int ok=1;
        for(int j=1;j<=n;++j){
            if(typek[j]==1&&dojde[j][i]==0){
                ok=0;
                break;
            }
        }
        if(ok==1){
            dziala=1;
            break;
        }
    }
    if(dziala==0){
        cout<<"NIE";
        return 0;
    }
    wynik=(1LL<<p);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            stare[i][j]=dojde[i][j];
            dojde[i][j]=0;
        }
    }
    int pp;
    for(pp=p-1;pp>=0;--pp){
        for(int i=1;i<=n;++i){
            if(typek[i]==1){
                for(int j=1;j<=n;++j){
                    dojde[i][j]=pot[i][j][pp];
                }
            }
        }
        dziala=0;
        for(int i=1;i<=n;++i){
            int ok=1;
            for(int j=1;j<=n;++j){
                if(typek[j]==1&&dojde[j][i]==0){
                    ok=0;
                    break;
                }
            }
            if(ok==1){
                dziala=1;
                break;
            }
        }
        if(dziala==1){
            wynik=(1LL<<pp);
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    stare[i][j]=dojde[i][j];
                    dojde[i][j]=0;
                }
            }
        }
        else{
            break;
        }
    }
    //if(dziala==1){
    //    cout<<"TAK\n"<<wynik;
    //    return 0;
    //}
    aw=(1LL<<pp);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            akt[i][j]=pot[i][j][pp];
            nieudane[i][j]=akt[i][j];
        }
    }
    --pp;
    while(pp>=0){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dojde[i][j]=0;
            }
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j){
                for(int k=0;k<=n;++k){
                    dojde[i][j]+=nieudane[i][k]*pot[k][j][pp];
                }
            }
        }
        naw=aw+(1LL<<pp);
        int dziala=0;
        for(int i=1;i<=n;++i){
            int ok=1;
            for(int j=1;j<=n;++j){
                if(typek[j]==1&&dojde[j][i]==0){
                    ok=0;
                    break;
                }
            }
            if(ok==1){
                dziala=1;
                break;
            }
        }
        if(dziala==1){
            wynik=naw;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    stare[i][j]=dojde[i][j];
                    dojde[i][j]=0;
                }
            }
        }
        else{
            aw=naw;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    nieudane[i][j]=dojde[i][j];
                }
            }
        }
        --pp;
    }
    cout<<"TAK\n"<<wynik;
}