#include<iostream>
using namespace std;
string s,s1,s2;
inline bool prime(string sx){
    long long x=0;
    for(int i=0;i<sx.size();++i){
        x*=10;
        x+=sx[i]-48;
    }
    if(x<=1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(long long i=3;i*i<=x;i+=2){
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size()-1;++i){
        s1="";
        for(int j=0;j<=i;++j){
            s1+=s[j];
        }
        s2="";
        for(int j=i+1;j<s.size();++j){
            s2+=s[j];
        }
        if(s1[0]=='0'||s2[0]=='0')continue;
        if(prime(s1)&&prime(s2)){
            cout<<"TAK";
            return 0;
        }
    }
    cout<<"NIE";
}