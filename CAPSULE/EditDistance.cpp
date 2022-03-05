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

int dp[101][101];
int editD(string &s, string &t,int m, int n) {
        // Code here
	if(m == 0) return n;
	if(n == 0) return m;
	if(dp[m][n] != -1) return dp[m][n];
	if(s[m-1]==t[n-1]){
		return dp[m][n]=editD(s,t,m-1,n-1);
	}

	return dp[m][n]= 1 +min(
							editD(s,t,m-1,n-1),
							min(editD(s,t,m,n-1),
								editD(s,t,m-1,n)
								)			
							);
}
int editDistance(string s, string t) {
        // Code here
	memset(dp,-1,sizeof dp);
	int ans = editD(s,t,s.length(),t.length());
	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		/*string s1="geeksgeek";
		string s2="geeks";*/
		string s1="ecfbefdcfca";
		string s2="badfcbebbf";

		 /*
		string s1="geek";
		string s2="gesek";*/

		int ans = editDistance(s1,s2);
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
