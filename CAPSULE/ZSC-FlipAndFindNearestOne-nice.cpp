vector<int> Solution::solve(string A, vector<vector<int> > &B) {
    vector<int> ANS;
    set<int> Set;
    for(int i=0;i<A.length();i++){
        if(A[i]=='1'){
            Set.insert(i);
        }
    }

    for(int q=0;q<B.size();q++){
        int qtype=B[q][0];
        if(qtype == 1){
            //flip the bit
            int posToFlip=B[q][1]-1;
            if(Set.find(posToFlip) == Set.end()){
                Set.insert(posToFlip);
            }else{
                Set.erase(posToFlip);
            }
        }else{
            if(Set.empty()){
                ANS.push_back(-1);
                continue;
            }
            int findNearestOneToPos=B[q][1]-1;
            auto fnp=Set.lower_bound(findNearestOneToPos);
            if(fnp==Set.begin()){
                ANS.push_back((*fnp)+1);
            }else if(fnp==Set.end()){
                ANS.push_back((*(--fnp)) + 1);
            }else{
                  int right = *fnp;
                  int left = *(--fnp);
                if((right - findNearestOneToPos)
                     >= (findNearestOneToPos - left) )
                ANS.push_back(left+1);
                else ANS.push_back(right+1);
            }
        }
    }
    return ANS;
}
