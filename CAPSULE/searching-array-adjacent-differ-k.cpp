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
//k - atleast k diff 
//x - to be search
int search(int arr[], int n, int x, int k){
		for(int i=0;i<n;){
				if(arr[i]==x) return i;
				i+=max(1,(arr[i]-x)/k);	
		}
		return -1;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int arr[] = {2, 4, 5, 7, 7, 6};
		int x = 4;
		int k = 2;
		int n = sizeof(arr)/sizeof(arr[0]);
		cout << "Element " << x  << " is present at index "
		<< search(arr, n, x, k);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
