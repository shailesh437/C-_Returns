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

void printLinkedList(Node *head){ /* PASS BY VALUE*/
cout<<endl<<"[ ";
while(head!=NULL){
	cout<<" "<<head->data<<"-->";
	head = head->next;
}
cout<<"NULL ]"<<endl;
}

Node* take_input_fromfile(){
	int d;
	cin>>d;
	Node *head=NULL;
	while(cin>>d){
		insertAtHead(head,d);
	}
	return head;
}

int main(){
	Node * head = take_input_fromfile(); 
	printLinkedList(head);
  return 0;
  }
