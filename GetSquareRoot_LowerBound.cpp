#include<iostream>
using namespace std;
int getSquareRoot(int x){
	
	int begin=0;
	int end=x;
	int rangeMid=(begin+end)/2;
	while(rangeMid!=begin && rangeMid!=end){
		if(rangeMid*rangeMid > x){
			end=rangeMid;
		}
		else if(rangeMid*rangeMid < x){
			begin=rangeMid;
		}
		else {
			return rangeMid;
		}
		rangeMid=(begin+end)/2;
		//cout<<endl<<"begin = "<<begin<<"::end = "<<end;	
		
	}
	return rangeMid;
}
int main(){
	int x;
	cin>>x;
	cout<<endl<<"ANS = "<<getSquareRoot(x);
}
