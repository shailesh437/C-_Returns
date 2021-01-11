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
void insertAtHead(Node*&head, int data){ /*PASS BY REFERNCE */
if(head==NULL){
	head = new Node(data);
	return;
}
Node* newNode = new Node(data);
newNode->next = head;
head = newNode;
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


ostream& operator<<(ostream &os, Node*head){
	printLinkedList(head);
	return os;
}

istream& operator>>(istream &is, Node*&head){
	head = take_input();
	return is;
}

int main(){
  Node * headConsoleBasedInput1 = take_input(); 
  Node * headConsoleBasedInput2 = take_input(); 
  cout<<headConsoleBasedInput1<<headConsoleBasedInput2;
  Node * headConsoleBasedInput3;
  Node * headConsoleBasedInput4;
  cin>>headConsoleBasedInput3>>headConsoleBasedInput4;
  cout<<headConsoleBasedInput3<<headConsoleBasedInput4;

  return 0;
  }
