void merge(int start,int mid,int end,vector<int> &A){
    int p1=start,p2=mid;
    vector<int> merged;
    while(p1<mid and p2<=end){
        if(A[p1]<=A[p2]){
            merged.push_back(A[p1]);
            p1++;
        }else{
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
void mergeSort(int start,int end, vector<int> &A){
    if(start<end){
        int mid = start+(end-start)/2;
        mergeSort(start,mid,A);
        mergeSort(mid+1,end,A);
        merge(start,mid+1,end,A);
    }
}
int Solution::solve(vector<int> &A) {
    mergeSort(0,A.size()-1,A);
    int ANS=INT_MAX;
    for(int i=0;i<A.size()-1;i++){
        ANS=min(ANS,abs(A[i+1]-A[i]));
    }
    return ANS;
}
