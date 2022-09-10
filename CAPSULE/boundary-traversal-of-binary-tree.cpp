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
	return node;
}
void inorder(Node*root,vector<Node*> &B){
	if(root){
		inorder(root->left,B);
		//cout<<root->data<<" ";
		if(!root->left and !root->right)
			B.push_back(root);
		inorder(root->right,B);
	}
} 
void LeftBoundary(Node* root,vector<int> &V){
	if(!root) return ;
	
	if(!root->left and !root->right) return;
	//cout<<"\n adding to vector:"<<root->data<<endl;
	V.push_back(root->data);
	if(root->left)
		LeftBoundary(root->left,V);
	else if(root->right) LeftBoundary(root->right,V);
}

void RightBoundaryUpwards(Node* root,vector<int> &V){
	if(!root) return ;
	
	if(!root->left and !root->right) return; 
	if(root->right)
		RightBoundaryUpwards(root->right,V);
	else if(root->left) RightBoundaryUpwards(root->left,V);
	V.push_back(root->data);
}

void  getAllLeaves(Node* root,vector<int> &V){
	if(!root) return ;
	getAllLeaves(root->left,V);
	if(!root->left and !root->right) V.push_back(root->data);
	getAllLeaves(root->right,V);
}
void prepareTree1(Node*  root){
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(8);
	root->left->right->right = newNode(9);

	root->right->left = newNode(6);
	root->right->right = newNode(7); 
}

void prepareTree(Node*  root){
	root->left = newNode(10);
	root->left->left = newNode(5);
	root->left->right = newNode(5);
	root->left->left->right=newNode(6);
	root->left->right->left=newNode(7);

	root->left->left->right->left=newNode(8);
	root->left->left->right->right=newNode(8);

	root->left->right->left->right=newNode(8);

	root->left->left->right->left->left=newNode(11);
	root->left->left->right->left->left->left=newNode(3);
	root->left->left->right->left->left->left->left=newNode(5);

	root->left->left->right->left->left->left->right=newNode(8);

	root->left->left->right->right->left=newNode(3);
	root->left->left->right->right->right=newNode(4);

	root->left->left->right->right->right->right=newNode(11);

	root->left->left->right->right->left->left=newNode(8);
	root->left->left->right->right->left->right=newNode(6);

	root->left->right->left->right->right=newNode(1);
	root->left->right->left->right->right->left=newNode(11);

}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//Node* root = newNode(1);
		//prepareTree1(root);
		Node* root = newNode(4);
		prepareTree(root);
		//inorder(root);

		vector<int> V;
		if(root){
			V.push_back(root->data);
			if(root->left or root->right){
				LeftBoundary(root->left,V);
				getAllLeaves(root,V); 
				RightBoundaryUpwards(root->right,V);
			}
			cout<<endl;
		//V.erase(V.end()-1);	
			for(int x:V) cout<<x<<"-";	
		}  
	
}
	 #ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
return 0;
}
