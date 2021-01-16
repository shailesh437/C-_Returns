#include<iostream>
#include<conio.h>
#define MAXQUE 5
using namespace std;
typedef struct queutag{
	int a[MAXQUE];
	int front,rear;
}queue_type;

void initialise(queue_type* qptr){
	qptr->front=0;
	qptr->rear=-1;
}
void insert(queue_type *qptr, int data){
	//Check if Queue is already full
	if(
		(qptr->front==0 && qptr->rear==MAXQUE-1) or
		((qptr->rear==qptr->front-1) and (qptr->rear > -1))
		){
		cout<<" Queue overflow \n";
	}else{
		qptr->rear=(qptr->rear+1)%MAXQUE;
		qptr->a[qptr->rear]=data;
	}
}

int deleteFromQueue(queue_type *qptr){
	int data=-1;
	if(qptr->rear <=-1){
		cout<<"Queue underflow\n";
	}else{
		data=qptr->a[qptr->front];
		if(qptr->front != qptr->rear)
			qptr->front = (qptr->front+1)%MAXQUE;
		else
			initialise(qptr);
	}
	return data;
}

void printQ(queue_type *qptr){
	int i;
	if(qptr->rear <=-1)
		cout<<"\n Queue is Empty \n";
	else{
		for(i=qptr->front;i!=qptr->rear;){
			cout<<"  -- -"<<qptr->a[i];
			i=(i+1)%MAXQUE;
		}
		cout<<"  -- -"<<qptr->a[i]<<"\n";
	}
}

int main(){

	int ch,x;
	queue_type queue;
	queue_type *qptr;
	qptr=&queue;
	initialise(qptr);
	while(1){
		cout<<"\n 1. ADD IN QUEUE ";
		cout<<"\n 2. REMOVE FROM QUEUE ";
		cout<<"\n 3. DISPLAY ";
		cout<<"\n 4. QUIT ";
		cout<<"\n ENTER YOUR CHOICE ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"|n ENter the element to be inserted ";
				int data;
				cin>>data;
				insert(qptr,data)	;
				printQ(qptr);
				break;
			case 2:
				int x ;
				x =  deleteFromQueue(qptr);
				cout<<"\n element reomved is "<<x<<"\n";
				printQ(qptr);
				break;
			case 3:
				printQ(qptr);
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<" Invalid choice "	;
		}
		getch();
	}
}
