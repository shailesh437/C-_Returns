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
 int minJumps_DP(int arr[], int n){
 	 int dp[n];
 	 for(int i=0;i<n;i++){
 	 	dp[i]=INT_MAX;
 	 }
 	 dp[0]=0;
 	 for(int i=1;i<n;i++){
 	 	for(int j=0;j<i;j++){
 	 		if(arr[j] != INT_MAX and arr[j]+j>=i){
 	 			if(dp[j]+1<dp[i])
 	 			dp[i]=dp[j]+1;
 	 		}
 	 	}
 	 }
 	 if(dp[n-1]!=INT_MAX)
 	 	return dp[n-1];
 	return -1;
 }

  int minJumps_O_OF_N(int arr[], int n){
 	   int maxReach=arr[0];
 	 int jump=1;
 	 int stepRemaining=arr[0];
 	  if(n == 1 ) return 0;
 	 if(arr[0] == 0 ) return -1;
 	
 	 for(int i=1;i<n;i++){
 	 	if(i==n-1) return jump;
 	 	maxReach = max(maxReach,i+arr[i]);
 	 	stepRemaining--;
 	 	if(stepRemaining==0){
 	 		jump++;
 	 		if(i>=maxReach){
 	 			return -1;
 	 		}
 	 		stepRemaining  = maxReach-i; 
 	 	}
 	 }
 	 return jump;
 }
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int N = 6;
		//int arr[] = {1, 4, 3, 2, 6, 7};
		//int arr[] = {1 ,3 ,5 ,8 ,9 ,2 ,6 ,7 ,6 ,8 ,9};//ans=3 , n=11
		int arr[] = {2 ,3 ,1 ,1 ,2 ,4 ,2 ,0 ,1 ,1}; //ans = 4,N=10

		int N=10;
		cout<<minJumps_DP(arr,N);
		cout<<minJumps_O_OF_N(arr,N);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
