#include <iostream>
using namespace std;
/* Print 1st N numbers in increasing and decreasing numbers */
int printNthTerm(int N){
	if(N==0 || N==1){
		return N;
	}
	return printNthTerm(N-1) +  printNthTerm(N-2);
}


int main(){
	int N;
	cout<<"\n Enter N to get the Nth term of Fibonacci series\n";
	cin>>N;
	cout<<printNthTerm(N);
}
