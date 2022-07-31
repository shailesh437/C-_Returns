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

int intersectPoint(NODE* head1, NODE* head2)
{
    // Your Code Here
    int head1Size=1;
    int head2Size=1;
    
    NODE* temp=head1;
    while(temp!=NULL){
        temp=temp->next;
        head1Size++;
    }
    temp=head2;
    while(temp!=NULL){
        temp=temp->next;
        head2Size++;
    } 
    int diff = abs(head1Size - head2Size);
    int skip=1;

    //cout<<"\n diff = "<<diff<<":"<<head1Size<<":"<<head2Size;
    if(head1Size > head2Size){
        while(skip<=diff and head1!=NULL){
            head1=head1->next;
            skip++;
        }
        //cout<<"\n head1->data="<<head1->data;
        /*skip = 1;
        while(skip<=(head2Size-diff-1) and head2!=NULL){
            head2=head2->next;
            skip++;
        }*/
        //cout<<"\n head2->data="<<head2->data;
    }else if (head1Size < head2Size){
        while(skip<=diff and head2!=NULL){
            head2=head2->next;
            skip++;
        }
        /*skip = 1;
        while(skip<=(head1Size-diff-1) and head1!=NULL){
            head1=head1->next;
            skip++;
        } */
       // cout<<"\n head1->data="<<head1->data;
    }
    while(head1 != head2  and head2!=NULL and head1!=NULL){
        head1=head1->next;
        head2=head2->next;
    }
  // cout<<endl<<head1Size<<":"<<head2Size;
   //return 0;
   return head1->data;
}


NODE* addTwoLists(NODE* first, NODE* second)
{
        // code here
	NODE *temp=first;
	vector<int> v1,v2,v3;
	while(temp!=NULL){
		v1.push_back(temp->data);
		temp=temp->next;
	}
	temp=second; 
	while(temp!=NULL){
		v2.push_back(temp->data);
		temp=temp->next;
	}
	int v1index=v1.size()-1; 
	int v2index=v2.size()-1;
	int carry=0;
	int result=0;
	int digSum;
	int v3index=0;
	while(v1index>=0 or v2index>=0){
        	//cout<<"=inside while";
		int x=v1index>=0?v1[v1index]:0;
		int y=v2index>=0?v2[v2index]:0;
		digSum = x+y+carry;;
		result=digSum%10;
		v3.push_back(result);
		v3index++;
		carry  = digSum/10;
        	//cout<<endl<<digSum<<endl;
		v1index--;v2index--;
	}
	if(carry>0) 
		v3[v3index-1]+=carry*10;
	int noOfEle=v3index-1;
	NODE *head3=NULL;
	while(noOfEle>=0){
		NODE *newNode = new NODE(); 
		addNewNode1(v3[noOfEle],newNode,head3);
		noOfEle--;			
	}

	if(head3->data >9){
        
        int carr  = head3->data/10;
        head3->data = head3->data%10;
        NODE *newNode = new NODE();
        newNode->data=carr;
        newNode->next=head3;
        head3 = newNode;
    }

	return head3; 	
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		int head1Ele,head2Ele,commonEle;
		cin>>head1Ele>>head2Ele>>commonEle;
		
		NODE *head1 = NULL,*temp;
		while(head1Ele--){
			NODE *newNode = new NODE();
			int data;
			cin>>data;
			addNewNode(data,newNode,head1);	
			cout<<head1->data;		
		}		 
		NODE *head2 = NULL ;
		while(head2Ele--){
			NODE *newNode = new NODE();
			int data;
			cin>>data;
			addNewNode(data,newNode,head2);			
		}

		NODE *common = NULL ;
		while(commonEle--){
			NODE *newNode = new NODE();
			int data;
			cin>>data;
			addNewNode(data,newNode,common);			
		}

		temp=head1;
		while(temp->next!=NULL){
			temp=temp->next;
		}	
		temp->next=common;
		temp=head2;
		while(temp->next!=NULL){
			temp=temp->next;
		}	
		temp->next=common;

		display(head1);
		display(head2);
		
		int ANS = intersectPoint(head1,head2);
		cout<<endl<<ANS;
		//NODE *head3 = addTwoLists(head1,head2);
		///display(head3);
		
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}	
