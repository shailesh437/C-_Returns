#include<bits/stdc++.h>
using namespace std;


int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		string S,T;
		cin>>S>>T;
		vector<vector<int>> dp(2,vector<int>(T.length()+1,0));
		int flag=0;
		for(int s_ptr=0;s_ptr<=S.length();s_ptr++){
			for(int t_ptr=0;t_ptr<T.length();t_ptr++){
				if(S[s_ptr]==T[t_ptr]){
					dp[1-flag][t_ptr+1]=1+dp[flag][t_ptr];
				}else{
					dp[1-flag][t_ptr+1]=max(dp[1-flag][t_ptr],
											dp[flag][t_ptr+1]);
				}				
			}
			flag=1-flag;
		}

		cout<<dp[1-flag][T.length()]<<endl;
	}
	return 0;
	}
