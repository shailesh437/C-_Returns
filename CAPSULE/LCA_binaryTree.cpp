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
 
deque<Node*> DQ1;
deque<Node*> DQ2;
void printDeque(deque<Node*> DQ){
	while(!DQ.empty()){
		cout<<DQ.front()->data<<" ";
		DQ.pop_front();
	}
}
bool  preparePath(Node* root ,int X ,deque<Node*> &DQ )
    {
       //Your code here 
    	if(!root) return false;
    	if(root->data==X){
    		//cout<<"\npushing:"<<root->data;
    		DQ.push_front(root);
    		return true;
    	}
    	if(preparePath(root->left,X,DQ)
    		or 
    		preparePath(root->right,X,DQ)){
    		//cout<<"\npushing:"<<root->data;
    		DQ.push_front(root);
    		return true;
    	}
    	return false;
    }
Node* lca(Node* root ,int n1 ,int n2 )
{
       //Your code here
	 preparePath(root,n1,DQ1);
	 preparePath(root,n2,DQ2);
	 printDeque(DQ1);
	 cout<<endl;
	 printDeque(DQ2);
	 Node* lca = DQ1.front();
	 while(DQ1.front() == 
	 	   DQ2.front()){
	 	lca = DQ1.front();
	 	DQ1.pop_front();
	 	DQ2.pop_front();
	 }
	 return lca;
}
  

  Node* lca1(Node* root ,int n1 ,int n2 )
{
       //Your code here
	 if(!root) return NULL;

	 if(root->data==n1 or root->data==n2) return root;

	 Node* L = lca1(root->left,n1,n2);
	 Node* R = lca1(root->right,n1,n2);

	 if(L and R) return root;
	 if(L) return L;
	 return R;
}
  

void keepPath(stack<Node*> &src,queue<Node*> &dest){
	Node* dataEle=src.top();
	dest.push(dataEle);
	src.pop();
	while(!src.empty()){
		Node* topNode=src.top();
		if(topNode->left==dataEle or topNode->right==dataEle)
			dest.push(topNode);
		src.pop();
	}
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
		Node* LCA = lca1(root,18,9);
		
		cout<<LCA->data;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
