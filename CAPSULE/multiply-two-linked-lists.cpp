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
vector<int> extractNumber(NODE* temp){
	vector<int> mul_1;
	while(temp!=NULL){
		int no = temp->data;
		if(no==0){
			mul_1.push_back(0);
		}else{
			stack<int> tempstack;
			while(no){
				tempstack.push(no%10);
				no/=10;
			}
			while(!tempstack.empty()){
				mul_1.push_back(tempstack.top());
				tempstack.pop(); 
			}	
		}			
		temp=temp->next;
	}
	return mul_1;
}
long long  multiplyTwoLists (NODE* l1, NODE* l2)
{
  //Your code here
	vector<int> mul_1=extractNumber(l1);
	vector<int> mul_2=extractNumber(l2);
	long long MOD=1000000007;  
	//long long MOD=13;  
	long long ANS=0;  
	long long SUBANS=0;  
	int stepMul=1;
	reverse(mul_1.begin(),mul_1.end());
	reverse(mul_2.begin(),mul_2.end());
	
	for(int x:mul_1){
		//int carry=0;
		int stepInnerMul=1;
		SUBANS=0;
		for(int y:mul_2){ 
			//int xx= (y*x+carry); 
			int xx= ((y*x)%MOD*(stepInnerMul%MOD))%MOD; 
			SUBANS+=xx;
			//cout<<endl<<"SUBANS=["<<SUBANS<<"]\n";		
			stepInnerMul=(stepInnerMul%MOD*10%MOD)%MOD; 
		}
		SUBANS%=MOD;
		//cout<<endl<<"SUBANS=["<<SUBANS<<"]\n";		
		ANS+=((stepMul%MOD)*SUBANS)%MOD;
		ANS%=MOD;
		stepMul=(stepMul%MOD*10%MOD)%MOD;;
		//cout<<endl<<"ANS=["<<ANS<<"]\n";		
	}
	return ANS; 
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
			head = NULL;
		} 
		for(int i=0;i<noOfLL;i++)
			display(arrayOfLL[i]); 

		long long ANS = multiplyTwoLists(arrayOfLL[0],
			arrayOfLL[1]);		
		cout<<endl<<"ANS:"<<ANS;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
