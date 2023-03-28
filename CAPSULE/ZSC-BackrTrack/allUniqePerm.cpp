void printAllPermut(vector<int> &A,
                    int curr_index,
                    vector<int> ans,
                    vector<bool> &visited,
                    set<vector<int>> &ANS){
    if(curr_index==A.size()){
        ANS.insert(ans);
        return;
    }                    
    for(int i=0;i<A.size();i++){
        if(!visited[i]){
            visited[i]=true;
            ans[curr_index]=A[i];
            printAllPermut(A,curr_index+1,ans,visited,ANS);
            visited[i]=false;
        }
    }
}
vector<vector<int>> Solution::permute(vector<int> &A) {
    set<vector<int>> ANS;
    vector<int>  ans(A.size());
    vector<bool> visited(A.size(),false);
    printAllPermut(A,0,ans,visited,ANS);
    vector<vector<int>> ANS1;
    for(auto it=ANS.begin();it!=ANS.end();it++){
        ANS1.push_back(*it);
    }
    return ANS1;
}
