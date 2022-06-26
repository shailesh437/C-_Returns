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
void sortBySetBitCount(int arr[], int n)
{
        // Your code goes here
	 multimap<int,int,greater<int>> m;

	 for(int i=0;i<n;i++){
		int cntSetBits=__builtin_popcount(arr[i]);
		m.insert(make_pair(cntSetBits,arr[i]));		
	}
	int x=0;
	for(auto mp:m){
		arr[x++]=mp.second;
	} 
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
		int arr[] = {1, 2, 3, 4, 5, 6};
		int n= sizeof arr/sizeof arr[0];
		sortBySetBitCount(arr,n);
		for(int x: arr) cout<<x<<" ";
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
