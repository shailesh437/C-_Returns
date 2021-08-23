//https://www.spoj.com/problems/ACODE/


#include<bits/stdc++.h>
using namespace std;
int dp[5001];
int solve(string s){
	//int j=0;  
	dp[0]=1;
	if((s[0]-'0')>0)
		dp[1]=1;
	for(int i=2;i<=s.length();i++){ 
		dp[i]=dp[i-1];	
		int x = (s[i-2] - '0')*10 + (s[i-1] - '0');
		if(10<x && x<=26){
			dp[i]+=dp[i-2];	
		}

		if(s[i-1]=='0'){
			if(i-2>0)
				dp[i]=dp[i-2];
			else dp[i]=1;
		}
	}
		return dp[s.length()];
	}

	int main(){
		while(1){
			string s;
			cin>>s;
			if(s.compare("0")==0){
				break;
			}
			memset(dp,0,sizeof(dp));
			cout<<solve(s)<<endl;
		}
		return 0;
	}
