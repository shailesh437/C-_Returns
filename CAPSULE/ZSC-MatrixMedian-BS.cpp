int getCountSmallerThanEle(int ele,vector<int> V){
	 int start=0;
	 int end=V.size()-1;
	 int ans=0;
	 if(V[0]>=ele) return 0;
	 while(start<=end){
	 	int mid = (start+end)/2;
		if(V[mid]==ele){
			ans=mid;
			end=mid-1;
		}
		if(V[mid]<ele){ 
	 		 ans=mid+1;
			 start=mid+1;
	 	}else{  
	 		end=mid-1;
	 	}
	 }
	 return ans;
}
int Solution::findMedian(vector<vector<int> > &A) {
   if(A.size()==1){
		return A[0][A[0].size()/2];
	} 
	int rows=A.size();
	int cols=A[0].size();
	int maxInA=INT_MIN;
	int minInA=INT_MAX;
	for(int i=0;i<rows;i++){
		maxInA=max(maxInA,A[i][cols-1]);
		minInA=min(minInA,A[i][0]);
	}
	int expectedAnsPosition=(rows*cols)/2;  
	int startRange=minInA; //start of full range
	int endRange = maxInA;//end of full range
	int ans;
	while(startRange<=endRange){
		int midELem=startRange+(endRange-startRange)/2;
		int greaterThanCount=0;
		for(auto singleRow:A){
			if(midELem>singleRow[0])
			greaterThanCount+=getCountSmallerThanEle(midELem,singleRow);	
		} 
		if(greaterThanCount <= expectedAnsPosition){ 
            ans=midELem;
			startRange=midELem+1;			
		}else{ 
			endRange=midELem-1;			
		}		
	} 
	return ans;
}
