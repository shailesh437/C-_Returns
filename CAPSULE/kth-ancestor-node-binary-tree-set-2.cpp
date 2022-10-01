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
struct Node{
	int data;
	Node *left,*right;
	Node *prev,*next;
};

Node* newNode(int data){
	Node* node = new Node;
	node->data = data;
	node->left=node->right=NULL;
	node->prev=node->next=NULL;
	return node;
}
void inorder(Node*root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
} 

void postorder(Node*root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";		
	}
} 

void stackAllNodesOfTree(Node*root,stack<Node*> &stk){
	if(root){
		stackAllNodesOfTree(root->left,stk);
		stk.push(root);
		stackAllNodesOfTree(root->right,stk); 
	}  
} 


void prepareTree1(Node*  root){
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
}
void prepareTree(Node*  root){
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);

	root->right = newNode(5);
	root->right->left = newNode(18);
	root->right->right = newNode(6);
	root->right->right->left = newNode(7);
	root->right->right->right = newNode(9);
 
} 
  
Node* getPathFromRootToNode(Node* root,int a, 
							vector<Node*> &path){
	if(!root) return NULL;
	if(root->data==a ) {path.push_back(root);return root;}

	Node* Lft=getPathFromRootToNode(root->left,
											a,path);
	Node* Rgt=getPathFromRootToNode(root->right,
											a,path);
	if(!Lft and !Rgt) return NULL;
	 
	path.push_back(root);
	return root; 
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node* root = newNode(1);
		prepareTree(root); 
		//Node* LCA = lca(root,18,9);
		cout<<"\nMethod 2\n";
 		vector<Node*> path;
 		Node * ans = getPathFromRootToNode(root,2,path); 
		cout<<endl<<"Path size = ["<<path.size()<<"]";
		cout<<"\n========================\n";
		cout<<endl<<ans->data;
		cout<<"\n========================\n";
		for(Node* P:path){
			cout<<P->data<<endl;
		}
		cout<<"\n========================\n";
		cout<<endl<<"No. of Ancestors = ["<<path.size()-1<<"]";
		int N = path.size()-1;
		int ancestorNumber=2;
		for(int i=1;i<=N;i++){
			cout<<endl<<"Ancestors No.["<<i<<"]= ["<<path[i]->data<<"]";
		}

		//cout<<LCA->data;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
