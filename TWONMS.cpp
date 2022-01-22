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
while(TC--){
		ll A,B,N;
		cin>>A>>B>>N;
		if(N&1){
			if(2*A>B){
				cout<<(2*A)/B<<endl;
			}else{
				cout<<(B/(2*A))<<endl;
			}
		}else{
			cout<<max(A,B)/min(A,B)<<endl;
		} 
	}
	return 0;
	}
