#include<bits/stdc++.h>
//https://www.codechef.com/UADPIP01/problems/CHMX
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
        freopen("input_CHMX.txt", "r", stdin);
        freopen("output_CHMX.txt", "w", stdout);
    #endif
}
ll burst(vi &arr){
	int n = arr.size();
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	for(int len=0;len<arr.size();len++){
		for(int i=0,j=len;j<n;i++,j++){
			for(int k=i;k<=j;k++){
				ll left_range_ans = (k==i)?0:dp[i][k-1];
				ll right_range_ans = (k==j)?0:dp[k+1][j];
				ll curr_ans = ((i==0)?1:arr[i-1])*
				               ((j==n-1)?1:arr[j+1])*
				               arr[k];
				dp[i][j]=max(dp[i][j],
							 left_range_ans+right_range_ans+curr_ans); 
			}
		}
	}
	return dp[0][n-1];
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){ 
			int n;
			cin>>n;
			vi arr(n);
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			
			cout<<burst(arr)<<endl;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
