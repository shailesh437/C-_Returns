void merge(int start,int mid, int end,vector<int> &A){
    vector<int> merged;
    int p1=start,p2=mid;
    while(p1<mid and p2<=end){
        if(A[p1]<=A[p2]){
            merged.push_back(A[p1]);
            p1++;
        }else {
            merged.push_back(A[p2]);
            p2++;
        }
    }
    while(p1<mid){
        merged.push_back(A[p1]);
        p1++;
    }
    while(p2<=end){
        merged.push_back(A[p2]);
        p2++;
    }
    int m=0;
    for(int i=start;i<=end;i++,m++){
        A[i]=merged[m];
    }
}
void mergeSort(int start,int end,vector<int> &A){
    if(end>start){
        int mid = start+(end-start)/2;
        mergeSort(start,mid,A);
        mergeSort(mid+1,end,A);
        merge(start,mid+1,end,A);
    }
}
vector<int> Solution::solve(vector<int> &A) {
    mergeSort(0,A.size()-1,A); 
    int N = A.size();
    int halfEnd=N/2-1;
    long long int SUM_MAX=0;
    int range=halfEnd+1;
    int MOD=1e9+7;
    for(int i=halfEnd+1;i<N;i++){
    	 SUM_MAX+=abs(A[i]-A[i-range])%MOD;
		 SUM_MAX%=MOD;
    }
    long long int SUM_MIN=0;
    for(int i=0;i<N-1;i+=2){
    	SUM_MIN+=abs(A[i+1]-A[i])%MOD;
    	SUM_MIN%=MOD;
    } 
    vector<int> ANS;
    ANS.push_back((int)SUM_MAX);
    ANS.push_back((int)SUM_MIN);
    return ANS;   
}
