#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int n){
		this->data = n;
		this->next = NULL;
	}

};
void insertAtHead(Node*&head, int data){ /*PASS BY REFERNCE */
if(head==NULL){
	head = new Node(data);
	return;
}
Node* newNode = new Node(data);
newNode->next = head;
head = newNode;
}
void printLinkedList(Node *head){ /* PASS BY VALUE*/
cout<<"[ ";
while(head!=NULL){
	cout<<" "<<head->data<<"-->";
	head = head->next;
}
cout<<"NULL ]"<<endl;
}
void insertAtTail(Node *&head,int data){
	Node *temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	Node *newNode=new Node(data);
	temp->next = newNode;
}
int lengthOfLinkedList(Node* head){
	int size=0;
	while(head!=NULL){
		head=head->next;
		size++;
	}
	return size;
}
void insertAtMiddle(Node *&head,int position, int data){
	if(head==NULL || position<=0){
		head = new Node(data);
		return;
	}
	if(position>=lengthOfLinkedList(head)){
		insertAtTail(head,data);
		return;
	}
	int jumps=1;
	Node *temp = head;
	while(jumps<=position-1){
		temp=temp->next;
		jumps++;
	}
	Node *newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;
}
int main(){
	Node *head=NULL;
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	printLinkedList(head);
	printLinkedList(head);
	cout<<endl<<"insertAtMiddle(head,2,5) Insert after 2 positions ";
	insertAtMiddle(head,2,5);
	printLinkedList(head);
	insertAtTail(head,19);
	cout<<endl<<"insertAt Tail insertAtTail(head,19) ";
	printLinkedList(head);

}
