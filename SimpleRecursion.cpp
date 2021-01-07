#include <iostream>
using namespace std;
/* Print 1st N numbers in increasing and decreasing numbers */
void printNDecreasing(int x){
	if(x==0){
		return ;
	}
	cout<<x<<" ";
	printNDecreasing(x-1);
}

void printNIncreasing_new(int x){
	if(x==0){
		return ;
	}
	printNIncreasing_new(x-1);
	cout<<x<<" ";
}

void printNIncreasing(int x,int N){
	if(x>N){
		return ;
	}
	cout<<x<<" ";
	printNIncreasing(x+1,N);
}

int main(){
	int N;
	cin>>N;
	printNDecreasing(N);
	cout<<endl;
	printNIncreasing(1,N);
	cout<<endl;
	printNIncreasing_new(N);
}
