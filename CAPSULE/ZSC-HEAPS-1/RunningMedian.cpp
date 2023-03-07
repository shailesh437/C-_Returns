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
void minHeapify(vector<int> &minHeap,int &minHeapSize,int newElem){
	if(minHeap.size()>(minHeapSize)){
		minHeap[minHeapSize]=newElem;	
	}else
		minHeap.push_back(newElem);
	
	minHeapSize++;
		
	if(minHeap.size()==1 or minHeapSize==1){
		return ;
	} 
	int currPos=minHeapSize-1;
	while(currPos>0){
		int pi=(currPos-1)/2;
		if(minHeap[currPos]  < minHeap[pi]){
			swap(minHeap[currPos],minHeap[pi]);
			currPos=pi;
		}else{
			break;
		}
	} 
}

void maxHeapify(vector<int> &maxHeap,
				int &maxHeapSize,
				int newElem){
	if(maxHeapSize<maxHeap.size()){
		maxHeap[maxHeapSize]=newElem;	
	}else
		maxHeap.push_back(newElem);
	maxHeapSize++;
	
    cout<<endl<<" new elelm:"<<newElem<<"::";
	logarr(maxHeap,0,maxHeap.size()-1);

	if(maxHeap.size()==1 or maxHeapSize==1){
		return ;
	} 
	int currPos=maxHeapSize-1;
	while(currPos>0){
		int pi=(currPos-1)/2;
		if(maxHeap[currPos] > maxHeap[pi]){
			swap(maxHeap[currPos],maxHeap[pi]);
			currPos=pi;
		}else{
			break;
		}
	} 
	cout<<endl<<" new elelm:"<<newElem<<"::";
	logarr(maxHeap,0,maxHeap.size()-1);
}
void removeFromMinHeap(vector<int> &minHeap,
	int &minHeapSize){
	swap(minHeap[0],minHeap[minHeapSize-1]);
	minHeapSize--;
	int pi=0;
	while(pi*2+1<minHeapSize){
		int minim;
		if(pi*2+2<minHeapSize){
			minim=min(minHeap[pi],
				min(minHeap[pi*2+1],minHeap[pi*2+2]));
		}else{
			minim=min(minHeap[pi],
				minHeap[pi*2+1]);
		}
		if(minim==minHeap[pi]) break;
		if(minim==minHeap[pi*2+1]){
			swap(minHeap[pi],minHeap[pi*2+1]);
			pi=pi*2+1;
		}else{
			swap(minHeap[pi],minHeap[pi*2+2]);
			pi=pi*2+2;
		}
	}

}
void removeFromMaxHeap(vector<int> &maxHeap,
	int &maxHeapSize){
	swap(maxHeap[0],maxHeap[maxHeapSize-1]);
	maxHeapSize--;
	int pi=0;
	while(pi*2+1<maxHeapSize){
		int maxim;
		if(pi*2+2<maxHeapSize){
			maxim=max(maxHeap[pi],
				max(maxHeap[pi*2+1],maxHeap[pi*2+2]));
		}else{
			maxim=max(maxHeap[pi],
				maxHeap[pi*2+1]);
		}
		if(maxim==maxHeap[pi]) break;
		if(maxim==maxHeap[pi*2+1]){
			swap(maxHeap[pi],maxHeap[pi*2+1]);
			pi=pi*2+1;
		}else{
			swap(maxHeap[pi],maxHeap[pi*2+2]);
			pi=pi*2+2;
		}
	}
}
vector<int> solve(vector<int> &A) {
	vector<int> minHeap;
	vector<int> maxHeap;
	int minHeapSize=0;
	int maxHeapSize=0;
	maxHeapify(maxHeap,maxHeapSize,A[0]);
	vector<int> ANS;
	ANS.push_back(A[0]);
	for(int i=1;i<A.size();i++){
		
		if(A[i]>maxHeap[0]){
			minHeapify(minHeap,minHeapSize,A[i]);
		}else{
			cout<<endl<<A[i]<<" is greater than "<<maxHeap[0]<<endl;
			cout<<endl<<"maxheapifying..";
			maxHeapify(maxHeap,maxHeapSize,A[i]);
			logarr(maxHeap,0,maxHeapSize-1);
		} 
		cout<<"\n i = "<<i<<endl;
		cout<<"MAXHE"<<endl;
		logarr(maxHeap,0,maxHeapSize-1);
		cout<<"MINHE"<<endl;
		logarr(minHeap,0,minHeapSize-1);
		cout<<"abs(minHeapSize-maxHeapSize)"<<abs(minHeapSize-maxHeapSize)<<endl;

		if(abs(minHeapSize-maxHeapSize)>1){
			if(minHeapSize>maxHeapSize){
				maxHeapify(maxHeap,maxHeapSize,minHeap[0]);
				removeFromMinHeap(minHeap,minHeapSize);
			}else{
				minHeapify(minHeap,minHeapSize,maxHeap[0]);
		logarr(minHeap,0,minHeapSize-1);

				removeFromMaxHeap(maxHeap,maxHeapSize);
			}

			cout<<"\n diff>1 = "<<i<<endl;
		cout<<"MAXHE"<<endl;
		logarr(maxHeap,0,maxHeapSize-1);
		cout<<"MINHE"<<endl;
		logarr(minHeap,0,minHeapSize-1);
		cout<<"abs(minHeapSize-maxHeapSize)"<<abs(minHeapSize-maxHeapSize)<<endl;

		}
		if(maxHeapSize > minHeapSize){
			ANS.push_back(maxHeap[0]);
		}else if (maxHeapSize < minHeapSize){
			ANS.push_back(minHeap[0]);
		}else{
			if(i+1 %2 ==0){
				ANS.push_back(minHeap[0]);
			}else{
				ANS.push_back(maxHeap[0]);
			}
		} 
	}
	return ANS;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A = { 69, 52, 34, 19, 56, 57, 5, 3, 83, 56};
		vector<int> ANS=solve(A);
		logarr(ANS,0,ANS.size()-1);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
