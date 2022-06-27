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
int minSwaps(vector<int>&nums)
{
	    // Code here
	int ans=0;
	vector<pair<int,int>> numsCopy(nums.size());
	for(int i=0;i<nums.size();i++){
		numsCopy[i]={nums[i],i};
	} 
	sort(numsCopy.begin(),numsCopy.end());
	for(int i=0;i<nums.size();i++){
		if(numsCopy[i].second!=i){
			swap(numsCopy[i],numsCopy[numsCopy[i].second]);
			i--;
			ans++;
		}
	} 
	return ans;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> nums = {10, 19, 16, 3, 5};
		//vector<int> nums = {2, 8, 5, 4};
		cout<<minSwaps(nums);
		//qwiksort(nums,0,3);
		//for(int x:nums) cout<<x<<" ";
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
