#include <bits/stdc++.h>
using namespace std;
int n;
string s1,s2;
int zlicz[300][2];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>s1>>s2;
    for(int i=0;i<n;++i)++zlicz[s1[i]][i%2];
    for(int i=0;i<n;++i)--zlicz[s2[i]][i%2];
    for(int i='a';i<='z';++i){
        if(zlicz[i][0]!=0||zlicz[i][1]!=0){
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
}