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

bool checkIfAnySubArrayWithZeroSum(int arr[],int n){
	int sum=arr[0];
	map<int,int> m; 
	m[arr[0]]++;
	for(int i=1;i<n;i++){
		sum += arr[i];
		cout<<endl;
	    cout<<arr[i]<<" sum = "<<sum<<" :: "<<m[sum];
		if(sum==0 || m[sum]>0){
			return 1;
		}
		m[sum]++;
	}
	return 0;
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int arr[] = {4,2,-3,1,6};
		//int arr[] = {49,-7,-1,18,-10,5,2};
		int arr[] = {9 ,-6 ,-48 ,-48 ,-44 ,34 ,-29 ,-8 ,
			        18 ,-22 ,39 ,22 ,-42 ,8 ,48 ,-14 ,-42 ,
			        3 ,-2 ,-47 ,-17 ,-17 ,-2 ,40 ,4 ,17, -4};
		//int arr[] = {1,2,3,4,5};
		bool check=checkIfAnySubArrayWithZeroSum(arr,27);
		if(check){
			cout<<"YES";
		}else cout<<"NO";
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
