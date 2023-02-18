/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::solve(TreeNode* A) {
    queue<TreeNode*> Q;
    Q.push(A);
    map<int,vector<int>> m;
   // m[0].push_back(A->val);
    TreeNode* dummynode = new TreeNode(-1);
    Q.push(dummynode);

    int level=0;
    int lvl=1;
    while(Q.size()>1){
        TreeNode* frontNode = Q.front();
        Q.pop();
        if(frontNode==dummynode){
            level++;
            Q.push(dummynode);
        }else{
            m[level].push_back(frontNode->val);
            if(frontNode->left)  Q.push(frontNode->left);
            if(frontNode->right)  Q.push(frontNode->right);
        }         
    }
    vector<vector<int>> ANSV;
    vector<int> ANSVsub;
    for(auto it=m.begin();it!=m.end();it++){
        ANSVsub=it->second;
        ANSV.push_back(ANSVsub);
    }
    return ANSV;
}
