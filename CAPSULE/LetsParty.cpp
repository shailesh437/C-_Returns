/*
In Danceland, one person can party either alone or can pair up with another person.

Can you find in how many ways they can party if there are A people in Danceland?

Note: Return your answer modulo 10003, as the answer can be large.
  */

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
int MOD=10003;
vector<int> dp(100000,-1);
int solve(int A) {
	if(A<=2){
		return dp[A]=A;
	}
	if(dp[A]!=-1) return dp[A];

	return  dp[A]=(solve(A-1)%MOD+(solve(A-2)*(A-1))%MOD)%MOD;

}

int solve1(int A) {
	if(A<=2){
		return  A;
	} 
	return   (solve(A-1)%MOD+(solve(A-2)*(A-1))%MOD)%MOD;

}


int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		cout<<endl<<solve(5);
		cout<<endl<<solve(3);
		cout<<endl<<solve(15);
		//dp=vector<int>(10001,-1);
		cout<<endl<<solve(10000);

	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
