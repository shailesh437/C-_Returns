
class Solution
{
public:
    void storeInOrder(Node* root,vector<int> &V){
        if(!root) return;
        storeInOrder(root->left,V);
        V.push_back(root->data);
        storeInOrder(root->right,V);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> V1;
        vector<int> V2;
        storeInOrder(root1,V1);
        storeInOrder(root2,V2);
         map<int, int> v2map;
         for(int i=0;i<V2.size();i++){
             v2map[V2[i]]=1;
         }
         int ans=0;
         for(int i=0;i<V1.size();i++){
             int rem=x-V1[i];
             if(v2map[rem]>0) ans++;
         }
         return ans;
    }
};
