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
		int N,K;
		cin>>N>>K;
		int A[N];
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		for(int i=0;i<N;i++){
			if(A[i]<=K){
				cout<<"1";
				K-=A[i];
			}else{
				cout<<"0";
			}
		} 
		cout<<endl;

	} 
	return 0;
	}
