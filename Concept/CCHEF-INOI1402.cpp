//This program is using Floyd Warshall

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

void displayVector(vector<vector<int>> mat,int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
void copyMatrix(vector<vector<int>> &prev,vector<vector<int>> &curr,int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			prev[i][j] = curr[i][j];
		}
	}
}


int main(){
	int C, F;
	cin>>C>>F;
	vector<vector<int>> prevMat(C+1, vector<int> (C+1, INF));
	vector<vector<int>> currmat(C+1, vector<int> (C+1, INF));
	//displayVector(prevMat,C);
	
	for(int i=2;i<=F+1;i++){
		int from, to, cost;
		cin>>from>>to>>cost;
		prevMat[from][to]=prevMat[to][from]=cost;
	}
	for(int i=1;i<=C;i++){
		prevMat[i][i]=0;
	}
	for(int k=1;k<=C;k++){
		for(int i=1;i<=C;i++){
			for(int j=1;j<=C;j++){
				prevMat[i][j]=min(prevMat[i][j],prevMat[i][k]+prevMat[k][j]);
			}
		}
	} 
	//displayVector(prevMat,C);
	int ans=-1;
	for(int i=1;i<=C;i++){
		for(int j=1;j<=C;j++){
			ans=max(ans,prevMat[i][j]);
		}
	}
	cout<<ans;

	return 0;
}
