#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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

int getHeight(TreeNode* root,int &ans){
	if(!root) return -1; 
	int LH = getHeight(root->left,ans);
	int RH = getHeight(root->right,ans);
	ans=max(ans,LH+RH+2); 
	return 1+max(LH,
				 RH); 
} 
int solve(TreeNode* A) {  
	 if(!A->left and !A->right) return 0;
	 int ans=INT_MIN;
     getHeight(A,ans);
     return ans;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		/*TreeNode * root = new TreeNode(9);
		 root->left = new TreeNode(6);
		 root->right = new TreeNode(17);

		 root->left->left = new TreeNode(23);
		 root->left->right = new TreeNode(7);*/


		/*TreeNode * root = new TreeNode(1);
		 root->left = new TreeNode(15);
		 root->right = new TreeNode(2);*/
		
		TreeNode * root = new TreeNode(29);
		 root->left = new TreeNode(10);
		 root->right = new TreeNode(15);

		 root->left->left = new TreeNode(28);
		 root->left->right = new TreeNode(28); 


		 root->right->left = new TreeNode(29);
		 root->right->right = new TreeNode(4);

		 root->left->left->left = new TreeNode(4);


 
		int ans = solve(root);
		cout<<endl<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
