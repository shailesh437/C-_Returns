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
ll MOD=1e9+7;
ll modExpo(ll base,ll power){
	if(power==0) return 1*1ll;
	if(power==1) return base;
	ll ans=((base%MOD)*(base%MOD))%MOD;
	if(power%2==0){
		return modExpo(ans,power/2); 
	}
	return (base%MOD*modExpo(ans,power/2))%MOD;
}


ll reduce_B_factorial_modM(ll b, ll MOD_reduce_1){
	ll result=1*1ll;
	for(ll i=b;i>=1;i--){
		result*=(i%MOD_reduce_1);
		result%=MOD_reduce_1;
	}
	return result;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int A=2;
		int B=27;
		ll MOD_reduce_1=MOD-1;
		ll newPower=reduce_B_factorial_modM(B*1ll,MOD_reduce_1);
		
		ll final_ans=modExpo(A*1ll,newPower);
		cout<<final_ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
