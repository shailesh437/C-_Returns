/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {

    ListNode* prev=NULL;
    ListNode* current=A;
    while(current!=NULL){
        ListNode* temp=current->next;
        current->next=prev;
        prev = current;
        current=temp;
    }
    return prev;


}
