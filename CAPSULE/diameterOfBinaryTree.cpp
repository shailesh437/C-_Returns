
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int getExtreme(Node* leftSide){
        if(leftSide == NULL ) return 0;
        if(leftSide->left == NULL  and leftSide->right== NULL ) return 0;
        if(leftSide->left!= NULL ) return 1 + getExtreme(leftSide->left);
        if(leftSide->right!= NULL ) return 1 + getExtreme(leftSide->right);
        return 0;
    } 
    
    int diameter(Node* root) {
        // Your code here
         queue<Node*> bt;
         bt.push(root);
         int mainAns=INT_MIN;
         while(!bt.empty()){
             Node* popped=bt.front();
             if(popped->left != NULL ) bt.push(popped->left);
             if(popped->right!= NULL ) bt.push(popped->right);
             
             int LL=(popped->left==NULL)?0:(1+getExtreme(popped->left));
             int RL=(popped->right==NULL)?0:(1+getExtreme(popped->right));
             if((LL+RL+1)>mainAns){
                 mainAns=LL+RL+1;
             }
             bt.pop();
             
         }
         return mainAns;
    }
};
