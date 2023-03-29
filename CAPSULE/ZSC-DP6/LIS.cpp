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

int LIS(const vector<int> &A,
			 int index,
			 vector<int> &dp){
	if(index==0) return 1;
	if(dp[index]!=-1) return dp[index];
	int ans=0;
	for(int i=0;i<index;i++){
		if(A[index]>A[i])
			ans=max(ans,LIS(A,i,dp)); 
	}
	if(ans==0){
		return dp[index]=LIS(A,index-1,dp);	
	}
	return dp[index]=ans+1;
}

int lis(const vector<int> &A) {
	vector<int> dp(A.size(),-1);
	//dp[0]=1;
	return LIS(A,A.size()-1,dp);
}

int lis_tab(const vector<int> &A) {
	vector<int> dp(A.size(),0);
	dp[0]=1;
	for(int i=1;i<A.size();i++){
		dp[i]=1;
		for(int j=0;j<=i;j++){
			if(A[i]>A[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	int ans=INT_MIN;
	for(int i=0;i<dp.size();i++)
	ans=max(ans,dp[i]);
	return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
		A={1,2,3,4,5,6,0,10,90,100,1120,11140,700000};
		A={1,2,6,4,5,6,0};
		//int ans = lis(A);
		int ans = lis_tab(A);
		cout<<endl<<"ANS = "<<ans;	
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
