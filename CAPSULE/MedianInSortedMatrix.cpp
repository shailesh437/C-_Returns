  int median(vector<vector<int>> &matrix, int r, int c){
        // code here      
        vector<int> bigV;
        for(int i=0;i<matrix.size();i++)
        bigV.insert(bigV.end(), matrix[i].begin(), matrix[i].end());
        sort(bigV.begin(),bigV.end());
        return bigV[(r*c)/2];
    }
