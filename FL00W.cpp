#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int basic;
	    cin>>basic;
	    double gross=0.0;
	    if(basic<1500){
	        gross = 2.0*basic;
	    }else{
	        gross = 500.0 + 1.98*basic;
	    }
	    cout<<fixed<<gross<<endl;
	}
	return 0;
}
