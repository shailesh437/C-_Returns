class Solution
{
    public:
    int sumTree(Node* root)
{ 
	if(!root) return 0;

	int LST =  sumTree(root->left);
	int RST =  sumTree(root->right);
    //cout<<endl<<"LST:"<<LST<<"::RST:"<<RST;
    
    return root->data+LST+RST;
}

bool isSumTree(Node* root)
    {
         // Your code here
         if(!root) return true;
         if(!root->left and !root->right) return true;
          
         if(root->data == sumTree(root->left)+
         				  sumTree(root->right))
         	return isSumTree(root->left) and 
                   isSumTree(root->right) and 
                   root->data == sumTree(root->left)+ sumTree(root->right);
         return false;				   
    }
};
