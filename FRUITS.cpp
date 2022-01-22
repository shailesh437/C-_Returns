#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int N,M,K;
	    cin>>N>>M>>K;
	    int diff = abs(N-M);
	    if(diff<=K){
	        cout<<"0"<<endl;
	    }else{
	        cout<<abs(K-diff)<<endl;
	    }
	}
	return 0;
}
