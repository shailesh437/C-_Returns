#include "solution.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int Asize=0;
    int Bsize=0;
    ListNode *temp = A;
    while(temp){
        Asize++;
        temp=temp->next;
    }
    temp = B;
    while(temp){
        Bsize++;
        temp=temp->next;
    }
    int diff = abs(Asize-Bsize);
    if(Asize>Bsize){
        for(int i=0;i<diff;i++){
            A=A->next;
        }
    }
    if(Asize<Bsize){
        for(int i=0;i<diff;i++){
            B=B->next;
        }
    }

    ListNode *tA=A;
    ListNode *tB=B;
    while(tA and tB){
        if(tA==tB) return tA;
        tA=tA->next;
        tB=tB->next;
    }
    return NULL;
}
