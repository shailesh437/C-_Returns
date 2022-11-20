vector<int> Solution::inorderTraversal(TreeNode* A) {
    	vector<int> ANS;
	if(!A) return ANS; 
	if(A->left==NULL and A->right == NULL ){
		ANS.push_back(A->val);
        return ANS;
    }    
    vector<int> LV = inorderTraversal(A->left);
    ANS.insert(ANS.end(),LV.begin(),LV.end());
    ANS.push_back(A->val);   
    vector<int> RV = inorderTraversal(A->right);
    ANS.insert(ANS.end(),RV.begin(),RV.end());
    return ANS;
}
