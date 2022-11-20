int Solution::solve(TreeNode* A) {
    if(!A) return 0;
    return 1+max(solve(A->left),solve(A->right));
}
