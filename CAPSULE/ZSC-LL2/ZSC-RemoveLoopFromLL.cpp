/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode * prev=A;
    ListNode *temp=A;
    set<ListNode*> S;
    S.insert(A); 
    while(temp){
        prev=temp;
        temp=temp->next;
        if(S.find(temp)!=S.end()){
            prev->next=NULL;
            break;
        }
        S.insert(temp);
    }
    return A;
}
