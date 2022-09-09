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
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node* root = newNode(8);
		root->left = newNode(3);
		root->right = newNode(10);
		root->left->left = newNode(1);
		root->left->right = newNode(6);
		root->right->right = newNode(14);
		root->right->right->left = newNode(13);
		root->left->right->left = newNode(4);
		root->left->right->right = newNode(7);
		diagonalPrint(root);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
