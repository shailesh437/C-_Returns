int Solution::solve(vector<int> &A, int B) {
     int goodCandidate=0;
     for(int x:A){
     	if(x<=B)
     		goodCandidate++;	
     } 
     int windowSize=goodCandidate;
     int goodInWindow=0;
     for(int i=0;i<windowSize;i++){
     	if(A[i]<=B){
     		goodInWindow++;
     	}
     }
     int windowStart=1;
     int windowEnd=windowSize;
     int maxGoodWindowSize=goodInWindow;
     while(windowEnd<A.size()){
     	if(A[windowStart-1]<=B){
     		goodInWindow--;
     	}
     	if(A[windowEnd]<=B){
     		goodInWindow++;
     	}
     	maxGoodWindowSize=max(maxGoodWindowSize,goodInWindow);
     	windowEnd++;
     	windowStart++;
     }
     return goodCandidate-maxGoodWindowSize;
}
