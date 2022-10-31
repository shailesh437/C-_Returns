
class Solution {
  public:
   void storeInorder(Node* root, vector<int> &values){
        if(!root) return;
        storeInorder(root->left,values);
        values.push_back(root->data);
        storeInorder(root->right,values);
    }
    
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        vector<int> values;
        storeInorder(root,values);
        if(values.size()<K ) return -1;
        return values[K-1];
    }
};
