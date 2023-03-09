/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* root,bool &ans){
    if(!root or !ans) return -1;
    int LH = height(root->left,ans); 
    int RH = height(root->right,ans);
    if(abs(LH-RH)>1){
        ans=false;
    } 
    return 1+max(LH,RH);
} 

int Solution::isBalanced(TreeNode* A) {
    bool ans=true;
    height(A,ans);
    return ans;
}
