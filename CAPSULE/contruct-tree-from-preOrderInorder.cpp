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

void diagonalPrintUtil(Node* root,int d,
	map<int,vector<int>> &diagonalPrint){
	if(!root) return;
	diagonalPrint[d].push_back(root->data);
	diagonalPrintUtil(root->left,d+1,diagonalPrint);
	diagonalPrintUtil(root->right,d,diagonalPrint);
	

}

void diagonalPrint(Node* root){
	map<int,vector<int>> diagonalPrint;
	diagonalPrintUtil(root,0,diagonalPrint);
	for(auto it:diagonalPrint){
		vector<int> v = it.second;
		for(int x: v) cout<<x<<" ";
			cout<<endl;	
	}
}

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


void prepareTree(Node*  root){
	root->left = newNode(-2);
	root->right = newNode(6);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);
	root->right->left = newNode(7);
	root->right->right = newNode(5);
}


int setSelfAsSumOfChild(Node *node){
	if(!node) return 0;
	int x = node->data; 
	node->data=setSelfAsSumOfChild(node->left)+
				setSelfAsSumOfChild(node->right);
	return 	x+node->data;		
}

void toSumTree(Node *node)
{
	node->data=setSelfAsSumOfChild(node->left)+
				setSelfAsSumOfChild(node->right);		
}

int preOrderIndex=0;
map<int,int> inorderMap;

Node * constructTree(int in[],
					 int pre[],
					 int startIndex,
					 int endIndex){

	if(startIndex>endIndex)
		return NULL;
	Node * nnNode=newNode(pre[preOrderIndex++]);
	if(startIndex == endIndex){
		return nnNode;
	}
	int nnNodeIndex=inorderMap[nnNode->data];
	nnNode->left=constructTree(in,pre,startIndex,nnNodeIndex-1);
	nnNode->right=constructTree(in,pre,nnNodeIndex+1,endIndex);
	return nnNode;
}
Node* buildTree(int in[],
				int pre[], 
				int n)
    {
        // Code here
        inorderMap.clear();
        for(int i=0;i<n;i++)
        	inorderMap[in[i]]=i;
        Node* root = constructTree(in,pre,0,n-1);
        return root;
    }

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//Node* root = newNode(1);
		//prepareTree1(root);
		int in[]={1,6,8,7};
		int pre[]={1,6,7,8};
		int n=4;
		Node * root = buildTree(in,pre,n);
		inorder(root);  
		cout<<endl;
		postorder(root);  
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
