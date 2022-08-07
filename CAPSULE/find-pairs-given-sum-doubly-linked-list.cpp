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
	struct node *next,*prev;
}NODE;


void display(NODE *noode,bool rightDir){
	cout<<endl<<"================Display===\n";
	NODE *temp = noode ;
	while(temp !=NULL  ){
		if(rightDir){ 
			cout<<temp->data<<"-->";
			temp = temp->next; 
		} else{
			cout<<temp->data<<"<---";
			temp = temp->prev; 
		}
	}
}


void addNewNode(int data,NODE* &newNode,NODE* &head,NODE* &tail){
	//return;
	newNode->data = data;
	newNode->next=NULL;
	tail=newNode;
	//return;
	if(head==NULL){
		head=newNode;
		head->next=NULL;
		head->prev=NULL;
	}else{
		NODE *temp = head ; 
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev=temp; 
	}
} 

void findPairsForSum(NODE* head,int SUM){
	NODE *start=head;
	NODE *end = head;
	while(end->next!=NULL){
			end=end->next;
	}
	cout<<start->data<<":"<<end->data;
	cout<<end->prev->data;
	//return;
	//while(start->prev!=end){
	int cnt=0;
	while(start!=NULL and end!=NULL
		and end->next!=start){
		if(start->data + end->data == SUM){
			cout<<"\n("<<start->data<<","<<end->data<<")";
			start=start->next;
			end=end->prev;
		}else if(start->data + end->data < SUM){
			start=start->next;
		}else{
			end=end->prev;
		}	
	}
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int head1Ele;
		cin>>head1Ele ;
		
		NODE *head1 = NULL,*temp;
		NODE *tail1 = NULL;
		while(head1Ele--){
			NODE *newNode = new NODE();
			int data;
			cin>>data;
			addNewNode(data,newNode,head1,tail1);	
			cout<<head1->data;		
		}		 

		display(head1,1);
		display(tail1,0);
        
        int sum;
        cin>>sum;
        findPairsForSum(head1,sum);
		
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}	
