#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
int main(){ 
	int TC=1;
	//cin>>TC;
	while(TC--){
		int n,e=0,o=0;
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x&1){
				o++;
			}else{
				e++;
			}			
		}
		if(e>o){
				cout<<"READY FOR BATTLE"<<endl;
			}else{
				cout<<"NOT READY"<<endl;
			}
	} 
	return 0;
	}
