#include<iostream>
using namespace std;
int solveEggDropRec(int Eggs,int Floors){
	if(Eggs == 1){
		return Floors;
	}
	if(Floors<=1){
		return Floors;
	}
	int ans = INT_MAX,res;
	for(int f=1;f<=Floors;f++){
		res = max(solveEggDropRec(Eggs-1,f-1)
				 ,solveEggDropRec(Eggs,Floors-f));
		ans=min(ans,res);
	}
	return 1 + ans;
}
int main(){
	int E,F;
	cout<<"Enter the number of Eggs ::";
	cin>>E;
	cout<<"\nEnter the number of Floors ::";
	cin>>F;
	cout<<"\n Answer = "<<solveEggDropRec(E,F);
	return 0;
}
