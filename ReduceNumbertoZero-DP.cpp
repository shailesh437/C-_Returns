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

vi getDigits(ll n){
	vi digitVector;
	while(n){
		int dig = n%10;
		digitVector.pb(dig);
		n/=10;
	}
	return digitVector;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		int n;
		cin>>n;
		vi dp(n+1,inf);
		for(int i=0;i<=9;i++){
			dp[i]=1;
		} 
		
		for(int i=10;i<=n;i++){
			vi digits = getDigits(i);
			for(int d:digits){
				if(d!=0)
				dp[i]=min(dp[i],1+dp[i-d]);
			}
		}
		cout<<dp[n];
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
