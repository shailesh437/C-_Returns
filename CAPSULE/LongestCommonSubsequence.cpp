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
//int getLCS(string s1,string s2){
string getLCS(string s1,string s2){
	int dp[s1.length()+1][s2.length()+1];
	//vector<vector<int>> dp(s1.length()+1,vector<int> (s2.length()+1));
	memset(dp,0,sizeof dp);
	for(int i=s1.length()-1;i>=0;i--){
		for(int j=s2.length()-1;j>=0;j--){
			if(s1[i] == s2[j]){
				dp[i][j]=1+dp[i+1][j+1];
			}else{
				dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
			}
		}
	}
	/*for(int i=0;i<s1.length();i++){
		cout<<endl;
		logarr(dp[i],0,s2.length()-1);
	}*/
	vector<char> ansStringVector;
	for(int i=0;i<s2.length();i++){
		if(dp[0][i] != dp[0][i+1]){
			ansStringVector.push_back(s2[i]);
		}
	}
	/*for(int i=0;i<ansStringVector.size();i++){
		cout<<ansStringVector[i]<<" ";
	}*/
	//return dp[0][0];	
	string s(ansStringVector.begin(), ansStringVector.end());
 return s;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
			string s1 = "abcdeeefggg";
			string s2 = "abefoooohg";
			cout<<getLCS(s1,s2);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
