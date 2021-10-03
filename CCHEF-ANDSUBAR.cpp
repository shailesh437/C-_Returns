#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
ll gethigestPowerOf2(ll n){ 
	ll ans=1;
	for(int i=1;i<30;i++){
		ans=1<<i;
		if(ans>n){
			ans = (1<<(i-1));
			break;
		}
	}
	return ans;
}
int main(){ 
	int TC;
	cin>>TC;
	while(TC--){ 
		ll N;
		cin>>N;
		ll maxPowOf2 = gethigestPowerOf2(N); 
		ll ans = max(maxPowOf2-(maxPowOf2>>1),N-maxPowOf2+1);
		cout<<ans<<endl;
	} 
	return 0;
}
