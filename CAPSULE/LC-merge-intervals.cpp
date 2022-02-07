//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    bool sortCol(const vector<int>& v1, const vector<int>& v2){
	return v1[0]<v2[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),
    		intervals.end());
    vector<vector<int>> ans;
    vector<int> subAns(2);
    subAns[0] = intervals[0][0];
    subAns[1] = intervals[0][1];
        int cnt=0;
   // cout<<subAns[0];
    for(int i=1;i<intervals.size();i++){
			if(intervals[i][0]<=subAns[1]){
				subAns[1] = max(subAns[1],intervals[i][1]);
			}else{
				//cout<<endl<<"-pushing:"<<subAns[0]<<"-"<<subAns[1]<<endl;
				ans.push_back(subAns);
                cnt++;
				subAns[0] = intervals[i][0];
    			subAns[1] = intervals[i][1];	
			}
			//cout<<endl;
		}
	ans.push_back(subAns);
	return ans;	
    }
};
