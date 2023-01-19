bool possibleToPaintInTime(
		long long int AvailableTime,
		int PaintersCount,
		int unitTime,
		vector<int> &boards
		){
	long long int timeLeft = AvailableTime;
	int b = 0;
	int p=1;
 	for(;b<boards.size() and p<=PaintersCount;){
		long long int requiredTime = 
		(long long int )boards[b]*
		(long long int )unitTime;
		if(requiredTime<=timeLeft){
			timeLeft-=requiredTime;
			b++;
		}else{
			p++; 
			timeLeft=AvailableTime;
		}	
	}	
	if(b<boards.size()) return false;
	return true;
}
//A Painters
//B - paintTime/unit 
int Solution::paint(int A, int B, vector<int> &C) {
	long long int maxTimeNeeded=0;
	long long int minTimeNeeded=1;
	int MOD = 10000003;
    for(int c:C){
		maxTimeNeeded+=(long long int)c*
						(long long int)B;
	} 
	long long int possibleAns=0;
	while(minTimeNeeded<=maxTimeNeeded){

		long long int midTime=
			minTimeNeeded+(maxTimeNeeded-minTimeNeeded)/2;
	 
	    if(possibleToPaintInTime(midTime,A,B,C)){
	    	possibleAns=midTime;
	    	//check if it still can be reduced
	    	maxTimeNeeded=midTime-1;
	    }else{
	    	minTimeNeeded=midTime+1;
	    }		
	}
    int  ANS = possibleAns%MOD;
	return ANS; 
}
 
