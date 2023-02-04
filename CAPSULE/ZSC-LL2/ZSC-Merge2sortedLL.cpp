/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!B) return A;
    if(!A) return B;
    ListNode* dummyHead = new ListNode(-1);
    ListNode* tail;
    ListNode* t1=A;
    ListNode* t2=B;
    if(A->val <= B->val) {
        dummyHead->next=A;
        tail=A;
        t1=t1->next;
    } else{
        dummyHead->next=B;
        tail=B;
        t2=t2->next;
    }
    while(t1 and t2){
        if(t1->val <= t2->val){
            tail->next=t1;
            tail=t1;
            t1=t1->next;
        }else{
            tail->next=t2;
            tail=t2;
            t2=t2->next;
        }
    }
    if(t1) tail->next=t1;
    if(t2) tail->next=t2;
    return dummyHead->next;
}
