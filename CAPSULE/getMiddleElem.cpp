    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if(A>B and A>C) return B<C?C:B;
        if(C>B and C>A) return A<B?B:A;
        return A<C?C:A;
    }
