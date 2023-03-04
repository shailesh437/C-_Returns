/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void heapify(vector<int> &A){
    for(int i=1;i<A.size();i++){
        int j=i;
        while(j>0){
            if(A[j]<A[(j-1)/2]){
                swap(A[j],A[(j-1)/2]);
                j=(j-1)/2;
            }else{
                break;
            }
        }
    }
}
int extractMin(vector<int> &A,
               int &heapSize){

      int minVal= A[0];
      swap(A[0],A[heapSize-1]);
      heapSize--;
      int pi=0;

      while(pi*2+1 < heapSize){
        int x;
        if(pi*2+2  < heapSize){
            x = min(A[pi],
                 min(A[pi*2+1],A[pi*2+2]));
        }else{
            x=min(A[pi],A[pi*2+1]);
        }
        if(A[pi]==x) break; //already in place
        if(x==A[2*pi+1]){
            swap(A[pi],A[2*pi+1]);
            pi=2*pi+1;
        }else{
            swap(A[pi],A[2*pi+2]);
            pi=2*pi+2;
        }
      }  
      return minVal;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> singleVector;
    for(int i=0;i<A.size();i++){
        ListNode* temp = A[i];
        while(temp){
            singleVector.push_back(temp->val);
            temp=temp->next;
        }
    }
    heapify(singleVector);
    int heapSize=singleVector.size();
    int x = extractMin(singleVector,heapSize);
    ListNode * root = new ListNode(x);
    ListNode * temp = root;
    while(heapSize>0){
        temp->next = new ListNode(extractMin(singleVector,heapSize));
        temp=temp->next;
    }
    temp->next=NULL;
    return root;
}
