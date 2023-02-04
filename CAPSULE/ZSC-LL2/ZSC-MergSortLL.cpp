/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
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

ListNode* getMiddleNode(ListNode* A) {
    ListNode *fast=A;
    ListNode *slow=A;
    ListNode *temp=A;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    while(fast->next and fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    //if(count%2 == 0) return slow->next;
    return slow;
}

ListNode* Solution::sortList(ListNode* A) {
    if(!A or !A->next) return A;
    ListNode* mid = getMiddleNode(A);
    ListNode* secondHalf=mid->next;
    mid->next=NULL;
    A=sortList(A);
    secondHalf=sortList(secondHalf);
    return mergeTwoLists(A,secondHalf);
}
