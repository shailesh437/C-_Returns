class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        m.clear();
        for(int n:nums){
            m[n]++;
        }
        int ans=0;
        for(auto it=m.begin();it!=m.end();it++){
            int x = it->first;
            if(2*x==k){
                while(m[x]>=2){
                    m[x]-=2;
                    ans++;
                }
            }else while(m[k-x]>0 and m[x]>0  ){
                m[k-x]--;
                m[x]--;
                ans++;
            }
        }
        return ans;
    }
};
