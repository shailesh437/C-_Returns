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

int editDistance(string &s1,string &s2,int i,int j){
	int m=s1.size();
	int n=s2.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0){
				dp[i][j]=j;//base case ("",string)
			}else if(j==0){
				dp[i][j]=i;//base case (sting,"")
			}else if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}); 
			}

		}
	} 
	return dp[m][n];
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<"\n Ans = "<<editDistance(s1,s2,s1.size(),s2.size());
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
