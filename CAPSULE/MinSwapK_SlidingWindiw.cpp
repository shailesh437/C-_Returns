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
int minSwap(int arr[], int n, int k) {
        // Complet the function
	int eleCount=0;
	for(int i=0;i<n;i++){
		if(arr[i]<=k) eleCount++;
	}
	int global_ans=INT_MAX;
	int local_ans=0;
	int largeElem=0;
	for(int i=0;i<eleCount;i++){
		if(arr[i]>k){
			local_ans++; 
		}
	}
	global_ans = min(local_ans,global_ans);
	//cout<<endl<<eleCount<<" "<<local_ans<<endl;
	for(int i=1,j=eleCount;j<n;i++,j++){
		if(arr[j]>k){
			local_ans++;	
		} 
		if(arr[i-1]>k){
			local_ans--;	
		}
		//cout<<endl<<i<<" "<<j<<" "<<local_ans<<endl;

		global_ans = min(local_ans,global_ans); 
	}
	return global_ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int arr[] = {2, 5, 7, 1,0,  6, 3};
		int K=3;
		cout<<minSwap(arr,7,K);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
