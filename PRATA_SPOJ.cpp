#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ULL unsigned long long 
ULL get_num(int a,ULL sum)
{
    ULL d = (ULL)sqrt(a*a + 8*a*sum);
    d-=a;
    return d / (2*a);
}

bool canMakeInGivenTime(int timeAlloted,vector<int> Ranks,int P_to_make){
	int P_made_tillNowByAll=0;
	for(int i=0;i<Ranks.size();i++){
		P_made_tillNowByAll+= get_num(Ranks[i],timeAlloted);
		if(P_made_tillNowByAll>=P_to_make){
			return true;
		}
	}
	return false;
}

int calculateTimeForP(int P,int L,vector<int> Ranks){
	int s=-1;
	int e=(Ranks[0]*P*(P+1))>>1;
	int midPoint=e;
	while(e-s>1){
		midPoint=(s+e)>>1;
		bool PCanbeMadeInETime=canMakeInGivenTime(midPoint,Ranks,P);
		if(PCanbeMadeInETime){
			e=midPoint;
		}else{
			s=midPoint;
		}
	}
	return e;
}


int main(){
	int TC;
	cin>>TC;
	int *L = new int[TC];
	int *P = new int[TC];
	vector<int> Ranks[TC];
	int i=0;
	while(i<TC){
		cin>>P[i];
		cin>>L[i];
		for(int r=0;r<L[i];r++){
			int Indrank;
			cin>>Indrank;
			Ranks[i].push_back(Indrank);
		}		
		i++;
	}
	i=0;
	while(i<TC){
		sort(Ranks[i].begin(),Ranks[i].end());		
		cout<<calculateTimeForP(P[i],L[i],Ranks[i])<<"\n";
		i++;
	}

	return 0;
}
