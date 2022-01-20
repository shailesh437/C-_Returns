#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
 
int main(){ 
	int TC;
	cin>>TC;
	std::vector<ll> v;
	while(TC--){
		int n;
		cin>>n;
		ll ans=1000000;
		for(int i=0;i<n;i++){
		    ll x;
		    cin>>x;
		    v.push_back(x);  
		}
		sort(v.begin(),v.end());
		ans= v[0]*(n-1);
		cout<<ans<<endl;
		v.clear();
	} 
	return 0;
	}
