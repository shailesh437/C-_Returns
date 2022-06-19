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
int FindMaxSum(int arr[], int n)
{
        // Your code here
	if(n==2){
		return max(arr[0],arr[1]);
	}
	if(n==1)
		return arr[0];
	
	int arr_run[n][3]; 

	arr_run[0][0]=arr[0];
	arr_run[0][1]=arr[0];
	arr_run[0][2]=0;

	arr_run[1][0]=arr[1];
	arr_run[1][1]=arr[1];
	arr_run[1][2]=arr[0];


	for(int i=2;i<n;i++){
		arr_run[i][0]=arr[i];
		arr_run[i][1]=arr[i]+max(arr_run[i-2][1],arr_run[i-2][2]);
		arr_run[i][2]=max(arr_run[i-1][1],arr_run[i-1][2]);
	}
 
	return max(arr_run[n-1][1],arr_run[n-1][2]);
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int n = 6;
		//int a[] = {5,5,10,100,10,5};
		int n = 9;
		int a[] = {8,6,4,10,2,8,10,1,30};
		cout<<FindMaxSum(a,n);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
