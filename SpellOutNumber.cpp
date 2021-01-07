#include <iostream>
#include<bits/stdc++.h>
#include <unordered_map> 
using namespace std;
unordered_map<int,string> umap;


void printWords(int N){
	if(N==0){
		return;
	}
	printWords(N/10);
	cout<<umap[N%10]<<" ";
}

int main(){
	int N;
	umap[0]="zero";
	umap[1]="one";
	umap[2]="two";
	umap[3]="three";
	umap[4]="four";
	umap[5]="five";
	umap[6]="six";
	umap[7]="seven";
	umap[8]="eight";
	umap[9]="nine";
	cout<<"Enter the Number ";
	cin>>N;
	printWords(N);
}
