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
	bool click[1000];
	while(TC--){
		int N,K;
		cin>>N>>K;
		int twt[1000]={0};
		for(int i=0;i<1000;i++){
			twt[i]=0;
		}
		string str;
		string str2="CLICK";
		string str3="CLOSEALL";
		int ans=0;
		for(int i=0;i<K;i++){
			cin>>str;
			//cout<<"::"<<str;
			if(str2.compare(str)==0){
				int x;
				cin>>x;
				if(twt[x]==0){
					ans++;
					twt[x]=1;
				}else{
					ans--;
					twt[x]=0;
				}
			}else if(str3.compare(str)==0){
				ans=0;
				memset(twt,0,sizeof twt);
			}
			cout<<ans<<endl;
		}			
	} 
	return 0;
}
