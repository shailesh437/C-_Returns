#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int L,B;
	cin>>L>>B;
	int A = L*B;
	int P = 2*(L+B);
	if(A>P){
	    cout<<"Area"<<endl<<A;
	}else if(P>A){
	    cout<<"Peri"<<endl<<P;
	}else{
	    cout<<"Eq"<<endl<<A;
	}
	return 0;
}
