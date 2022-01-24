#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int N;
	    cin>>N;
	    string s;
	    cin>>s;
	    int count=0;
	    for(int i=0;i<(N-1);i++){
	        if(s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u'){
	            if(s[i+1]=='a' or s[i+1]=='e' or s[i+1]=='i' or s[i+1]=='o' or s[i+1]=='u')
	                count++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
