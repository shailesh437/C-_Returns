#include<iostream>
#include<deque>
#include<algorithm>
#include <climits> /*NEEDED SPECIALLY IN SPOJ FOR MAX_INT,MIN_INT*/
using namespace std;

int getmaxFromArray(int arr[],int startIndex, int endIndex){
	int maxx = INT_MIN;
	for(int i=startIndex;i<=endIndex;i++){
		if(maxx<arr[i]){
			maxx = arr[i];
		}
	}
	return maxx;
}

int main(){
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	int k;
	cin>>k;
	deque<int> subArr;
	int MAX_IN_SUBARR = 0;	
	for(int i=0;i<k;i++){
		if(MAX_IN_SUBARR<A[i]){
			MAX_IN_SUBARR = A[i];
		}
		subArr.push_back(A[i]);
	}
	cout<<"\n"<<MAX_IN_SUBARR<<" "; 
	for(int i=k;i<N;i++){
		subArr.pop_front();
		int removedElement = subArr.front();
		subArr.push_back(A[i]);
		if(A[i]>=MAX_IN_SUBARR){
			MAX_IN_SUBARR = A[i];			
		}else{
			MAX_IN_SUBARR = getmaxFromArray(A,i-k+1,i);
		}
		cout<<MAX_IN_SUBARR<<" "; 
	}
	return 0;
}
