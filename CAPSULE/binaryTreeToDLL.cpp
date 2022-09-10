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

void stackAllNodesOfTree(Node*root,stack<Node*> &stk){
	if(root){
 		stackAllNodesOfTree(root->left,stk);
 		stk.push(root);
 		stackAllNodesOfTree(root->right,stk); 
	}  
} 


void prepareTree(Node*  root){
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	
	root->right->left=newNode(36); 
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//Node* root = newNode(1);
		//prepareTree1(root);
		Node* root = newNode(10);
		prepareTree(root);
		inorder(root);
		stack<Node*> stk;
		stackAllNodesOfTree(root,stk);
		Node* tail = stk.top();
		Node* head = stk.top();
		Node* N1   = stk.top();
		tail->prev=tail->next=NULL;
		head->prev=head->next=NULL;
		N1->prev=N1->next=NULL;
		stk.pop();
		while(!stk.empty()){
			Node* temp = stk.top();
			head->prev=temp;
			temp->next=head;
			head=temp; 
			stk.pop();
		}
		head->prev=NULL;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
