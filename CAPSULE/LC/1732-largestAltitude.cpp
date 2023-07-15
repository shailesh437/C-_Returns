class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int lastAlt=0;
        for(int i=0;i<gain.size();i++){
            ans=max(ans,gain[i]+lastAlt);
            lastAlt+=gain[i];
        }
        return ans;
    }
};
