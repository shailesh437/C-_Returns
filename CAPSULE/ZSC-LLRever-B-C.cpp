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
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  }; 
  void printll(ListNode* HEAD){
  	ListNode *temp = HEAD;
  	cout<<"\n========================\n";

  	while(temp){
  		cout<<temp->val<<" ";
  		temp=temp->next;
  	}
  	cout<<"\n========================\n";
  }
ListNode* reverseBetween(ListNode* A, int B, int C) {
    if(B==C) return A;
    
    ListNode * temp = A;
    cout<<endl<<"---------------";
    while(temp){
    	cout<<temp->val<<" ";
    	temp=temp->next;
    } 
    int b=1;
    int c=1;
    ListNode* HEAD=A;
    ListNode* prev=A;
    ListNode* startingListEnd=A;
    while(b<B){
    	startingListEnd=prev;
    	prev=prev->next;
    	b++;
    } 
    cout<<endl<<prev->val; 
    
    ListNode* curr = prev->next;
    cout<<endl<<curr->val;
    int flippingLinks=1;
    ListNode* newListEnd = prev;
    
    while(flippingLinks<=(C-B)){
        temp = curr->next;
        curr->next=prev;
        cout<<endl<<"curr->val="<<curr->val<<":prev->val="<<prev->val;
        prev=curr;
        curr=temp;
        flippingLinks++;
    }
    startingListEnd->next=prev;
    newListEnd->next=curr;
    if(B==1) return prev;
    //return NULL; 
    return A;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		ListNode *head= new ListNode(1);
		head->next= new ListNode(2);
		head->next->next= new ListNode(3);
		head->next->next->next= new ListNode(4);
		head->next->next->next->next= new ListNode(5);
		ListNode *temp = reverseBetween(head,1,1);
		cout<<endl<<"------------------------\n";
		
		while(temp){
			cout<<temp->val<<" ";
			temp=temp->next;
		}
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
