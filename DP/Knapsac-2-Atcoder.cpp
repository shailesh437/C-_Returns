#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
//https://atcoder.jp/contests/dp/tasks/dp_e

void file_i_o()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		ll N,W;
		cin>>N>>W;
		vi Val(N),Wt(N);
		loop(i,0,N-1) cin>>Wt[i]>>Val[i];
		vi dp1(N*1000+1,inf),dp2(1000*N+1,inf);
		dp1[0]=0;
		dp1[Val[0]] = Wt[0];
		loop(i,0,N-1){
			loop(j,0,N*1000){ //similar to weight array, here we explore value array
				if(Val[i]>j){
					dp2[j]=dp1[j];
				}else{
					dp2[j]=min(dp1[j],Wt[i]+dp1[j-Val[i]]);
				}
			}
			dp2.swap(dp1);
			fill(dp2.begin(),dp2.end(),inf);
		}
		ll ans=0;
		loop(i,0,N*1000){
			if(dp1[i]<=W) ans=i;
		}
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
