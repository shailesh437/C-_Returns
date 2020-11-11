#include<iostream>
using namespace std;

//Find the number of times the cell can possibly be a part of any matrix
int sumOfSubMatrices(int** arr, int n, int m){
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int TL = (i+1)*(j+1); //TOP LEFT 
			int BR = (n-i)*(m-j);//BOTTOM RIGHT
			sum+= TL*BR*arr[i][j];
		}
	}
	return sum;
}

int main(){
	int n,m;
	cin>>n>>m;
	int **arr = new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];	
		}	
	}
	cout<<sumOfSubMatrices(arr,n,m)<<endl;
	return 0;
}
