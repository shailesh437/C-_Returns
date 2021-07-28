//https://www.codechef.com/COOK131C/problems/CHFGCD
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getGcd(ll a,ll b){
	if(a==0){
		return b;
	}
	return getGcd(b%a,a);
}
int main(){
	ll TC;
	cin>>TC;
	while(TC){
		ll a,b;
		cin>>a>>b;
		int eventCount = 0;
		eventCount+=(a&1==0);
		eventCount+=(b&1==0);
		if( eventCount == 2 ){
			cout<<"0"<<endl;
		}else{
			if( eventCount == 1 ){
				cout<<"1"<<endl;
			}else{
				int checkGcd = getGcd(a,b);
				if(checkGcd>1){
					cout<<"0"<<endl;		
				}else{
					if(getGcd(a+1,b)>1 || getGcd(a,b+1)>1){
						cout<<"1"<<endl;	
					}else{
						cout<<"2"<<endl;	
					}
				}
			}
		}	

		TC=TC-1;
	}
	return 0;
}
