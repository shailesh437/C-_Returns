/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
bool checkValidBST(TreeNode* A,long long int min,long long int max){
    if(!A) return true;
    if(min<A->val and max>A->val){
        return checkValidBST(A->left,min,A->val) and 
               checkValidBST(A->right,A->val,max) ;
    }
    return false;
}
int Solution::isValidBST(TreeNode* A) { 
    if(!A) return 1;
    return checkValidBST(A,1e10*-1,1e10); 
}
