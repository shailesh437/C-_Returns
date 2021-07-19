#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	int ni;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>ni;
		if(ni%k == 0){
		ans++;	
		}
	}
	cout<<ans;
}
