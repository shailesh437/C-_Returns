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
cout<<endl<<"[ ";
while(head!=NULL){
	cout<<" "<<head->data<<"-->";
	head = head->next;
}
cout<<"NULL ]"<<endl;
}

Node* take_input(){
	int d;
	cin>>d;
	Node *head=NULL;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
	return head;
}

int main(){
  Node * head = take_input(); 
	printLinkedList(head);
  return 0;
  }
