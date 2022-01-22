#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int TC;
	cin>>TC;
	while(TC--){
	    int N;
	    cin>>N;
	    int a[9]={0};
	    for(int i=0;i<N;i++){
	        int qn,score;
	        cin>>qn>>score;
	        if(qn<9){
	            if(score>a[qn]){
	                a[qn]=score;
	            }
	        }
	    }
	    int ans=0;
	    for(int i=1;i<=8;i++){
	        ans += a[i];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
