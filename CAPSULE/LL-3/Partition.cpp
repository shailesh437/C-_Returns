/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if(!A->next) return A;
    ListNode* HEAD = new ListNode(-1);
    HEAD->next=A;
    ListNode* prev = HEAD;
    ListNode* curr = A;
    ListNode* temp = A;
    vector<ListNode*> lessThanBList;
    int lessThanB=0;
    int moreThanB=0;
    while(temp){
        if(temp->val < B){
            lessThanBList.push_back(temp);
            prev->next=temp->next; 
            lessThanB++;
        }else{
            prev=temp;
            moreThanB++;
        }
        temp=temp->next;
    }
    if(lessThanB==0 or moreThanB==0) return A;
    ListNode* ANS = lessThanBList[0];
    ListNode* ans1 = lessThanBList[0];
    for(int i=1;i<lessThanBList.size();i++){
        ans1->next = lessThanBList[i];
        ans1=ans1->next;
    }
    ans1->next=HEAD->next;
     
    return ANS;
}
