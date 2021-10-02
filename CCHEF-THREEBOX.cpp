#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int A,B,C,D;
	    cin>>A>>B>>C>>D;
	    int total_weight=(A+B+C);
	    if(total_weight<=D){
	        cout<<"1"<<endl;
	    }else if((A+B)<=(D)){
	        cout<<"2"<<endl;
	    }else{
	        cout<<"3"<<endl;
	    }/*
	    int ans = total_weight/D;
	    int rem = total_weight%D; 
	    if(rem==0){
	        cout<<ans<<endl;
	    }else{
	        cout<<ans+1<<endl;
	    }*/
	}
	return 0;
}
