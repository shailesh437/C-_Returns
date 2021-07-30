#include<iostream>
using namespace std;
int solveEggDropDP(int Eggs,int Floors){
	int DPArray[Eggs+1][Floors+1];
	for(int f=1;f<=Floors;f++){
		DPArray[1][f]=f;
	}
	// We need one trial for one floor and 0
	// trials for 0 floors
	for(int e=1;e<=Eggs;e++){
		DPArray[e][1]=1;
		DPArray[e][0]=0;
	}

	for(int e=2;e<=Eggs;e++){
		for(int f=2;f<=Floors;f++){
			DPArray[e][f] = INT_MAX;
			int res=0;
			for(int f_1=1;f_1<=f;f_1++){
				res=1+max(DPArray[e-1][f_1-1],DPArray[e][f-f_1]);
				DPArray[e][f] = min(DPArray[e][f],res);
			}
		}
	}

	//Printing the DP Array
	for(int e=1;e<=Eggs;e++){
		for(int f=1;f<=Floors;f++){
			cout<<DPArray[e][f]<<" ";
		}
		cout<<endl;
	}	
	return DPArray[Eggs][Floors];
}
int main(){
	int E,F;
	cout<<"Enter the number of Eggs ::";
	cin>>E;
	cout<<"\nEnter the number of Floors ::";
	cin>>F;
	int ans = solveEggDropDP(E,F);
	cout<<"\n Answer = "<<ans;
	return 0;
}
