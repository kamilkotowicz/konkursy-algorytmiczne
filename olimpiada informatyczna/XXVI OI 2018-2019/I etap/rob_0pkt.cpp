#include <iostream>
using namespace std;
long long n,co;
long long t,x,y,pozx,pozy,pozt,cykle,modx,mody,sx,sy,nx,ny,wynik,minx,miny,minx2,miny2,maxx,maxy,maxx2,maxy2,konx,kony,fx;
long long tab[400015];
long long niesk=1e17;
#ifdef _WIN32
#define getc_unlocked getc
#endif
inline void read(long long *n)
{
    register char c = 0,
  znak_liczby=1;
    while (c < 33) c=getc_unlocked(stdin);

    if(c==45) {znak_liczby=-1;  c=getc_unlocked(stdin);}
    (*n) = 0;

  while (c>32) {(*n)=(*n)*10 + c-48; c=getc_unlocked(stdin);}

    (*n)*=znak_liczby;
}
inline int przetnie(long long sx,long long sy,long long nx,long long ny,long long x,long long y){
    if(sx==x&&sy==y){
        return 0;
    }
    minx=min(sx,nx);
    maxx=max(sx,nx);
    miny=min(sy,ny);
    maxy=max(sy,ny);
    if(minx<=x&&x<=maxx&&miny<=y&&y<=maxy)return 1;
    return 0;
}
long long ile(long long a,long long b,long long c,long long d){
    if(a>b)return 0;
    if(d<0)d*=-1;
    c+=d;
    if(c<0)c+=d*d;
    c%=d;
    a-=c;
    b-=c;
    a+=d*(niesk/d+1);
    b+=d*(niesk/d+1);
    return b/d-(a-1)/d;
}
inline int przetnie(long long sx,long long sy,long long nx,long long ny,long long x,long long y,long long cykle){
    minx=min(sx,nx);
    maxx=max(sx,nx);
    miny=min(sy,ny);
    maxy=max(sy,ny);
    if(sx!=nx){
        if(minx==sx)++minx;
        if(maxx==sx)--maxx;
    }
    else{
        if(miny==sy)++miny;
        if(maxy==sy)--maxy;
    }
    konx=x-(cykle-1)*pozx;
    kony=y-(cykle-1)*pozy;
    minx2=min(x,konx);
    maxx2=max(x,konx);
    miny2=min(y,kony);
    maxy2=max(y,kony);
    if(sx==nx){
        if(pozx==0){
            if(x!=sx)return 0;
            return ile(max(miny,miny2),min(maxy,maxy2),y,pozy);
        }
        else{
            fx=(sx-x)/pozx;
            if(minx2<=sx&&sx<=maxx2&&fx*pozx==sx-x){
                fx=fx*pozy+y;
                if(miny<=fx&&fx<=maxy){
                    return 1;
                }
            }
            return 0;
        }
    }
    else{
        if(pozy==0){
            if(y!=sy)return 0;
            return ile(max(minx,minx2),min(maxx,maxx2),x,pozx);
        }
        else{
            fx=(sy-y)/pozy;
            if(miny2<=sy&&sy<=maxy2&&fx*pozy==sy-y){
                fx=fx*pozx+x;
                if(minx<=fx&&fx<=maxx){
                    return 1;
                }
            }
            return 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    read(&n);
    read(&t);
    for(int i=0;i<n;++i){
        read(&(tab[i]));
    }
    for(int i=n;i<4*n;++i){
        tab[i]=tab[i-n];
    }
    n*=4;
    read(&x);
    read(&y);
    pozx=0;
    pozy=0;
    pozt=0;
    for(int i=0;i<n;++i){
        co=i&3;
        if(co==0){
            pozy+=tab[i];
        }
        else if(co==1){
            pozx+=tab[i];
        }
        else if(co==2){
            pozy-=tab[i];
        }
        else{
            pozx-=tab[i];
        }
        pozt+=tab[i]+1;
    }
    if(pozx!=0)modx=x%(abs(pozx));
    if(pozy!=0)mody=y%(abs(pozy));
    cykle=(t+1)/pozt;
    if(cykle>0){
        sx=0;
        sy=0;
        for(int i=0;i<n;++i){
            co=i&3;
            if(co==0){
                nx=sx;
                ny=sy+tab[i];
            }
            else if(co==1){
                nx=sx+tab[i];
                ny=sy;
            }
            else if(co==2){
                nx=sx;
                ny=sy-tab[i];
            }
            else{
                nx=sx-tab[i];
                ny=sy;
            }
            if(pozx==0&&pozy==0){
                if(przetnie(sx,sy,nx,ny,x,y)){
                    wynik+=cykle;
                }
            }
            else{
                if(przetnie(sx,sy,nx,ny,x,y,cykle)==1){
                    ++wynik;
                }
            }
            sx=nx;
            sy=ny;
        }
    }
    t-=pozt*cykle;
    sx=pozx*cykle;
    sy=pozy*cykle;
    for(int i=0;i<n;++i){
        if(t<=0)break;
        co=i&3;
        if(co==0){
            nx=sx;
            ny=sy+min(tab[i],t);
        }
        else if(co==1){
            nx=sx+min(tab[i],t);
            ny=sy;
        }
        else if(co==2){
            nx=sx;
            ny=sy-min(tab[i],t);
        }
        else{
            nx=sx-min(tab[i],t);
            ny=sy;
        }
        if(przetnie(sx,sy,nx,ny,x,y)){
            ++wynik;
        }
        sx=nx;
        sy=ny;
        t-=min(tab[i],t)+1;
    }
    if(x==0&&y==0)++wynik;
    cout<<wynik;
}