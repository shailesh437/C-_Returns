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
vi X;
ll X_len;
ll dp[19][2][3];
ll solve(int index,bool tight, int remainder){ 
	if(index==X_len){
		return remainder==0?1:0;
	}
	if(dp[index][tight][remainder]!=-1){
		return dp[index][tight][remainder];
	}
	int ub = tight?X[index]:9;
	ll answer=0;
	for(int dig=0;dig<=ub;dig++){
		bool tight_1=tight;
		if(dig<X[index]){
			tight_1=false;
		}
		answer+=solve(index+1,tight_1,
			(remainder+dig)%3);

	}
	return dp[index][tight][remainder]=answer;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	
	while(TC--){
		ll L,R;
		cin>>L>>R;
		memset(dp,-1,sizeof(dp));
		L=L-1;
		while(L>0){
			int digit = L%10;
			X.push_back(digit);
			L=L/10;
		}
		X_len = X.size();
		reverse(X.begin(),X.end());
		ll L_ans = solve(0,1,0);
		
		X.clear();

		memset(dp,-1,sizeof(dp));
		while(R>0){
			int digit = R%10;
			X.push_back(digit);
			R=R/10;
		}
		X_len = X.size();
		reverse(X.begin(),X.end());
		ll R_ans = solve(0,1,0);
	    cout<<"\n L_ans = "<<L_ans<<" "<<" R_ans = "<<R_ans; 
		cout<<"::"<<R_ans-L_ans<<endl;
		X.clear();
		X_len=0;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
