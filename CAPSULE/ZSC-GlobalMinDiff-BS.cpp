int Solution::solve(int A, int B, vector<vector<int> > &C) {
    for(int i=0;i<A;i++){
		sort(C[i].begin(),C[i].end());
	}
	int currRow=0;
	int nextRow=1;
	int globalMinDiff=INT_MAX;
	int localMinDiff;
	while(currRow<C.size()-1){
		for(int i=0;i<B;i++){
			int currElem=C[currRow][i];
			int start=0;
			int end=B-1;
			localMinDiff=INT_MAX;
			int mid;
			while(start<=end){
				mid=(start+end)/2;
			if(C[nextRow][mid]==currElem){//return as minDiff found
				return 0;
			}	
			if(C[nextRow][mid]>currElem){
				end=mid-1;
			}else{
				start=mid+1;
			} 
		}
		globalMinDiff=min(globalMinDiff,abs(C[nextRow][mid]-currElem));
	} 
	currRow++;
	nextRow++;
}
return globalMinDiff;
}
