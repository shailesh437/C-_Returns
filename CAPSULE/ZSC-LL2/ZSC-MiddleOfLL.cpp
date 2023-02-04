/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
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
    if(count%2 == 0) return slow->next->val;
    return slow->val;
}
