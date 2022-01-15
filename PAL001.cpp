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
		int n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++){			
			cin>>s[i];	
		}
		for(int i=0;i<n;i++){			
			string tempStr = s[i];
			reverse(tempStr.begin(),tempStr.end());
			if(tempStr.compare(s[i]) == 0){
				cout<<"wins";
			}else{
				cout<<"loses";
			}
			cout<<endl;	
		}

	} 
	return 0;
}
