vector<int> Solution::solve(vector<vector<int> > &A, 
vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
   vector<int> ANS;
    int MOD=1e9+7;
    vector<vector<int>> pSum(A.size(),vector<int>(A[0].size(),0));
    for(int i=0;i<A.size();i++){
        pSum[i][0]=A[i][0];
        for(int j=1;j<A[0].size();j++){
            pSum[i][j]=pSum[i][j-1]+A[i][j];
            if(pSum[i][j]<0) pSum[i][j]+=MOD;
            else pSum[i][j]=pSum[i][j]%MOD;
        }
    } 
    for(int j=0;j<A[0].size();j++){ 
        for(int i=1;i<A.size();i++){
            pSum[i][j]+=pSum[i-1][j];
            if(pSum[i][j]<0) pSum[i][j]+=MOD;
            else pSum[i][j]=pSum[i][j]%MOD;
        }
    }  
    for(int b=0;b<B.size();b++){
        int TLR=B[b];
        int TLC=C[b];
        int BRR=D[b];
        int BRC=E[b];
        int val;
        if(TLR==1 and TLC==1){
            val = pSum[BRR-1][BRC-1];  
            if(val<0) val+=MOD; 
        }else if(TLR==1){
           val=pSum[BRR-1][BRC-1]%MOD-
                   pSum[BRR-1][TLC-2]%MOD;   
            if(val<0) val+=MOD; 

        }else if(TLC==1){
            val=pSum[BRR-1][BRC-1]%MOD-
                   pSum[TLR-2][BRC-1]%MOD; 
            if(val<0) val+=MOD; 

        }else{ 
            val=pSum[BRR-1][BRC-1]%MOD-pSum[BRR-1][TLC-2]%MOD;
            if(val<0) val+=MOD;
            val-=pSum[TLR-2][BRC-1]%MOD;
            if(val<0) val+=MOD;
            val+=pSum[TLR-2][TLC-2]%MOD;  

        } 
        if(val<0) val+=MOD;
            else val=val%MOD; 
        ANS.push_back(val);  
    } 
    return ANS;
}
