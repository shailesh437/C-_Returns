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
long long countTriplets(long long arr[], 
	int n, 
	long long sum)
{
	    // Your code goes here
	sort(arr,arr+n);
	long long ans=0;
	for(int i=0;i<n-2;i++){ 
		for(int j=i+1;j<n-1;j++){ 
			long long partialSum = arr[i]+arr[j];
			if(partialSum >=sum ){
				break;
			}
			long long remaining=sum-partialSum;			 
			int left=j+1; 
			auto upper = lower_bound(arr+left, arr + n, remaining);
			int temp = upper-(arr+left);
			//cout<<"\n temp = "<<temp<<endl;
			if(temp>0)
			ans += temp;
			else 
			break;	
			
		}
	}
	//cout<<endl<<"returning "<<ans<<endl;
	return ans;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int  N = 5;
		long long int sum = 12;
		long long int arr[] = {5, 1, 3, 4, 7};
		
	/*
		int  N = 4;
		long long int sum = 2;
		long long int arr[] = {-2, 0, 1, 3};*/
	
	cout<<countTriplets(arr,N,sum);
/*
	int gfg[] = { 1,3,4,5,7};
 
    
  
    auto upper = lower_bound(gfg+2, gfg+5, 8);
    cout<<(upper - (gfg+2));

    auto upper1 = lower_bound(gfg+3, gfg+5, 5);
    cout<<(upper1 - (gfg+3));*/

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
