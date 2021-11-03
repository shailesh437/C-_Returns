#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
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

ll BLDJMPTD(vi inp,vi dp,ll BLG_NO,ll k){
	if(BLG_NO==0){
		return 0;
	}
	for(int j=1;j<=k;j++){
		if(BLG_NO-j<0){
			break;
		}
		dp[BLG_NO]=min(dp[BLG_NO],
					   BLDJMPTD(inp,dp,BLG_NO-j,k)
					   +abs(inp[BLG_NO]-inp[BLG_NO-j]));
	}
	return dp[BLG_NO];
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		ll N,k;
		cin>>N>>k;
		vi dp(N,inf); 
		vi inp(N);
		for(int i=0;i<N;i++){
			cin>>inp[i];
		}
		cout<<endl<<BLDJMPTD(inp,dp,N-1,k);

		/*dp[0]=0;
		for(int i=1;i<N;i++){
			for(int j=1;j<=k;j++){
				if((i-j)<0){
					break;
				}
				dp[i]=min(dp[i],
						  dp[i-j]+abs(inp[i]-inp[i-j]));
			}
		}
		cout<<dp[N-1]<<endl;*/
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
