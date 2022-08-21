#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
long long multiply(string s1,string s2);
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
	struct node* arb;
	node(int x){
		data=x;
		next=NULL;
		arb=NULL;
	}
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
NODE* addOne(NODE *head) 
{
        // Your Code here
        // return head of list after adding one
	NODE *temp=head;
	vector<int> v;
	while(temp!=NULL){
		v.push_back(temp->data);
		temp=temp->next;
	}
	int totalEle=v.size();
	int carry=1;
	for(int i=totalEle-1;i>0;i--){
		int digitSum=v[i]+carry;
		v[i]=digitSum%10;
		carry=digitSum/10;
	} 
	v[0]+=carry;
	temp=head;
	int i=0;
	while(temp!=NULL){
		temp->data=v[i++];
		temp=temp->next;
	}
	return temp=head;
}

void addNewNode(int data,NODE* &newNode,NODE* &head){
	newNode->data = data;
	newNode->next=NULL;
	newNode->arb=NULL;
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
bool allComputed(NODE  *head){
	NODE  *temp = head;
	int maxVal=temp->data;
	while(temp!=NULL){
		if(temp->data > maxVal)
			return false;
		maxVal=min(maxVal,temp->data);
		temp=temp->next;
	}
	return true;
}	
NODE *compute(NODE *head)
{
 
	do{
		while(head!=NULL and head->next!=NULL and 
			(head->data < (head->next)->data)){
			head=head->next;
			} 
		NODE *temp=head;
		NODE *prev=head;
	  while(temp!=NULL and temp->next!=NULL ){
				if(temp->data < temp->next->data){
					prev->next=temp->next;
					prev=prev->next;
				}else{
					prev=temp;
				}
				temp=temp->next;
			}
		}while(!allComputed(head)); 


return head;
} 

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		NODE *head = NULL,*temp;
		int noOfLL; 
		cin>>noOfLL;
		NODE* arrayOfLL[noOfLL];
		for(int i=0;i<noOfLL;i++){
			int size;
			cin>>size;
			for(int i=0;i<size;i++){
				int data;
				cin>>data;
				NODE *newNode = new NODE(data);					
				addNewNode(data,newNode,head);		
			}
			arrayOfLL[i]=head;
			//head = NULL;
		} 
		for(int i=0;i<noOfLL;i++)
			display(arrayOfLL[i]); 

		NODE * ANS=compute(head);
		display(ANS);

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
