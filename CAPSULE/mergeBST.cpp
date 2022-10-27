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


void storeInOrder(Node* root,vector<int> &nodesInOrderList){
	if(root){
		storeInOrder(root->left,nodesInOrderList);
		nodesInOrderList.push_back(root->data);
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



Node* buildBSTFromArray(vector<int> mergedVector, 
				  int startIndex, 
				  int endIndex){
	if(startIndex>endIndex) return NULL;
	int midIndex=(startIndex+endIndex)/2;
	Node* root = newNode(mergedVector[midIndex]);
	root->left=buildBSTFromArray(mergedVector,
								startIndex,midIndex-1);
	root->right=buildBSTFromArray(mergedVector,
								midIndex+1,endIndex);
	return root;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		Node  *root1 = newNode(100);
		root1->left     = newNode(50);
		root1->right = newNode(300);
		root1->left->left = newNode(20);
		root1->left->right = newNode(70);
		cout<<"\n In-order of Tree-1"<<endl;
		vector<int> mergedVector1;
		storeInOrder(root1,mergedVector1);
		
		Node *root2 = newNode(80);
		root2->left     = newNode(40);
		root2->right = newNode(120);

		cout<<"\n In-order of Tree-2"<<endl;
		vector<int> mergedVector2;
		storeInOrder(root2,mergedVector2);
 		cout<<endl;	
 		for(int i=0;i<mergedVector1.size();i++){
 			cout<<mergedVector1[i]<<" ";
 		}

 		cout<<endl;	
 		for(int i=0;i<mergedVector2.size();i++){
 			cout<<mergedVector2[i]<<" ";
 		}
		vector<int> mergedVector;

 		int v1=0,v2=0;
 		while(v1<mergedVector1.size() and  
 			  v2<mergedVector2.size()){

 			if(mergedVector1[v1]<mergedVector2[v2] ){
 				mergedVector.push_back(mergedVector1[v1]);
 				v1++;
 			}else if(mergedVector1[v1]>mergedVector2[v2] ){
 				mergedVector.push_back(mergedVector2[v2]);
 				v2++;
 			}else{ 
 				mergedVector.push_back(mergedVector1[v1]);
 				mergedVector.push_back(mergedVector2[v2]);
 				v1++;
 				v2++;
 			}
 		}
 		if(v1<mergedVector1.size()){
 			while(v1<mergedVector1.size()){
 				mergedVector.push_back(mergedVector1[v1]);
 				v1++;
 			}
 		}
 		if(v2<mergedVector2.size()){
 			while(v2<mergedVector2.size()){
 				mergedVector.push_back(mergedVector2[v2]);
 				v2++;
 			}
 		}
 		cout<<endl;
 		cout<<"::::::::::::\n";	
 		for(int i=0;i<mergedVector.size();i++){
 			cout<<mergedVector[i]<<" ";
 		}

 		Node* mergedRoot = buildBSTFromArray(mergedVector,0,mergedVector.size()-1);
 		cout<<"\n after merging...............";
 		inorder(mergedRoot);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
