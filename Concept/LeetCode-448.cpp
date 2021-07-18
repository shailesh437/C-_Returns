//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums){
		map<int,int> m;
		vector<int>  res; 
		for(int i=1;i<=nums.size();i++){
			m[i]=0;
		}
		for(auto it = nums.begin();it!=nums.end();it++){
			if(m.find(*it) == m.end()){
				m[*it] =1;	
			}else{
				m[*it]+=1; 			
			}
		}



		int lastnum = nums.size(); 
		nums.clear();
		int j=0; 
		for(int i=1;i<=lastnum;i++){
			if( m[i] == 0){
				nums.push_back(i);
				j++;	 				
			} 
		} 
		return nums;

	}
};

int main(){
	vector<int> inp = {4,3,2,7,8,2,3,1};
	Solution s ;
	vector<int> res = s.findDisappearedNumbers(inp); 
	for(int x: res){
		cout<<x<<" ";
	}
	return 0;
}
