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
root->left = newNode(3);
root->left->left = newNode(2);
root->left->right = newNode(1);
root->left->right->left = newNode(1);
root->right = newNode(-1);
root->right->left = newNode(4);
root->right->left->left = newNode(1);
root->right->left->right = newNode(2);
root->right->right = newNode(5);
root->right->right->right = newNode(2);
 }
map<int,int> inorderMap;
 
unordered_map<Node*, int> dp;
 
void printKSumPath(Node* root,vector<int> &path,int k){
	if(!root) return;

	path.push_back(root->data);
	printKSumPath(root->left,path,k);
	printKSumPath(root->right,path,k);
	int SUM=0;
	for(int i=path.size()-1;i>=0;i--){
		SUM+=path[i];
		if(SUM==k)
			{
				for(int v=i;v<path.size();v++){
					cout<<path[v]<<" ";
				}
				cout<<endl;
			}
	} 
	path.pop_back();
}
void printKSumPath(Node* root,int k){
	vector<int> path;
	printKSumPath(root,path, k);
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node* root = newNode(1);
		prepareTree(root);
		int k=5;
		printKSumPath(root,k);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
