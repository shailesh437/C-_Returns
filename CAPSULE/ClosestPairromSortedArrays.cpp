#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
}

/*
Given two sorted arrays of distinct integers, A and B, 
and an integer C, find and return the pair whose 
sum is closest to C and the pair has one element from each array.

More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) 
has minimum value.

If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j.

Return an array with two elements {A[i], B[j]}.

*/

int bs(int X,vector<int> &Y){
	int l=0;
	int r=Y.size()-1;
	int diff=INT_MAX;
	int bestMatch=Y[0];
	while(l<=r){
		int m=(l+r)/2;
		if(abs(Y[m]-X)<diff){
			diff=abs(Y[m]-X);
			bestMatch = Y[m];
		}
		if(Y[m]>X){
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return bestMatch;
}

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
	int X=A[0];
	int Y=B[0];
	int ans = INT_MAX;
	for(int i=0;i<A.size();i++){
		int temp = bs(abs(C-A[i]),B);
		int check = abs(A[i]+temp-C);
		if(check<ans){
			ans=check;
			X=A[i];
			Y=temp;
		}
	}
		 
	return {X,Y};
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A  = {1, 2, 3, 4, 5};
		vector<int> B  = {2, 4, 6, 8};
		int C=9;
		A={5,10,20};
		B={1,2,30};
		C=13;
		vector<int> ans = solve(A,B,C);
		cout<<endl;
		logarr(ans,0,ans.size()-1);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
