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
int longestSubarray(vector<int>& nums) {
	//check sum;
	 /*
	 use sliding window 
	 at max there should be single zero in every window 
	 */
	int left=0;
	int maxLen=0;
	int zeroCount=0;
	for(int right=0;right<nums.size();right++){
		if(nums[right]==0){
			zeroCount++;
		}
		while(zeroCount>1){
			if(nums[left]==0)
				zeroCount--;
			left++;

		}
		maxLen=max(maxLen,right-left);
	}
	return maxLen;

}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A={1,1,1};
		//A={0,0,1,1,1,0,1,1,1,0,0,1};
		A={0,1,1,1,0,1,1,0,1};
		///A={0,0,1,1};
		A={1,0};
		int ans = longestSubarray(A);
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
