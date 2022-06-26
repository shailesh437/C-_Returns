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
vector<long long int> productExceptSelf
				(vector<long long int>& nums, 
					int n) {

        //code here
	long long int forwardProduct[n];
	long long int backwardProduct[n];
	long long int p=1;
	forwardProduct[0]=1;
	for(int i=1;i<n;i++){
		p=p*nums[i-1];
		forwardProduct[i]=p;    
	}
	p=1;
	backwardProduct[n-1]=1;
	for(int i=n-2;i>=0;i--){
		p=p*nums[i+1];
		backwardProduct[i]=p;    
	}
	vector<long long int>  ans(n);
	for(int i=0;i<n;i++){
		ans[i]=forwardProduct[i]*backwardProduct[i];
	}

	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//ll n = 5;
		//vector<ll> nums = {10, 3, 5, 6, 2};
		ll n = 2;
		vector<ll> nums = {12,0};
		vector<ll> ans = productExceptSelf(nums,n);
		for(ll x: ans) cout<<x<<" ";
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
