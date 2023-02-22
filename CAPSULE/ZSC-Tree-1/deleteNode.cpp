/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
TreeNode* Solution::solve(TreeNode* A, int B) {
     if(A==NULL) return NULL;
     if(A->val > B)  {
         A->left = solve(A->left,B);
     }else if(A->val < B)  {
         A->right = solve(A->right,B);
     }else{
         if(!A->left and A->right) return A->right;
         if(A->left and !A->right) return A->left;
         if(!A->left and !A->right) return NULL;
         TreeNode * maxInLeft = A->left;
         while(maxInLeft->right){
             maxInLeft=maxInLeft->right;
         }
         int tmp = maxInLeft->val;
          maxInLeft->val = A->val;
          A->val = tmp;
         A->left=solve(A->left,B);
         return A;
     }
     return A;
}
