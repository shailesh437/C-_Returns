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



void prepareTree(Node*  root){
	root->left = newNode(16);
	root->right = newNode(15); 
	root->left->right = newNode(8);
	root->left->right->right = newNode(8);
	root->right->left = newNode(4);
	root->right->left->left = newNode(4);
	root->right->right = newNode(7);
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

void postOrder(Node* root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
	
}
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


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node* root = newNode(62);
		prepareTree(root);
		//Node* root = newNode(10);
		//prepareTree(root);
		inorder(root);
		cout<<endl;
		postOrder(root);
		cout<<endl;
		cout<<isSumTree(root);		
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
