/*
struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};
*/

void insertAtRightPlace(ListNode* CurrNode,
	ListNode* newNode){
    ListNode* temp = CurrNode;
    ListNode* tempPrev = CurrNode;
    newNode->down=NULL; 
    while(temp){ 

        if(newNode->val >= temp->val){
            tempPrev=temp;            
        }else{
             newNode->right=temp;
             tempPrev->right=newNode; 
             return;
        }
        temp=temp->right; 
    } 
    tempPrev->right=newNode; 
    
}
ListNode* flatten (ListNode* root) {
    ListNode* HEAD = root;
    ListNode* RIGHT = root;
   while(RIGHT){  
        ListNode *DOWN=RIGHT->down; 
        while(DOWN){ 
            ListNode *nextDOWN=DOWN->down;
            insertAtRightPlace(RIGHT,DOWN);
            DOWN=nextDOWN; 
        }
        RIGHT=RIGHT->right;
    }
    //use down pointer to flatter :)
 
    ListNode *TEMP = HEAD;
    while(TEMP){
        TEMP->down=TEMP->right;
        TEMP=TEMP->down;
    }
    return HEAD;
}
