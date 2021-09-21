#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18 
using namespace std; 

ll GCD_fn(ll a,ll b){
	if(a%b==0){
		return b;
	}
	return GCD_fn(b,a%b);
}

int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		ll a,b;
		cin>>a>>b;
		ll GCD,LCM;
		if(a>b)
			GCD=GCD_fn(a,b);
		else
			GCD=GCD_fn(b,a);
		LCM = 	(a*b)/GCD;
		cout<<GCD<<" "<<LCM<<endl;

	} 
return 0;
}
