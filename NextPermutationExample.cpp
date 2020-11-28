#include<iostream>
#include<cstring>
#include <algorithm>
#include<vector>

using namespace std;
int main(){
	int TC;
	cin>>TC;
	int size1;
	while(TC--){
		cin>>size1;
		vector<int> v;
		int x;
		for(int i=0;i<size1;i++){
			cin>>x;
			v.push_back(x); 
		}
		next_permutation(v.begin(), v.end());
		cout<<endl;
		for(auto i=v.begin();i!=v.end();i++){
			cout<<*i<<" ";
		}
	}	
	return 0;
}
/*
*******INPUT***********
2
3
1 2 3 
3
3 2 1
*******OUTPUT*************
1 3 2
1 2 3


*/
