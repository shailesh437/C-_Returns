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
  

void addNewNode(int data,NODE* &newNode,NODE* &head){
	//return;
	newNode->data = data;
	newNode->next=NULL;
	//return;
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

void addNewNode1(int data,NODE* &newNode,NODE* &head){
	//return;
	newNode->data = data;
	newNode->next=NULL; 
	//return; 
	if(head==NULL){
		head=newNode;
		head->next=NULL;
		return;
	}else{
		NODE *temp = head ;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode; 
	}
}

 NODE* doMerge(NODE* &head,
 				NODE* &midNode,
 				NODE* &tail,
 				int size){
 	NODE* LL_1=head,*LL_2=midNode;
 	NODE* sortedLL ;
 	//return NULL;
 	if(LL_1 !=NULL and LL_2 !=NULL and  LL_1->data <= LL_2->data){
 		sortedLL = LL_1;
 		LL_1=LL_1->next;
 	}else{
 		sortedLL = LL_2;
 		LL_2=LL_2->next;
 	}
 	head = sortedLL;
 	NODE* tmp = sortedLL; 
 	//return NULL;
 	while(LL_1!=NULL and LL_2 != NULL){
 		if(LL_1->data<=LL_2->data){
 			sortedLL->next=LL_1;
 			LL_1=LL_1->next;
 		}
 		if(LL_1->data > LL_2->data){
 			sortedLL->next=LL_2;
 			LL_2=LL_2->next;
 		}
 		sortedLL=sortedLL->next;
 	}
	cout<<"\n==========1:\n"<<LL_1->data<<":"<<sortedLL->data;
	//return NULL;
 	
 	while(LL_1!=midNode->next){
 			sortedLL->next=LL_1;
 			sortedLL=sortedLL->next;
 			LL_1=LL_1->next;
 	}
 	sortedLL->next=NULL;
	while(LL_2!=NULL){
 			sortedLL->next=LL_2;
 			sortedLL=sortedLL->next;
 			LL_2=LL_2->next;
 	}
 	sortedLL->next=NULL;
 	return head=tmp;
 }

void mergeSort(NODE* &head,NODE* &tail,int size){
 	if(head!=tail and head!=NULL ){
 		int mid=ceil(size/2.0);
 		NODE* midNode=head;
 		while(mid>1 and midNode!=NULL){
 			midNode=midNode->next;
 			mid--;
 		}	
 		if(midNode!=NULL)
 			midNode->next=NULL;
 		/*cout<<endl<<head->data;
 		cout<<endl<<midNode->data;
 		cout<<endl<<tail->data;*/
 		cout<<endl<<size;
 		cout<<endl<<ceil(size/2.0);

 		mergeSort(head,midNode,ceil(size/2.0));
 		if(midNode!=NULL)
 		mergeSort(midNode->next,tail,size-ceil(size/2.0));

 		head=doMerge(head,midNode,tail,size);
 	} 
 }


NODE* doLeftRightMerging(NODE * leftLL,
						NODE * rightLL){
	NODE* result=NULL;
	if(!rightLL) return leftLL;
	if(!leftLL)  return rightLL;
	if(leftLL->data <= rightLL->data){
		result=leftLL;
		result->next = doLeftRightMerging(leftLL->next,rightLL);
	}else{
		result=rightLL;
		result->next = doLeftRightMerging(leftLL,rightLL->next);
	}
	return result;

}
void FinfMiddle(NODE* curr,NODE** leftLL,NODE** rightLL){
	NODE *fast,*slow;
	slow=curr;
	fast=curr->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*leftLL=curr;
	*rightLL=slow->next;
	slow->next=NULL;
}
void doMergeSort(NODE ** head){
	NODE *curr=*head;
	NODE *leftLL,*rightLL;

	if(!curr or curr->next==NULL)
		return;
	FinfMiddle(curr,&leftLL,&rightLL);
 
	doMergeSort(&leftLL);
	doMergeSort(&rightLL);
	*head = doLeftRightMerging(leftLL,rightLL);

}
 NODE* mergeSort(NODE* head) {
        // your code here
 		  
 		 doMergeSort(&head);

 		 return head;
    }

NODE *getPivot(NODE* head,NODE* tail){
	NODE *pivot=head;
	NODE *prev=head;
	NODE *curr=head->next;

	while(curr != tail->next){
		if(pivot->data > curr->data){
			swap(prev->next->data,curr->data);
			prev=prev->next;
		}
		curr=curr->next;
	}
	swap(pivot->data,prev->data);
	return prev;
} 
void doquickSort(NODE *head,NODE *tail){
	if(head == tail or !head or !tail)
		return;
	NODE *pivot=getPivot(head,tail);
	doquickSort(head,pivot);
	doquickSort(pivot->next,tail);

}

void quickSort(NODE **headRef) {
	NODE *temp=  *headRef;
	NODE *head=  *headRef;
	while(temp->next !=NULL){
		temp=temp->next;
	}
	doquickSort(head,temp);	
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
		while(head1Ele--){
			NODE *newNode = new NODE();
			int data;
			cin>>data;
			addNewNode(data,newNode,head1);	
			cout<<head1->data;		
		}		 
		  
		display(head1);
		 
		//NODE *ANS = mergeSort(head1);
 		//display(ANS);
 		quickSort(&head1);
 		display(head1);
		
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}	
