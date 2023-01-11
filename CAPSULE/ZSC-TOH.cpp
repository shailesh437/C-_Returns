void toh(int noOfDisk,
    int sourceTower,
    int destinationTower,
    int helperTower,
    vector<vector<int>> &TotalStepsTaken){
    if(noOfDisk==0) return;
    toh(noOfDisk-1,sourceTower,helperTower,destinationTower,TotalStepsTaken);
    vector<int> stepsTaken;
    stepsTaken.push_back(noOfDisk);
    stepsTaken.push_back(sourceTower);
    stepsTaken.push_back(destinationTower);
    TotalStepsTaken.push_back(stepsTaken);
    toh(noOfDisk-1,helperTower,destinationTower,sourceTower,TotalStepsTaken);
}
vector<vector<int> > Solution::towerOfHanoi(int A) {
    vector<vector<int>> ANS;
    if(A==1){
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(3);
        ANS.push_back(ans);
        return ANS;
    }
    if(A==2){
        return {{1 ,1 ,2},{2 ,1 ,3},{1 ,2 ,3}};

    }
    toh(A,1,3,2,ANS);
    return ANS;
}
