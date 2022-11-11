int Solution::solve(vector<int> &A, int B) {
    int ANS=0; 
	vector<int> pSum(A.size());
	pSum[0]=A[0]; 
	map<int,int> m;
	m[pSum[0]]++;
    if(pSum[0]==B) ANS++; 
	for(int i=1;i<A.size();i++){
		 
	pSum[i]=pSum[i-1]+A[i]; 
	
	if(pSum[i]==B) ANS++; 
	ANS+=m[pSum[i]-B];
    m[pSum[i]]++; 
} 
return ANS;
}
