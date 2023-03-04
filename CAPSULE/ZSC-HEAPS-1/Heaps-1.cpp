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

void heapify(vector<int> &A){
	for(int i=1;i<A.size();i++){
		int j = i;
		while(j>0){
			int parentIndex=(j-1)/2;
			if(A[parentIndex]>A[j]){
				swap(A[parentIndex],A[j]);
				j=parentIndex;
			}else{
				break;
			}
		}
	}
}

void addToHeap(vector<int> &A,
	int &heapSize,
	int value){
	heapSize++;
	A[heapSize-1]=value;
	int j = heapSize-1;
	while(j>0){
		int parentIndex=(j-1)/2;
		if(A[parentIndex]>A[j]){
			swap(A[parentIndex],A[j]);
			j=parentIndex;
		}else{
			break;
		}
	} 
}


int extractMin(vector<int> &A,
	int &heapSize){
	int minVal =  A[0];
	swap(A[0],A[heapSize-1]);
	heapSize--;
	int pi=0;
	while(2*pi+1<heapSize){

		int x;
		if(pi*2+2<heapSize){

			x = min(A[pi],
				min(A[pi*2+1],A[pi*2+2])
				);
		}else{
			x = min(A[pi],
				A[pi*2+1]);
		}
		if(x==A[pi]) break;//already in place
		else if(x==A[2*pi+1]){
			swap(A[pi],A[2*pi+1]);
			pi=2*pi+1;
		}else{
			swap(A[pi],A[2*pi+2]);
			pi=2*pi+2;
		}
	} 
	return minVal;
}

int solve(vector<int> &A) {
	int heapSize = A.size();
	heapify(A);
	logarr(A,0,A.size()-1);
	int cost=0;
	int cnt=0;
	while(cnt<A.size()-1){
		int r1 = extractMin(A,heapSize);
		int r2 = extractMin(A,heapSize);
		int addRope=r1+r2;
		cost+=addRope;
		addToHeap(A,heapSize,addRope);
		cnt++;
	}

	return cost;
}


int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> A = {5, 17, 100, 11};
		vector<int> A = {1, 2, 3, 4, 5};
		int ans = solve(A);
		cout<<endl<<"ANS="<<ans;
		//logarr(A,0,A.size()-1);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
