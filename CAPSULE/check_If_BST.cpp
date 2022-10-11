class Solution
{
    public:
    
    
    int getMaxFromLeft(Node* root){
        if(root->right){
            return getMaxFromLeft(root->right);
        }
        return root->data;
    }
    
    int getMinFromRight(Node* root){
        if(root->left){
            return getMinFromRight(root->left);
        }
        return root->data;
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        if(!root) return true;
        int maxFromLeft,minFromRight;
        if(root->left){
            maxFromLeft=getMaxFromLeft(root->left);
            if(maxFromLeft>root->data) return false;
        }
        if(root->right){
            minFromRight=getMinFromRight(root->right);
            if(minFromRight<root->data) return false;
        }
        return isBST(root->left) and isBST(root->right);  
    }
};
