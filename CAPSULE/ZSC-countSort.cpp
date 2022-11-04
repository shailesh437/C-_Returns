vector<int> Solution::solve(vector<int> &A) {
    vector<int> freq(100001,0);
    for(int i=0;i<A.size();i++){
        freq[A[i]]++;
    }
    int cnt=0;
    for(int i=0;i<freq.size();i++){
        if(freq[i]>0){
            for(int j=0;j<freq[i];j++){
                A[cnt]=i;
                cnt++;
            }
        }
    }
    return A;
}
