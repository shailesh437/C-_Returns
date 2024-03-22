#include <bits/stdc++.h>
using namespace std;

vector<int> heapv(100000,0);
int heapSize=0;

void addToHeap(int wealth){
    heapSize++;
    heapv[heapSize-1]=wealth;
        int j=heapSize-1;
        while(j>0){
            int parentIndex=(j-1)/2;
            if(heapv[parentIndex]<heapv[j]){
                swap(heapv[parentIndex],heapv[j]);
                j=parentIndex;
            }else{
                return;
            }
        }
}


void heapify(){
    swap(heapv[0],heapv[heapSize-1]);
    heapSize--;
    int i=0;
    while(2*i+1<heapSize-1){
        int x=max(heapv[i],max(heapv[2*i+1],heapv[2*i+2]));
        if(x==heapv[i]){
            return;
        }
        if(x==heapv[2*i+1]){
            swap(heapv[i],heapv[2*i+1]);
            i=2*i+1;
        }else{
            swap(heapv[i],heapv[2*i+2]);
            i=2*i+2;
        }
    }
}


int main() {
	// your code goes here
    int N,M;
    cin>>N>>M;
    vector<int> inp(N+M,0);
    vector<int> ans;
    for(int i=0;i<N+M;i++){
        cin>>inp[i];
    }
    int kingArrival=0;
    for(int i=0;i<N+M and kingArrival<M;i++){
        if(inp[i]!=-1){
            addToHeap(inp[i]);
        }else{
            ans.push_back(heapv[0]);
            heapify();
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
