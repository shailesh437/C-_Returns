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
	while(head!=NULL){
		cout<<" "<<head->data<<"-->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	Node *head=NULL;
	insertAtHead(head,2);
	insertAtHead(head,3);
	insertAtHead(head,4);
	printLinkedList(head);
	printLinkedList(head);
}
