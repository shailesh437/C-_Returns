#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
//https://leetcode.com/problems/next-permutation/
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
//1st try to find dip while scanning from right to left 
//then sort from that point 
//then compare on both sides of that break point, is there's eligible condition to swap the elements as we want increasing lexo seq
//Finally if required just sort as the given seq is already max possible Lexo
 void nextPermutation(vector<int>& nums) {
        int count=0;
        bool desc=true; 
        for(int i = nums.size()-1;i>0;i--){ 
        	if(nums[i]>nums[i-1]){
        		desc = false;
        		auto it = nums.begin();
        		while(count<=(i-1)){
        			it++;count++;
        		}
        		sort(it,nums.end());
        		break;
        	}
        }         
        if(!desc){ 
        	/*cout<<endl<<count<<" \n";
        	cout<<endl<<nums[count]<<" "<<nums[count-1];
*/
        	for(int j=count-1;j>=0;j--){
        			for(int i = count;i<nums.size();i++){
        				//cout<<endl<<nums[i]<<" "<<nums[j];
        				if(nums[i]>nums[j]){
        				swap(nums[j],nums[i]);
        				return;
        			}
        		}
        	}
        }else{
        	sort(nums.begin(),nums.end());
        } 
    }

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
			//vector<int> nums =  {1, 3, 2}; //213 
			//vector<int> nums =  {2,3,1}; // 312
			//vector<int> nums =  {1, 2, 3, 6, 5, 4};  
			vector<int> nums =    {4, 2, 0, 2, 3, 2, 0};
			nextPermutation(nums);
			cout<<endl;
			for(int x:nums) cout<<x<<" ";

	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
