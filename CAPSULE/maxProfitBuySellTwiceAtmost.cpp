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

int maxProfitBuySellTwiceAtmost(int price[],int n){
	// For here 2 transactiosn allowed 
	// make profit array initalize to zero
	// From right to Left store the max Profit possible in subarray(i to N-1)
	// From Left to Right store the max Profit possible in subarray(0 to i)
	// considering the earlier profit 

	int profit[n];
	memset(profit,0,sizeof profit);

	// RIGHT TO LEFT	
	int max_price = price[n-1];
	for(int i=n-2;i>=0;i--){
		if(price[i]>max_price){
			max_price = price[i];
		}
		profit[i] = max(profit[i+1],max_price - price[i]);
	} 
//	cout<<endl;

//	logarr(profit,0,n-1);
	//Now scan from Left to Right 
	int min_price = price[0];
	for(int i=1;i<n;i++){
		if(min_price>price[i]){
			price[i] = min_price;
		}
		profit[i]=max(profit[i-1],profit[i] + (price[i]-min_price));
	}	
//	cout<<endl;
//	logarr(profit,0,n-1);
	int ans = profit[n-1];
	delete[] profit;
	return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int price[] = {10, 22, 4, 75, 65, 80};
		int price[] = {2,  30, 15, 10, 8, 25, 80};
		cout<<maxProfitBuySellTwiceAtmost(price,7);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
