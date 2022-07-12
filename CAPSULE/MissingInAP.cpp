  int inSequence(int A, int B, int C){
        // code here
        if(C==0 and A!=B) return 0;
        if( A == B) return 1;
        
        if(B<0  and A>0 and C>0) return 0;
        if((B-A)%C==0 and ((B-A)/C)>0) return 1;
		return 0;
    }
};

