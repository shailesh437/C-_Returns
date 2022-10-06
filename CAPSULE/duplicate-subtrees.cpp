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
 	root->right->right->left->left = newNode(2);
 	root->right->right->left->left->left = newNode(3);
 	root->right->right->left->left->right = newNode(4);
} 
map<string,int> m;
map<string,Node*> m2;
string preOrder(Node*root){
	if(!root) return "";
	string txt=to_string(root->data)+"$";
	string leftText=preOrder(root->left);
	string rightText=preOrder(root->right);
	string textF=txt+"$"+leftText+"$"+rightText;
	m[textF]++;
	m2[textF]=root;
	return textF;
}  

vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*> ANS;
    preOrder(root);
    ANS.clear();
    for(auto it = m.begin();it!=m.end();it++){ 
			if(it->second>1){
				ANS.push_back(m2[it->first]);
			}
		}
		
    m.clear();
    m2.clear();
    return ANS;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node* root = newNode(1);
		prepareTree(root); 
		string abc=preOrder(root);
		cout<<abc;
		cout<<"\n==1===============================\n";
		vector<Node*> ANS = printAllDups(root);
		cout<<endl<<"____________";
		cout<<ANS.size();
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
