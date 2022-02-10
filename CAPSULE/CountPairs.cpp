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
int getPairsCount(int arr[], int n, int k) {
	map<int,int> arrFreq;
	for(int i=0;i<n;i++){
		arrFreq[arr[i]] += 1;
	} 
	int ans=0;
	for(int i=0;i<n;i++){
		if(arrFreq[arr[i]]>0)
			arrFreq[arr[i]]-=1;
		int key =  k - arr[i];
		ans += arrFreq[key];		
	}

	return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int N = 4, K = 6;
		//int arr[] = {1, 5, 7, 1};
		int N = 4, K = 2;
		int arr[] = {1, 1, 1, 1};
		int ans = getPairsCount(arr,N,K);
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
