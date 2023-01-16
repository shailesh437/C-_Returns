int bsearch(const vector<int> &A, int B,
             int start,int end){ 
           while(start<=end){
               int m=(start+end)/2;
               if(A[m]==B) return m;
               if(A[m]<B){
                   start=m+1;
               }else{
                   end=m-1;
               }
           }      
    return -1;
}


int Solution::search(const vector<int> &A, int B) {
    int partitionStart=0;
    if(A[1]<A[0]) {
        int check1=bsearch(A,B,1,A.size()-1);
        if(check1!=-1) return check1;
        return (A[0]==B)?0:-1;
    } 
    if(A[A.size()-2]>A[A.size()-1]) {
        int check1=bsearch(A,B,0,A.size()-2);
        if(check1!=-1) return check1;
        return (A[A.size()-1]==B)?A.size()-1:-1;
    }  
    if(A[0]<A[A.size()-1]){//already sorted
        return bsearch(A,B,0,A.size()-1);
    }
    int s=0;
    int e=A.size()-1;
    
    while(s<=e){
        int m=(s+e)/2;
        if(A[m]>A[m-1] and A[m]>A[m+1]){
            partitionStart=m+1;
            break;
        }else if(A[m]>A[s]){
            s=m+1;
        }else{
            e=m-1;
        }
    }
    int check1=bsearch(A,B,0,partitionStart-1);
    if(check1 !=-1) return check1;
    return bsearch(A,B,partitionStart,A.size()-1);

}
