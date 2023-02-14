#include<iostream>
using namespace std;
int n,x;
int gdzie1,gdzie2;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    gdzie1=gdzie2=-1;
    for(int i=1;i<=n;++i){
        cin>>x;
        if(x==1){
            if(gdzie1==-1)gdzie1=i;
            else if(gdzie2==-1)gdzie2=i;
        }
    }
    if(gdzie2!=-1){
        cout<<0<<"\n"<<2<<"\n";
        //cout<<gdzie1<<" "<<gdzie2;
    }
    else if(gdzie1!=-1){
        if(gdzie1==1)gdzie2=2;
        else gdzie2=1;
        cout<<1<<"\n"<<2<<"\n";
       // cout<<gdzie1<<" "<<gdzie2;
    }
    else{
        gdzie1=1;
        gdzie2=2;
        cout<<2<<"\n"<<2<<"\n";
        //out<<gdzie1<<" "<<gdzie2;
    }
    cout<<1<<" "<<2;
}