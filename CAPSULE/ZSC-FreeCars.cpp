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
void addToHeap(vector<int> &minHeap,int &minHeapSize,int newElem){
    if(minHeap.size()==0){
        minHeap.push_back(newElem);
        minHeapSize=1;
        return;
    }
    minHeapSize++;
    if(minHeap.size()>=minHeapSize){
        minHeap[minHeapSize-1]=newElem;
    }else{
        minHeap.push_back(newElem);
    }
    //heapify
    int currPos=minHeapSize-1;
    while(currPos > 0){
        if(minHeap[currPos]<minHeap[(currPos-1)/2]){
            swap(minHeap[currPos],minHeap[(currPos-1)/2]);
            currPos=(currPos-1)/2;
        }else{
            break;
        }
    }
}
void extractMinHeap(vector<int> &minHeap,int &minHeapSize){
    swap(minHeap[0],minHeap[minHeapSize-1]);
    minHeapSize--;
    int pi=0;
    while(pi*2+1 < minHeapSize){
        int minim;
        if(pi*2+2<minHeapSize){
            minim=min(minHeap[pi],
              min(minHeap[2*pi+1],minHeap[2*pi+2]));
        }else{
            minim=min(minHeap[pi],minHeap[2*pi+1]);
        }
        if(minim==minHeap[pi]){
            break;
        }else if(minim==minHeap[pi*2+1]){
         swap(minHeap[pi],minHeap[pi*2+1]);
         pi=pi*2+1;   
     }else{
        {
            swap(minHeap[pi],minHeap[pi*2+2]);
            pi=pi*2+2;   
        }
    }
}
}
int solve(vector<int> &A, vector<int> &B) {
    multimap<int,int> mm;
    for(int i=0;i<A.size();i++){
        mm.insert(pair<int,int>(A[i],B[i]));
    }
    for(auto it=mm.begin();it!=mm.end();it++){
        cout<<endl<<it->first<<"::"<<it->second;
    }
    int currTime=0;
    vector<int> minHeap;
    int minHeapSize=0;
    for(auto it=mm.begin();it!=mm.end();it++){
        if(currTime<it->first){
         currTime++;
         addToHeap(minHeap,minHeapSize,it->second);
     }else{
        if(it->second <= minHeap[0]){
                //its ok continue;
        }else{
            extractMinHeap(minHeap,minHeapSize);
            addToHeap(minHeap,minHeapSize,it->second);
        }
    }
    cout<<endl<<":minHeapSize:"<<minHeapSize<<endl;
    logarr(minHeap,0,minHeapSize-1);

}
int ans=0;
int MOD=1000000007;
logarr(minHeap,0,minHeapSize-1);
for(int i=0;i<minHeapSize;i++){
    ans+=minHeap[i]%MOD;
    ans%=MOD;
}
return ans;
}

int main(){
    clock_t begin = clock();
    file_i_o();
    int TC=1;
	//cin>>TC;
    while(TC--){
		/*vector<int> A =  {1,  7, 6, 2, 8, 4, 4, 6, 8, 2 };
		vector<int> B = { 8, 11, 7, 7, 10, 8, 7, 5, 4, 9};*/
        vector<int> A =  {6, 8, 5, 4, 2, 1, 6, 4, 2, 8, 5, 4, 4, 8, 8, 5, 3, 4, 4, 5, 8, 5, 5, 7, 2, 4, 5, 2, 6 };
        vector<int> B = {  11, 10, 8, 10, 5, 7, 5, 9, 8, 7, 11, 5, 7, 4, 7, 9, 8, 5, 5, 5, 8, 11, 8, 4, 4, 2, 9, 6, 6 };
        int ans = solve(A,B);
        cout<<endl<<ans;
    }
	 #ifndef ONLINE_JUDGE 
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
