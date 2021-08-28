#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std; 
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		int N,M,K;
		cin>>N>>M>>K;
		set<pair<int,int>> blockedCells;
		vector<vector<int>> dp(2,vector<int>(M,0));
		for(int i=0;i<K;i++){
			int x,y;
			cin>>x>>y;
			blockedCells.emplace(x-1,y-1);
		}
		pair<int,int> p(N-1,M-1);
		if(blockedCells.find(p) != blockedCells.end()){
			cout<<"0"<<endl;
			continue;
		}
		//using only 2 row dp array
		dp[1][M-1]=1;//destination
		
		//prepare the 2nd row of dp
		for(int i=M-2;i>=0;i--){
			pair<int,int> p(N-1,i);
			if(blockedCells.find(p) == blockedCells.end()){
				dp[1][i]=dp[1][i+1];
			}else{
				dp[1][i]=0;
			}
		}
		int flag=0;//to flip and use dp 2 rows
		for(int i=N-2;i>=0;i--){
			pair<int,int> p(i,M-1);
			if(blockedCells.find(p) == blockedCells.end()){
				dp[flag][M-1]=dp[1-flag][M-1];
			}else{
				dp[flag][M-1]=0;
			}
			//for every column from 2nd last column
			for(int j=M-2;j>=0;j--){
				pair<int,int> p(i,j);
				if(blockedCells.find(p) == blockedCells.end()){
					dp[flag][j]=((dp[1-flag][j])%MOD+(dp[flag][j+1])%MOD)%MOD;
				}else{
					dp[flag][j]=0;
				}		
			} 
			flag=1-flag;
		}
		cout<<dp[1-flag][0]<<endl;


	}
	return 0;
}
