#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC=1;
	//cin>>TC;
	while(TC--){
	    int N;
	    cin>>N;
	    string string1[N]={""};
	    for(int i=0;i<N;i++){
	        short a,b,c,d,e;
	        cin>>a>>b>>c>>d>>e;
	        short sum = a+b+c+d+e;
	        switch(sum){
	            case 0:
	                string1[i]="Beginner";
	                break;
	            case 1:
	                string1[i]="Junior Developer";
	                break;
	            case 2:
	                string1[i]="Middle Developer";
	                break;
	            case 3:
	                string1[i]="Senior Developer";
	                break;
	            case 4:
	                string1[i]="Hacker";
	                break;
	            case 5:
	                string1[i]="Jeff Dean";
	                break;
	        }
	    }
	    for(int i=0;i<N;i++){
	        cout<<string1[i]<<endl;
	    }
	}
	return 0;
}
