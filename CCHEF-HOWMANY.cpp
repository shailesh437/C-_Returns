#include <iostream>
using namespace std;

int main() {
	// your code goes here

		string s;
		cin>>s;
		if(s.length()>3){
			cout<<"More than 3 digits"<<endl; 
		}else{
		    cout<<s.length()<<endl;
		}
	return 0;
}
