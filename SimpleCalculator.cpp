#include<iostream>
using namespace std;
int x,y;

void accept_input(){
    cout<<"\n First Number: ";
    cin>>x;
    cout<<"\n Second Number: ";
    cin>>y;
}

int main(){
    int choice_int;;
    do
    {
    cout<<"\n========Simple Calculator===============\n";
    cout<<"\n Please enter your choice::\n";
    cout<<"\n 1. Addition";
    cout<<"\n 2. Subtraction";
    cout<<"\n 3. Division";
    cout<<"\n 4. Multiplication";
    cout<<"\n 5. Exit\n";
    cin>>choice_int;        /* code */
    switch(choice_int){
        case 1:
            cout<<"\n Enter the 2 numbers to add:\n";
           accept_input();
            cout<<"\n Addition = "<<x+y;
            break;
        case 2:
            cout<<"\n Enter the 2 numbers to Subtract:\n";
            accept_input();
            cout<<"\n Subtraction = "<<x-y;
            break;
        case 3:
            cout<<"\n Enter the 2 numbers to Divide:\n";
            accept_input();
            cout<<"\n Division = "<<x/y;
            break;
        case 4:
            cout<<"\n Enter the 2 numbers to Multiply:\n";
            accept_input();
            cout<<"\n Product = "<<x*y;
            break;            
        case 5:
            cout<<"\n Thank you for using Calci....";
            exit(0);    

    }
    } while (choice_int>0 and choice_int<5);

    return 0;
}
