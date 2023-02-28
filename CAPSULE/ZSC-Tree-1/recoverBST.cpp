/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void inorder(TreeNode* A
                ,TreeNode* &prev1
                ,TreeNode* &first
                ,TreeNode* &second){
     if(!A) return;
     inorder(A->left,prev1,first,second);
     if(prev1!=NULL and prev1->val > A->val){
         if(first==NULL)
            first=prev1;
         second=A;
     }
     prev1=A;
     inorder(A->right,prev1,first,second);
 };
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ANS;
    TreeNode* prev1=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    inorder(A,prev1,first,second);
    ANS.push_back(second->val);
    ANS.push_back(first->val);
    return ANS;
}
