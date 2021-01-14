#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
void insertAtHead(Node*&head,int data){
	if(head==NULL){
		head = new Node(data);
	}else{
		Node *newNode = new Node(data);
		newNode->next=head;
		head  = newNode;
	}
}
void printLinkedList(Node* head){
	cout<<endl;
	while(head!= NULL){
		cout<<head->data<<"->";
		head = head->next;
	}	
}
Node* take_input(){
	int data;
	cin>>data;
	Node *head = NULL;
	while(data!=-1){
		insertAtHead(head,data);
		cin>>data;
	}
	return head;
}
ostream& operator<<(ostream &os,Node *head){
	printLinkedList(head);
	return os;
}
istream& operator>>(istream &is,Node* &head){
	head=take_input();
	return is;
}

// slow pointer and fast pointer technique 
Node* getMidNode(Node* head){
	Node* slow= head;
	Node* fast = head->next;
	while(fast!=NULL and fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
Node* merge_AlreadySortedLL(Node*a,Node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	Node* c;
	if(a->data < b->data){
		c=a;
		c->next=merge_AlreadySortedLL(a->next,b);
	}else{
		c=b;
		c->next=merge_AlreadySortedLL(a,b->next);
	}
	return c;
}
Node* mergeSortLL(Node* head){
//base case
	if(head==NULL or head->next==NULL){
		return head;
	}
	Node *midNode = getMidNode(head);
	Node* firstHalf = head;
	Node* secondHalf = midNode->next;
	midNode->next=NULL;
	firstHalf=mergeSortLL(firstHalf);
	secondHalf=mergeSortLL(secondHalf);
	head=merge_AlreadySortedLL(firstHalf,secondHalf);
	return head;
}

int main(){
	Node *head=NULL;
	cin>>head;
	cout<<head;
	Node *midNode = getMidNode(head);
	int midNodeValue = midNode->data;
	cout<<" Value at Middle Node = "<<midNodeValue;
	cout<<"\nSort the LinkedList using Merge Sort\n";
	head=mergeSortLL(head);
	cout<<head;
	return 0;
}
