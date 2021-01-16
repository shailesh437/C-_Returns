#include<iostream>
#include<conio.h>
using namespace std;
typedef struct stack{
	int a[100];
	int top;
}stack_type;
void initialise(stack_type* sptr){
	sptr->top=-1;
}
void push(stack_type* sptr,int data){
	sptr->top++;
	sptr->a[sptr->top]=data;
}
int pop_1(stack_type* &sptr){
	cout<<"ENETRED POP";
	if(sptr->top<0){
		cout<<"\nStack is empty ";
		return -1;
	}
	int topElem = sptr->a[sptr->top];
	sptr->top=(sptr->top)-1;
	return topElem;
}
void display(stack_type* sptr){
	int size = sptr->top;
	cout<<endl;
	for(int i=size;i>=0;i--){
		cout<<" "<<sptr->a[i];
	}	
	cout<<endl;
}

int main(){
	int ch,x;
	stack_type s;
	stack_type *sptr;
	sptr=&s;
	initialise(sptr);
	while(1){
		cout<<"\n 1. PUSH ";
		cout<<"\n 2. POP ";
		cout<<"\n 3. DISPLAY ";
		cout<<"\n 4. QUIT ";
		cout<<"\n ENTER YOUR CHOICE ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"|n ENter the element to be pushed ";
				int data;
				cin>>data;
				push(sptr,data)	;
				display(sptr);
				break;
			case 2:
				int x ;
				x =  pop_1(sptr);
				cout<<"\n element reomved is "<<x<<"\n";
				display(sptr);
				break;
			case 3:
				display(sptr);
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
