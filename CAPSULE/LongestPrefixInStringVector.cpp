class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
         std::sort(strs.begin(), strs.end(), [](const std::string &s1, const std::string &s2)              {return s1.size() < s2.size(); });
        
        for(int i=0;i<strs[0].length();i++){
            bool match=true; 
            for(int j=1;j<strs.size();j++){
                 if(strs[j][i]==strs[0][i]){
                     continue;
                 }else{
                     match=false;
                     break;
                 }
             }
            if(match){
                ans += strs[0][i];
            }else{
                break;
            }
        }
        return ans;
    }
};
