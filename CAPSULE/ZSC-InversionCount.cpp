int MOD=1e9+7; 
int  merge(int start,int mid,int end,
	vector<int> &A){ 
	int INVC=0;
	 
	vector<int> merged;
	int p1=start,p2=mid; 
	while(p1<mid  and p2<=end){ 
		if(A[p1]<=A[p2]){
			merged.push_back(A[p1]);
			p1++;
		}
		else{			
			INVC+= (mid%MOD-p1%MOD)%MOD;
			INVC%=MOD; 
			merged.push_back(A[p2]);
			p2++; 
		} 
	}
	
	while(p1<mid){
		merged.push_back(A[p1]);
		p1++;
	}
	while(p2<=end){
		merged.push_back(A[p2]);
		p2++;
	}
	int m=0; 
	for(int i=start;i<=end;i++,m++){
		A[i]=merged[m];
	} 
 	return INVC;
}
int mergeSort(int start,
	int end ,
	vector<int> &A){
	long long int ans=0;
	if(end>start){
		int mid = start+(end-start)/2;
		ans+=mergeSort(start,mid,A)%MOD;
        ans%=MOD;
		ans+=mergeSort(mid+1,end,A)%MOD; 		 
		ans%=MOD;
        ans+= merge(start,mid+1,end,A);
        ans%=MOD; 
	} 
	return (int)ans;
}
int Solution::solve(vector<int> &A) {        
	  return mergeSort(0,A.size()-1,A);
}
