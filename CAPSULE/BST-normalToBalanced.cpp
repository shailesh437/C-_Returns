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


void preOrder(Node*root){
	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);				
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

void storeInOrder(Node* root,vector<Node*> &nodesInOrderList){
	if(root){
		storeInOrder(root->left,nodesInOrderList);
		nodesInOrderList.push_back(root);
		storeInOrder(root->right,nodesInOrderList);
	}
}

Node* buildBSTUtil(vector<Node*> &nodesInOrderList,
					int start,
					int end){
	
	if(start>end) return NULL;
	int  mid=(start+end)/2;
	Node* root = nodesInOrderList[mid];
	root->left=buildBSTUtil(nodesInOrderList,
						   start,
						   mid-1);
	root->right=buildBSTUtil(nodesInOrderList,
						   mid+1,
						   end);
	return root;
}

Node* buildBST(Node* root){
	vector<Node*> nodesInOrderList;
	storeInOrder(root,nodesInOrderList);
	cout<<endl<<nodesInOrderList.size();
	//now use this nodesInOrderList to make balancedBST
	Node* rootBalancedBST = buildBSTUtil(nodesInOrderList,0,nodesInOrderList.size()-1);	
	return rootBalancedBST;
	//return NULL;
} 
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node *root = newNode(10);
		root->left = newNode(8);
		root->left->left = newNode(7);
		root->left->left->left = newNode(6);
		root->left->left->left->left = newNode(5);
		cout<<"\n Pre-order B4 of Balanced BST "<<endl;
		preOrder(root);
		
		root = buildBST(root);
		//break;
		cout<<"\n Pre-order of Balanced BST "<<endl;
		preOrder(root);

	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
