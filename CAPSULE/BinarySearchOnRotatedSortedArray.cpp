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
 int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        //check if the range is good sorted 
        //cout<<"L="<<nums[low]<<":H="<<nums[high]<<":T="<<target;
        	while(low<=high){
        		int m = low+(high-low)/2;
        		if(target == nums[m]) return m;
        		if(target == nums[low]) return low;
        		if(target == nums[high]) return high;
        		//cout<<endl<<"a.1";
        		if((nums[low] < target) and (target<nums[high])){
        			//cout<<endl<<"nums[low]<target<nums[high]";
        			//cout<<endl<<nums[low]<<":"<<target<<":"<<nums[high];
        			if(target>nums[m]) 
        				low = m+1;
        			else 
        				high = m-1;	
        		}else {
        			//cout<<endl<<"b";
        			if(target<nums[m]){
        				if(nums[low]<nums[m] and nums[low]>target){
        					low = m+1;
        				}else{
        					high=m-1;
        				}
        			}else{
        				if((nums[low]<nums[m] and nums[low]<target)
        					or
        					(nums[m]<target and nums[high]>target)	
        					){
        					low = m+1;
        				}else{
        					high=m-1;
        				}
        			}
        		}
 
        	} //EOW
        return -1;
    }
  //567891234 
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
	    //vector<int> V = {4,5,6,7,0,1,2};
	  //  vector<int> V = {8,1,2,3,4,5,6,7};
		//vector<int> V = {5,1,3};
		//vector<int> V = {3,1};
		int target = 0;
		//int target = 3;
		//int target = 5;
	    //
		//vector<int> V = {8,1,2,3};
		//int target = 6;
		vector<int> V = {1,2,3,4,5};
		//int target = 2;
	for(int i=0;i<V.size();i++)
				cout<<endl<<search(V,V[i]);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
