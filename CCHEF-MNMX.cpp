#include <bits/stdc++.h>
using namespace std;

int main() {
	int TC;
	cin>>TC;
	while(TC--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int cost=0;
	    for(int i=1;i<n;i++){
	        cost+=min(a[i-1],a[i]);
	    }
	    cout<<cost<<endl;
	}
	return 0;
}
