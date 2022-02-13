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
long long maxProduct(vector<int> arr,int n){
	long long maxProduct=INT_MIN;
	long long localProduct=1;
	for(int i=0;i<n;i++){
		localProduct *= arr[i];
		maxProduct=max(maxProduct,localProduct);
		if(localProduct == 0){
			localProduct=1;
		}
	}
	localProduct=1;
	for(int i=n-1;i>0;i--){
		localProduct *= arr[i];
		maxProduct=max(maxProduct,localProduct);
		if(localProduct == 0){
			localProduct=1;
		}
	}
	return maxProduct;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> Arr = {6,-3,-10,0,2};
		//vector<int> Arr = {2, 3, 4, 5, -1, 0};
		//vector<int> Arr = {9 ,0 ,8 ,-1 ,-2 ,-2 ,6};
		vector<int> Arr = {0 ,3 ,-5 ,-2 ,8 ,-7 ,-6 ,-2 ,-3 ,-9};
		int N = 10;
		long long maxP = maxProduct(Arr,N);
		cout<<endl<<maxP;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
