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

void printll(ListNode*  HEAD){
	ListNode* temp = HEAD;
	cout<<endl<<"---------------------\n";
	while(temp){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl<<"---------------------\n";
}

int matchAndCount(ListNode *XX, ListNode *YY){
	int count=0;
	ListNode *X=XX;
	ListNode *Y=YY;
	while(X and Y){
		if(X->val != Y->val) break;
		count++;
		X=X->next;
		Y=Y->next;
	}
	return count;
} 

int solve(ListNode* A) {
	ListNode *dummyHead = new ListNode(-1);
	ListNode *dummyTail = new ListNode(101);
	dummyHead->next = A;
	ListNode *temp =A;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=dummyTail;
	ListNode *prev = dummyHead;
	ListNode *curr = A;
	ListNode *currentNode = A->next;
	int ans=1;
	while(currentNode){ 
		curr->next=prev; 
		cout<<endl<<curr->val<<":c:"<<currentNode->val<<endl;
		ans=max(ans,matchAndCount(curr,currentNode)*2);
		cout<<endl<<prev->val<<":p:"<<currentNode->val<<endl;

		ans=max(ans,matchAndCount(prev,currentNode)*2+1);
		prev=curr;
		curr=currentNode;
		currentNode=currentNode->next;
	}
	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		ListNode *head = new ListNode(2);
		head->next = new ListNode(2);
		/*head->next = new ListNode(3);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(3);
		*/printll(head);
		cout<<endl<<solve(head);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
