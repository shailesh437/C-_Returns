#include<iostream>
using namespace std;


int getTotalWays_BU_Optimized(int N, int dp[], int K) {
	dp[0]=dp[1]=1;
	for (int j = 1; j <= N; j++) {
		if(j<=K){
			dp[j]=2*dp[j-1];
			continue;	
		}
		dp[j]=2*dp[j-1]+dp[j-K-1];
	}
	return dp[N];
}

int main() {
	int N = 4;
	int K = 3;
	dp[100] = {0};
	cout << "\n getTotalWays BU = " << getTotalWays_BU(N, dp, K);
}
