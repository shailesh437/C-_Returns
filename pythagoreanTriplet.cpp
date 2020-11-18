#include<iostream>
#define LONG long int
using namespace std;
int main(){
LONG N,m,n;
cin>>N;
if(N<3){
cout<<"-1";
}
else if(N&1){
	cout<<(N+1)*(N-1)/2<<" ";
	cout<<(N*N+1)/2;
}else{
	cout<<(N*N)/4-1<<" ";
	cout<<(N*N)/4+1;
}
return 0;
}
