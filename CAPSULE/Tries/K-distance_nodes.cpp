#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	cout<<endl;for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  }; 


 bool findTarget(TreeNode* root, int X,vector<TreeNode*> &path){
     if(!root ) return false;
     
     if(root->val==X) { 
         path.push_back(root);
         return true;
     }
     if(findTarget(root->left,X,path)){
            path.push_back(root);
            return true;
     }
     if(findTarget(root->right,X,path)){
            path.push_back(root);
            return true;
     }
     return false;
 }
 void getC_distanceAwayNodes(TreeNode* root,
                             int distance_C,
                             TreeNode* skipNode,
                             vector<int> &c_distance_Nodes){
      if(!root or distance_C<0 or root==skipNode) return;
      if(distance_C==0){
          c_distance_Nodes.push_back(root->val);
          return;
      }
      getC_distanceAwayNodes(root->left,distance_C-1,skipNode,c_distance_Nodes);                           
      getC_distanceAwayNodes(root->right,distance_C-1,skipNode,c_distance_Nodes);                           

 }
vector<int> solve(TreeNode* A, int B, int C) {
    TreeNode* targetNode;
    vector<TreeNode*> path;
    findTarget(A,B,path);
    vector<int> c_distance_Nodes;
    cout<<endl;
    for(int i=0;i<path.size();i++){
    	cout<<path[i]->val<<" ";
        getC_distanceAwayNodes(path[i],C-i,
                              i==0?NULL:path[i-1],
                              c_distance_Nodes );
    }   
    return c_distance_Nodes;
}
void inorder(TreeNode* root){
	if(!root) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
			TreeNode * root = new TreeNode(1);
			root->left=new TreeNode(2);
			root->right=new TreeNode(3);
			root->left->left=new TreeNode(4);
			root->left->right=new TreeNode(5);

			root->right->left=new TreeNode(6);
			root->right->right=new TreeNode(7);

			root->left->right->left=new TreeNode(8);
			root->left->right->right=new TreeNode(9);

			root->left->right->left->right=new TreeNode(12);

			root->right->left->left=new TreeNode(10);

			root->right->right->left=new TreeNode(11);

			inorder(root);
			vector<int> ANS = solve(root,9,3);
			logarr(ANS,0,ANS.size()-1);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
