int firstMissingPositive(vector<int> &A) {
    for(int i=0;i<A.size();i++){

        while(A[i]!=i+1 and A[i]>0 and A[i]<=A.size()){
        	//cout<<"\nEntered while with i = :"<<i<<endl;
			if(A[i]==A[A[i]-1]){
                break;
            }
			swap(A[i],A[A[i]-1]);
            
        }
       // cout<<"\npassed:"<<i<<endl;
    }
    for(int i=0;i<A.size();i++){
        if(A[i]!=i+1)
            return (i+1);
    }
    return A.size()+1;
}
