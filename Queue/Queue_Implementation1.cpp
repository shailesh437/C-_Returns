/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#define MAXSIZE 10
using namespace std;
class Queue{
  public:
  int a[MAXSIZE];
  int maxSize=MAXSIZE;
  int currentSize;
  int front=0;
  int rear=0;
  void initialise(){
      front=0;
      rear=-1;
  }
  bool isEmpty(){
      return currentSize==0;
  }
  bool isFull(){
      return currentSize==maxSize;
  }
  void push(int data){
      if(!isFull()){
        rear=(rear+1)%MAXSIZE;
        a[rear]=data;    
        currentSize++;
      }else{
          cout<<"\n Queue is Full....\n";
      }
  }
  int popAndGetFront(){
      int x;
      if(!isEmpty()){
        x = a[front];
        front=(front+1)%MAXSIZE;
        currentSize--;
      }else{
          cout<<"\n Queue is Empty....\n";
      }
     return x;
  }
  void traverse(){
      cout<<endl;
      for(int i=0;i<MAXSIZE;i++){
          cout<<" "<<a[i];
      }
      cout<<"\n front = "<<front<<"  rear = "<<rear;
      cout<<"\n";
  }
};
int main()
{
    Queue q;
    q.initialise();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.traverse();
    cout<<"\n popped "<<q.popAndGetFront();
    q.push(110);
    q.push(120);
    q.push(130);
    cout<<"\n popped "<<q.popAndGetFront();
    q.traverse();
}
