/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * reverseLL(ListNode* HEAD){
    ListNode * prev=NULL;
    ListNode * curr=HEAD;
    while(curr){
        ListNode * temp=curr->next;
        curr->next = prev;
        prev=curr;
        curr=temp;
    }
    return prev;
} 
ListNode* Solution::reorderList(ListNode* A) {
    ListNode *fast=A,*slow=A;
    while(fast->next and fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode * LL2 = slow->next;
    slow->next=NULL;
    LL2=reverseLL(LL2);
    ListNode * LL1 = A;
    while(LL1 and LL2){
        ListNode *templl1 = LL1->next;
        ListNode *templl2 = LL2->next;
        LL1->next = LL2;
        LL2->next=templl1;
        LL1=templl1;
        LL2=templl2;
    }
    return A;
}
