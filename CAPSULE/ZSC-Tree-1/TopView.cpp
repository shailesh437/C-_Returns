/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int>> m;
    queue<pair<int,TreeNode*>> Q;
    Q.push(make_pair(0,A));
    TreeNode* dummy = new TreeNode(-1);
    Q.push(make_pair(0,dummy));
    while(Q.size()>1){
        auto frontQNode=Q.front();
        if(frontQNode.second!=dummy){
            m[frontQNode.first].push_back(frontQNode.second->val);
            if(frontQNode.second->left){
                Q.push(make_pair(frontQNode.first-1,
                                 frontQNode.second->left));
            }
            if(frontQNode.second->right){
                Q.push(make_pair(frontQNode.first+1,
                                 frontQNode.second->right));
            }
            Q.pop();
        }else{
            Q.pop();
            Q.push(make_pair(0,dummy));
        }
    }
     vector<int> ANS;
     for(auto it = m.begin();it!=m.end();it++){
         if(it->second.size()){
             ANS.push_back(it->second[0]);
         }
     }
     return ANS;
}
