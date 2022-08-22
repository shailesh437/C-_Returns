class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      queue<Node*> NQ;
      NQ.push(node);
      vector<int> ANS;
      while(!NQ.empty()){
          ANS.push_back(NQ.front()->data);
          Node *temp=NQ.front();
          NQ.pop();
          if(temp->left!=NULL)
          NQ.push(temp->left);
          if(temp->right!=NULL)
          NQ.push(temp->right);
      }
      return ANS;
    }
};
