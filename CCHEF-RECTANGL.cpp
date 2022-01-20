#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int a,b,c,d;
	    cin>>a>>b>>c>>d;
	    if(!(a^b^c^d))
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}
