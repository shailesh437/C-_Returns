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

typedef struct node{
	int data;
	struct node* next;
}NODE;
void display(NODE *head){
	cout<<endl<<"================Display===\n";
	NODE *temp = head ;
	while(temp !=NULL){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
}

void reverseLL(NODE *currNode, NODE * &newHead){
	if(currNode->next != NULL){
		reverseLL(currNode->next,newHead);	
		cout<<endl<<currNode->data<<"->";
		currNode->next->next = currNode;
		currNode->next = NULL;
		cout<<endl<<"H::head IF  pointing at -->"<<newHead->data<<"->"; 
	}else{
		newHead = currNode;
		cout<<endl<<"H::head ELS pointing at -->"<<newHead->data<<"->";
	}
}

void addNewNode(int data,NODE* &newNode,NODE* &head){
	newNode->data = data;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		head->next=NULL;
	}else{
		NODE *temp = head ;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode; 
	}
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int noOfEle,x;;
		cin>>noOfEle;
		x=noOfEle;
		NODE *head = NULL,*temp;
		while(noOfEle--){
			NODE *newNode = new NODE();
			int data;
			cin>>data;
			addNewNode(data,newNode,head);			
		}		
		display(head);
		temp=head;
		cout<<endl<<"----FN call to reverse LL ---------\n";
		NODE* newHead= new NODE();
		reverseLL(temp,newHead);
		head = newHead;
		display(head);

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
