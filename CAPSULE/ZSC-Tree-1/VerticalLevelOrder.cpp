/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>> m;
    TreeNode* root = A;
    TreeNode* dummy = new TreeNode(-1);
    queue<pair<TreeNode*,int>> Q;
    Q.push(make_pair(root,0));
    Q.push(make_pair(dummy,0));
    int level=0;
    while(Q.size()>1){
        auto qfrontNode = Q.front();
        if(qfrontNode.first!=dummy){
            m[qfrontNode.second].push_back(qfrontNode.first->val);
            if(qfrontNode.first->left){
                Q.push(make_pair(qfrontNode.first->left,
                              qfrontNode.second-1));
            }
            if(qfrontNode.first->right){
                Q.push(make_pair(qfrontNode.first->right,
                              qfrontNode.second+1));
            }
            Q.pop();
        }else{
            level++;
            Q.pop();
            Q.push(make_pair(dummy,0));
        }
        
    }
    vector<vector<int> > ANS;
    for(auto it=m.begin();it!=m.end();it++){
        ANS.push_back(it->second);
    } 
    return ANS;
}
