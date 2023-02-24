/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
  set<int> setV;
 int getTotalTreeSum(TreeNode* root){
     if(!root) return 0;
     int ltSum = getTotalTreeSum(root->left);
     int rtSum = getTotalTreeSum(root->right);
     setV.insert(root->val+ltSum+rtSum);
     return root->val+ltSum+rtSum;
 }


int Solution::solve(TreeNode* A) {
int totalOfTree=getTotalTreeSum(A);
if(totalOfTree %2 ==1 ) return 0;
if(setV.find(totalOfTree/2)!=setV.end()) return 1;
return 0;
}
