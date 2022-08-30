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

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}NODE;

NODE* createNewNode(int data){
	NODE* newNode=(NODE*)malloc(sizeof (struct Node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

void inOrderTraversal(NODE* root){
	if(root==NULL) return;
	inOrderTraversal(root->left);
	cout<<root->data<<"  ";
	inOrderTraversal(root->right);
}

void preOrderTraversal(NODE* root){
	if(root==NULL) return;
	cout<<root->data<<"  ";
	preOrderTraversal(root->left);	
	preOrderTraversal(root->right);
}

void postOrderTraversal(NODE* root){
	if(root==NULL) return;
	postOrderTraversal(root->left);	
	postOrderTraversal(root->right);
	cout<<root->data<<"  ";
}

void mirrorify(NODE* root,NODE** mirror){
	if(root==NULL){
		mirror=NULL;
		return;
	}
	*mirror = createNewNode(root->data);
	mirrorify(root->left,&((*mirror)->right));
	mirrorify(root->right,&((*mirror)->left)); 
}

int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		cout<<"JSRJHJBB";
		NODE* head=(NODE*)malloc(sizeof (struct Node));
		head->data=5;
		head->left=NULL;
		head->right=NULL;
		head->left=createNewNode(3);
		head->right=createNewNode(6);
		cout<<"\n head = "<<head->data;
		cout<<"\n L1-left = "<<head->left->data;
		cout<<"\n L1-right = "<<head->right->data;
		head->left->left=createNewNode(2);
		head->left->right=createNewNode(4);
		cout<<"\n L1-left-left = "<<head->left->left->data;
		cout<<"\n L1-left-right = "<<head->left->right->data;
		cout<<"\n======INORDER==============\n";
		inOrderTraversal(head);
		cout<<"\n======PRE-ORDER==============\n";
		preOrderTraversal(head);
		cout<<"\n======POST-ORDER==============\n";
		postOrderTraversal(head);
		cout<<"\n======MIRRORIFY==============\n";
		NODE* mirror=NULL;
		mirrorify(head,&mirror);
		cout<<"\n======INORDER OF MIRROR ==============\n";
		inOrderTraversal(mirror);
		
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
