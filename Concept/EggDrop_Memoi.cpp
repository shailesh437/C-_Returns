#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
vector<vector<int>> memoTable(MAX,vector<int> (MAX,-1));

int solveEggDropMemo(int Eggs,int Floors){
	if(memoTable[Eggs][Floors]!=-1){
		return memoTable[Eggs][Floors];
	}
	if(Eggs == 1){
		return Floors;
	}
	if(Floors<=1){
		return Floors;
	}
	int ans = INT_MAX,res;
	for(int f=1;f<=Floors;f++){
		res = 1 + max(solveEggDropMemo(Eggs-1,f-1)
			         ,solveEggDropMemo(Eggs,Floors-f));
		ans=min(ans,res);
	}
	memoTable[Eggs][Floors] = ans;
	return memoTable[Eggs][Floors];
}
int main(){
	int E,F;
	cout<<"Enter the number of Eggs ::";
	cin>>E;
	cout<<"\nEnter the number of Floors(MAX ==predefined 1000) ::";
	cin>>F;
	int ans = solveEggDropMemo(E,F);
	cout<<"\n Answer = "<<ans;
	return 0;
}
