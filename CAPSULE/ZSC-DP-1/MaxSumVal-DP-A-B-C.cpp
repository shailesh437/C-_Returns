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
int solve(vector<int> &A, int B, int C, int D) {
    vector<vector<int>> dp(3,vector<int> (A.size(),0));
    dp[0][0]=B*A[0];
    for(int i=1;i<A.size();i++){
        dp[0][i]=max(dp[0][i-1],B*A[i]);
    }
    cout<<dp[0][0]<<endl;
    

    dp[1][0]=dp[0][0]+C*A[0];
    cout<<dp[1][0]<<endl;
    dp[2][0]=dp[1][0]+D*A[0];
    cout<<dp[2][0]<<endl;
    for(int r=1;r<3;r++){
        for(int c=1;c<A.size();c++){
            if(r==1)
            dp[r][c]=max(dp[r][c-1],
                    max(dp[r-1][c]+C*A[c],
                        dp[r-1][c-1]+C*A[c]));
            else
            dp[r][c]=max(dp[r][c-1],
                    max(dp[r-1][c]+D*A[c],
                        dp[r-1][c-1]+D*A[c]));             
        	cout<<"dp["<<r<<"]["<<c<<"]="<<dp[r][c]<<endl;
        }
    }
    return dp[2][A.size()-1];
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A  = {11, -32, 34, 11, -5, -3, -28, 18, 31, 29};
		A={-21, 34, 3, 46, 8, -47, -47};
		int B = -28;int C = -15;int D = 0;
		B=-13;C=10;D=9;
		int ans = solve(A,B,C,D);
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
