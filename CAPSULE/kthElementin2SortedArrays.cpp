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
int kthElement(int arr1[], int arr2[], int n, int m, int K)
{
	if(K==1) return min(arr1[0],arr2[0]);
	if(K==m+n) return max(arr1[n-1],arr2[m-1]);
	if(arr1[0]>arr2[m-1]) {
		if(K<=m)
			return arr2[K-1];
		else{ 
			return arr1[K-m-1];
		}
	}
	if(arr2[0]>arr1[n-1]) {
		if(K<=n)
			return arr1[K-1];
		else
			return arr2[K-n-1];
	} 
	if(n>m)
		return kthElement(arr2,arr1,m,n,K);
	int low = max(0,K-m);
	int high = min(K,n);
	while(low<=high){
		int cut1 = (low+high)>>1;
		int cut2 = K-cut1;
		int l1 = cut1==0?INT_MIN:arr1[cut1-1];
		int l2 = cut2==0?INT_MIN:arr2[cut2-1];
		int r1 = cut1==n?INT_MAX:arr1[cut1];
		int r2 = cut2==m?INT_MAX:arr2[cut2];
		if(l1<=r2 and l2<=r1)
			return max(l1,l2);
		else if(l1>r2){
			high=cut1-1;
		}else{
			low=cut1+1;
		}	  
	}
	return 1;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int arr1[] = {2, 3, 6, 7, 9};
		//int arr2[] = {1, 4, 8, 10};
		int arr1[] = {5, 6, 7, 9};
		int arr2[] = {1, 2, 3, 4};
		int k = 8;
		int n = sizeof arr1 / sizeof arr1[0];
		int m = sizeof arr2 / sizeof arr2[0];
		cout<<kthElement(arr1,arr2,n,m,k);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
