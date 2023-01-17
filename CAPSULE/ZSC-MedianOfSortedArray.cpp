int getCountOfEleLessThan(const vector<int> &A,int x){
  if(x<=A[0] ) return 0;
    if(x >  A[A.size()-1]) return A.size();
     int s=0;
     int e = A.size()-1;
     int ans=0;
     while(s<=e){
         int m = (s+e)/2;
         if(A[m] == x){
            ans=m;
            e=m-1;
         }else if(A[m]<x){
            ans=m+1;
            s=m+1;
         } else{
             e=m-1;
         }
     }
     return ans;
}

double Solution::findMedianSortedArrays(const vector<int> &A, 
                                         const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     if(A.size()==0 and B.size()>0){
         int mid = B.size()/2;
         if(B.size() %2 == 0) {
              mid--;
            return (B[B.size()/2] + B[mid])/2.0*1.0;
        }
         return B[mid];
     }
     if(A.size()>0 and B.size()==0){
         int mid = A.size()/2;
         if(A.size()%2 == 0) {
            mid--;
            return (A[A.size()/2] + A[mid])/2.0*1.0;
        }
         return A[mid];
     }
     int minEle=min(A[0],B[0]);
     int maxEle=max(A[A.size()-1],B[B.size()-1]);
     int s = minEle;
     int e = maxEle;
     int totalEle = A.size()+B.size();
     int desiredLessThanCount=(A.size()+B.size())/2-1;
     if(totalEle & 1){
         desiredLessThanCount++;
     }
     int ans;
     while(s<=e){
         int m = (s+e)/2;
         int cnt=0;
         cnt+=getCountOfEleLessThan(A,m); 
         cnt+=getCountOfEleLessThan(B,m);
         if(cnt<=desiredLessThanCount){
             ans=m;
             s=m+1;
         }else{
             e=m-1;
         }
     }
     int anse=0;
     if(totalEle %2 ==0){
        desiredLessThanCount++;
         //repeat with desiredLessThanCount++
         s = minEle;
         e = maxEle;
         int ans;
            while(s<=e){
                int m = (s+e)/2;
                int cnt=0;
                cnt+=getCountOfEleLessThan(A,m);
                cnt+=getCountOfEleLessThan(B,m);
               if(cnt<=desiredLessThanCount){
             ans=m;
             s=m+1;
         }else{
             e=m-1;
         }
            }
            anse=ans;
              
     }
     if(totalEle & 1) return ans*1.0;
     return (ans+anse)/2.0 * 1.0;
}
