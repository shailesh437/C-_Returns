/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMaxValNodeFromLeft(TreeNode* root){
        if(root->right)
            return getMaxValNodeFromLeft(root->right);
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val==key){
         if(!root->left and !root->right) return NULL;
         
         if(root->left and root->right){
            int maxVal = getMaxValNodeFromLeft(root->left);
             root->val=maxVal;
             root->left=deleteNode(root->left,maxVal);
             return root;
         }          
         else if(root->left){
             return root->left;
         }else
             return root->right;
         
     }else if(root->val < key)
         root->right = deleteNode(root->right,key);
      else
        root->left = deleteNode(root->left,key);  
        
	 return root;
        
    } 
};
