#include <bits/stdc++.h>
using namespace std;
#define ll int
//#define MOD 20011
int R,C,d;

int dp[301][301][301][2];
vector<vector<ll>> mat;
int MOD=20011;
  int solve(ll row, 
	ll col, 
	ll count,
	ll direction 
	) {

	if (row > R or col > C or (mat[row][col] == 0) or count>d) {
		return 0;
	} 

	if (row == R and col == C) {
       	return  1;
	}

    if (dp[row][col][count][direction] != -1) 
    	return dp[row][col][count][direction];
    	
    	


    int ans = 0;
    if (direction == 0) {
    	ans = (solve(row, col + 1, count + 1,0) % MOD +
    		solve(row + 1, col,  1,1) % MOD) % MOD;
    } else {
    	ans = (solve(row + 1, col, count + 1,1 ) % MOD +
    		solve(row, col + 1,1,0) % MOD) % MOD;
    }
    return dp[row][col][count][direction] = ans;  
}
 


int main() {
	// your code goes here
	cin>>R>>C>>d;
	mat = vector<vector<ll>>(R+1,
			vector<ll>(C+1,-1));
	/*	dp = vector<vector<vector<vector<ll>>>> (R+1,
			vector<vector<vector<ll>>>(C+1,
				vector<vector<ll>>(d+1,
				vector<ll>(2,-1))));*/

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cin >> mat[i][j];
				for(int k=0;k<=d;k++){
				    dp[i][j][k][0]=-1;
				    dp[i][j][k][1]=-1;
				}
			}
		}
		
	// int ans =  solve(1, 1, 0, 0)%MOD;	
	 int ans =  solve(1, 2, 1, 0)%MOD ;
	 ans += solve(2, 1, 1, 1)%MOD;
	 ans %= MOD;
		cout << ans <<endl; 	
		
	//dp.clear();
	mat.clear();

}
