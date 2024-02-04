#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
	// your code goes here
    int TC=1;
	cin>>TC;
	while(TC--){
		int K,N;
		cin>>K>>N;
		vector<vector<int>> dp(4,vector<int>(N+1,0));
		dp[1][1]=0;
		dp[1][2]=0;
		dp[1][3]=1;
		dp[2][1]=0;
		dp[2][2]=1;
		dp[2][3]=1;
		dp[3][1]=1;
		dp[3][2]=1;
		dp[3][3]=2;

		if(K==1 ) {
		    if(N%3==0){
		        cout<<1<<endl;
		        continue;
		    }
		    cout<<0<<endl;
		    continue;
		}
		if(K==2){
		    for(int i=4;i<=N;i++){
					dp[2][i]=dp[2][i-2]; //for 2 x 2
					
					 //for 1 x 3
						dp[2][i]+=dp[2][i-3];	
				    dp[2][i]%=MOD;
			    
			}
            cout<<dp[K][N]<<endl;
            continue;
		}
		
		if(K==3){
		    //there are 3 shapes for which we need to compute dp 
		    // 1 full rectangle .call it a A 
		    // rectangle with extra 2 x 1 block 
		    // rectangle with extra 1 x 1 block 
		    
		    vector<long long int> dp_A(N+1,0);
		    vector<long long int> dp_B(N+1,0);
		    vector<long long int> dp_C(N+1,0);
		    
		    //base cases 
		    dp_A[0]=dp_A[1]=dp_A[2]=1; // there's 1 way for no tiling , and 1 way for keeping 3 x 1 vertically 
		    
		    dp_B[0] = dp_B[1]=0;
		    dp_B[2]=1;
		    
		    dp_C[0]=0;dp_C[1]=0; 
		    dp_C[2]=0;
		    
		    for(int n=3;n<=N;n++){
		        dp_A[n]=dp_A[n-1]+dp_A[n-3]+2*dp_C[n-3];
		        
		        dp_B[n] = dp_B[n-3] + dp_A[n-2];
		        
		        dp_C[n] =  dp_C[n-3] + dp_B[n-1];
		        dp_A[n]%=MOD;
		        dp_B[n]%=MOD;
		        dp_C[n]%=MOD;
		    }
		    
		    cout<<dp_A[N]<<endl;
		    continue;
		}
			
        
		}  
	
	return 0;
}
