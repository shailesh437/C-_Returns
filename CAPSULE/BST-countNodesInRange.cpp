class Solution{
public:
void storeInorder(Node* root,vector<int> &V){
    if(!root) return;
    storeInorder(root->left,V);
    V.push_back(root->data);
    storeInorder(root->right,V);
}
    int getCount(Node *root, int l, int h)
    {
      // your code goes here
      int start=0;
      vector<int> V;
      storeInorder(root,V);
      while(V[start]<l){
          start++;
      }
      int end=V.size()-1;
      while(V[end]>h){
          end--;
      }
      int ans = end-start+1;
      if(ans<0) return 0;
      return end-start+1;
    }
    
};
