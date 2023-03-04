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

void maxHeapify(vector<int> &A){
	for(int i=1;i<A.size();i++){
		int j = i;
		while(j>0){
			int parentIndex=(j-1)/2;
			if(A[parentIndex]<A[j]){
				swap(A[parentIndex],A[j]);
				j=parentIndex;
			}else{
				break;
			}
		}
	}
}

int extractMax(vector<int> &A 
	,int &heapSize){
	int maxVal =  A[0];
	swap(A[0],A[heapSize-1]);
	heapSize--;
	int pi=0;
	while(2*pi+1<heapSize){

		int x;
		if(pi*2+2<heapSize){

			x = max(A[pi],
				max(A[pi*2+1],A[pi*2+2])
				);
		}else{
			x = max(A[pi],
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
	//cout<<endl<<"returning:"<<maxVal<<"leaving at A[0]="<<A[0]<<endl;
	return maxVal; 
}

void addToMaxHeap(vector<int> &A 
	,int &heapSize,
	int newValue){
	A[heapSize]=newValue;
	int childIndex=heapSize;
	//cout<<endl<<"adding "<<newValue<<":at pos"<<childIndex;
	heapSize++;
	while(childIndex>0){
		if(A[childIndex]>A[(childIndex-1)/2]){
			swap(A[childIndex],A[(childIndex-1)/2]);
			childIndex=(childIndex-1)/2;
		}else{
			break;
		}	
	}
}

int nchoc(int A, vector<int> &B) {
	int MOD=1000000007;
	int heapSize=B.size();
	maxHeapify(B);
	int a=0;
	int maxChoc=0;
	while(a<A){
		int c1=extractMax(B,heapSize);
		maxChoc+=c1%MOD;
		maxChoc%=MOD;
		a++;
		addToMaxHeap(B,heapSize,c1/2);
	}
	return maxChoc;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int A = 3;
		//vector<int> B = {6, 5};
		int A =5;
		vector<int> B = {2, 4, 6, 8, 10};
		int ans = nchoc(A,B);
		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
