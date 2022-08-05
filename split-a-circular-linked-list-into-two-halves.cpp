
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *temp = head->next;
    *head1_ref=head;
    *head2_ref=head;
    
    int cnt=1;
    while(temp!=head){
        temp=temp->next;
        cnt++;
    }
    if(cnt%2 != 0) cnt +=1;
    cnt/=2;
    while(cnt>1){
        temp=temp->next;
        cnt--;
    }
    *head2_ref=temp->next;
    temp->next=head;
    
    temp = *head2_ref;
    while(temp->next!=head) temp=temp->next; 
    temp->next = *head2_ref;
    
    }
