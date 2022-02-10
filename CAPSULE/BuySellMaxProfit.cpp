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

int maxProfit(vector<int>& prices) {
 int maxProfit =0;
 int cp = prices[0];
 for(int i=1;i<prices.size();i++){
 	if(prices[i]-cp > maxProfit){
 		maxProfit = prices[i]-cp; 
 	}else{
 		cp = min(cp,prices[i]);
 	}
 }
 return maxProfit;
 }

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> prices = {7,6,5,3,6,4,2,15};
		int ans = maxProfit(prices);
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
