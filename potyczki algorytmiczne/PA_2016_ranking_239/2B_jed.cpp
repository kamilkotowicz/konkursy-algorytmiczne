#include<iostream>
using namespace std;
int n,x;
void wyswietl(int& x){
	if(x==1){
		cout<<"1";
		return;
	}
	else if(x==2){
		cout<<"1+1";
		return;
	}
	else if(x==3){
		cout<<"1+1+1";
		return;
	}
	else if(x%2==0){
		cout<<"(1+1)*(";
		x/=2;
		wyswietl(x);
		cout<<")";
		return;
	}else{
        cout<<"1+(1+1)*(";
        x/=2;
        wyswietl(x);
        cout<<")";
        return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x;
		wyswietl(x);
		cout<<"\n";
	}
}
