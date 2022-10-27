class Solution
{
    public:
    void storeInorder(Node* root, vector<int> &values){
        if(!root) return;
        storeInorder(root->left,values);
        values.push_back(root->data);
        storeInorder(root->right,values);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> values;
        storeInorder(root,values);
        return values[values.size()-K];
    }
};
