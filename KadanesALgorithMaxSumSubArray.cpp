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

int getAnsByKadanes(int inp[],int size){
	int currentSum=0;
	int BestSum=0;
	for(int i=0;i<size;i++){
		if(inp[i]>=0 && (inp[i]+currentSum)>inp[i]){
			currentSum+=inp[i];
		}else{
			currentSum=inp[i];
		}
		if(currentSum>BestSum){
			BestSum = currentSum;
		}
	}
	return BestSum;
}

int main(){

clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		int n;
		cin>>n;
		int arr[n];
		loop(i,0,n-1) cin>>arr[i];
		cout<<endl;
		loop(i,0,n-1) cout<<" "<<arr[i];
		cout<<endl;
		int ans = getAnsByKadanes(arr,n);
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
