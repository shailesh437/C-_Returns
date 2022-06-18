#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
    set<vector<int>> main_ans;
	unordered_map<int,vector<int>> index_map;
	for(int m=0;m<arr.size();m++){
				index_map[arr[m]].push_back(m);
	} 
	for(int i=0;i<=arr.size()-4;i++){ 
		for(int j=i+1;j<=arr.size()-3;j++){
			
			for(int m=j+1;m<=arr.size()-2;m++){ 
				int pendingSum=k-(arr[i]+arr[j]+arr[m]);
				if(index_map[pendingSum].size()>0){
					for(int idx=0;idx<index_map[pendingSum].size();idx++){
						if(index_map[pendingSum][idx]>m){
							multiset<int> mset;
							mset.insert(arr[i]);
							mset.insert(arr[j]);
							mset.insert(arr[m]);
							mset.insert(pendingSum);
							vector<int> indV(mset.begin(),mset.end()); 
							main_ans.insert(indV);
							//index_map[pendingSum].erase(index_map[pendingSum].begin()+idx);	
						}
					}
				} 
			}
			//index_map.clear();
		}   
	} 
	vector<vector<int>> main_ans_V(main_ans.begin(),main_ans.end());
	
	return main_ans_V;
    }
};
 vector<vector<int> > fourSum(vector<int> &arr, int k) { //optimized 
        // Your code goes here
    set<vector<int>> main_ans;
	sort(arr.begin(),arr.end());  
	for(int i=0;i<=arr.size()-4;i++){ 
		for(int j=i+1;j<=arr.size()-3;j++){
		    int start=j+1;
		    int end = arr.size()-1;
		    int partialSum=arr[i]+arr[j];
		    while(start<end){ 
		        if( (partialSum+arr[start]+arr[end])==k){
		            
		            vector<int> v1(4);
		            v1[0]=arr[i];v1[1]=arr[j];
		            v1[2]=arr[start];v1[3]=arr[end];
		            main_ans.insert(v1);
		            v1.clear();
		            start++;
		            end--;
		        }else if(partialSum+arr[start]+arr[end]<k) start++;
		        else end--;
		    }
		 
		}   
	}  
	vector<vector<int>> main_ans_V(main_ans.begin(),main_ans.end());
	return main_ans_V;
    }
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
