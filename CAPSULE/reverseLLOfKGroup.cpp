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
	int limit=1;
	while(temp !=NULL  ){
		cout<<temp->data<<"-->";
		temp = temp->next;
		limit++;
	}
}

struct node *reverse1 (struct node *head, int k)
{ 
        // Complete this method
	struct node *prev,*curr,*Next;
	curr=head;
	prev=NULL;
	Next=NULL;
	int count=1;
	struct node *last1=head;
	while(count<=k){
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next; 
		count++;
	}
	head = prev;
	//return head;
	struct node *head2=curr;
	prev=NULL;
	Next=NULL;
	while(curr != NULL){
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next; 
	}
	last1->next=prev;
	return head;
} 



struct node *reverse (struct node *head, int k)
{ 
        // Complete this method
	struct node *prev,*curr,*Next;
	curr=head; 
	prev=NULL;
	Next=NULL;  
	int count=1; 
	while(count<=k and curr!=NULL){
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next; 
		count++;
	}   
	if(Next != NULL) head->next = reverse(Next,k);
	return prev;
} 

struct node *reverse_iterative (struct node *head, 
	int k)
{ 
        // Complete this method
	struct node *prev,*curr,*Next,*prevTail,*mainHead,*temp;
	
	curr=head; 
	int pass=1;
	while(curr!=NULL){
		prev=NULL;
		Next=NULL;  
		int count=1; 
		temp = curr;
		while(count<=k and curr!=NULL){
			Next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = Next; 
			count++;
		}   
		
		if(pass==1) mainHead=prev;
		else{
			prevTail->next = prev;	
		}
		prevTail = temp;
		pass++;	
	}
	return mainHead;
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
		int noOfEle,x;
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
		int k;
		cin>>k;
		head = reverse_iterative ( head,  k);
		display(head);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
