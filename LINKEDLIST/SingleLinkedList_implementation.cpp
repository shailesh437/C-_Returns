#include<iostream>
#include<conio.h>
using namespace std;
typedef struct node_tag{
int data;
struct node_tag*next;
}node_type;
typedef struct sll_tag{
node_type* start;
}sll_type;

void initialise(sll_type * sptr){
	sptr->start=NULL;
}
void create(sll_type *sptr){
	char ch;
	node_type *prev,*curr;
	cout<<"\n Want to create a list(Y | N)";
	cin>>ch;
	while(ch == 'Y'){
		cout<<"Enter data value\n";
		if(sptr->start == NULL){
			sptr->start = (node_type*)malloc(sizeof(node_type));
			cin>>sptr->start->data;
			sptr->start->next=NULL;
			prev=sptr->start;
		}
		else{
			curr=(node_type*)malloc(sizeof(node_type));
			cin>>curr->data;
			curr->next=NULL;
			prev->next=curr;
			prev=curr;
		}
		cout<<"\n Want to add more (Y|N) ? \n";
		cin>>ch;
	}
}
void traverse(node_type *traversel){
	cout<<endl;
	while(traversel!=NULL){
		cout<<"  --->"<<traversel->data;
		traversel=traversel->next;
	}
	cout<<endl;
}
int main(){
	sll_type* list;
	create(list);
	traverse(list->start);
	return 0;
}
