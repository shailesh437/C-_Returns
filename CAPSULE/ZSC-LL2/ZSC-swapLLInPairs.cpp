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


ListNode *  swapPairs(ListNode * head) {
	if(!head->next) return head;
	ListNode * prev=head;
	ListNode * curr=head->next;
	ListNode * NEWHEAD=head->next;     
	ListNode * TAIL;     
	ListNode * countH = head;
	int count=0;
	while(countH){
		count++;
		countH=countH->next;
	}

	if(count%2==0){
		while(curr->next){
			ListNode * temp=curr->next;
			curr->next = prev;
			prev->next=temp;
			TAIL=prev;
			prev = temp;
			curr=temp->next;
			TAIL->next=curr;
		}
	}else{
		while(curr){
			ListNode * temp=curr->next;
			curr->next = prev;
			prev->next=temp;
			TAIL=prev;
			prev = temp;
			curr=temp->next;
			TAIL->next=curr;
		}
	}
	if(prev)
		TAIL->next=prev;
	if(count%2==0){

		TAIL->next=curr;
		curr->next=prev;
		prev->next=NULL;
	}

	cout<<endl<<prev->val;
	cout<<endl<<curr->val;
	cout<<endl<<TAIL->val;
	return NEWHEAD;
}
void printll(ListNode*  HEAD){
	ListNode* temp = HEAD;
	cout<<endl<<"---------------------\n";
	while(temp){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl<<"---------------------\n";
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		ListNode * head = new ListNode(27);
		head->next = new ListNode(67);
		head->next->next = new ListNode(10);
		head->next->next->next = new ListNode(64);
		head->next->next->next->next  = new ListNode(85);
		head->next->next->next->next->next  = new ListNode(4);
		printll(head);
		ListNode * ANS = swapPairs(head);
		printll(ANS);

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
