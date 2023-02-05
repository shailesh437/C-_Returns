/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 
ListNode* reverseLL(ListNode *HEAD){
	ListNode *prev=NULL;
	ListNode *curr=HEAD;

	while(curr){
		ListNode *temp =curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;	
	}
	return prev;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    //A = reverseLL(A);
	//B = reverseLL(B);
	int carry=0;
	ListNode *ANS=new ListNode(-1);
	ListNode *ANSHEAD=ANS;
	while(A and B){
		int x = A->val;
		int y = B->val;
		ANS->next=new ListNode((x+y+carry)%10);
		carry = (x+y+carry)/10;
		ANS=ANS->next;
		A=A->next;
		B=B->next;
	}
	if(A){
		while(A){
			int x = A->val;
			ANS->next=new ListNode((x+carry)%10);
			carry = (x+carry)/10;
			ANS=ANS->next;
			A=A->next;
		}
	}
	if(B){
		while(B){
			int x = B->val;
			ANS->next=new ListNode((x+carry)%10);
			carry = (x+carry)/10;
			ANS=ANS->next;
			B=B->next;
		}
	}
	if(carry){
		ANS->next=new ListNode(carry);
		ANS=ANS->next;
	}

	return ANSHEAD->next;
}
