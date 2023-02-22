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
    vector<int> ANS;
    TreeNode* curr = A;
    while(curr){
        if(!curr->left){
            ANS.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode* temp = curr->left;
            while(temp->right and temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right=curr;
                curr=curr->left;
            }else{
                temp->right=NULL;
                ANS.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ANS;
}
