
int Solution::solve(vector<vector<int> > &A, int B) {
 vector<vector<int>> pSum(A.size(),vector<int>(A.size(),0)); 
 for(int i=0;i<A.size();i++){
     pSum[i][0]=A[i][0];
     for(int j=1;j<A.size();j++){
         pSum[i][j]=pSum[i][j-1]+A[i][j];
     }
 }
 for(int j=0;j<A.size();j++){
     for(int i=1;i<A.size();i++){
         pSum[i][j]+=pSum[i-1][j];
     }
 }  

 int rowWindowStart=0;
 int rowWindowEnd=B-1;
 int colWindowStart=0;
 int colWindowEnd=B-1; 
 int val=0;
 int ans=INT_MIN;
 while(rowWindowEnd<A.size()){
      while(colWindowEnd<A.size()){
      	  if(rowWindowStart==0 and colWindowStart==0){
      	  	val = pSum[rowWindowEnd][colWindowEnd];
      	  }
      	  if(rowWindowStart==0){
              val=pSum[rowWindowEnd][colWindowEnd]-
                   pSum[rowWindowEnd][colWindowStart-1]; 
          }	
          else if(colWindowStart==0){
              val=pSum[rowWindowEnd][colWindowEnd]-
                   pSum[rowWindowStart-1][colWindowEnd]; 
          }
          else{
              val=pSum[rowWindowEnd][colWindowEnd] -
                  pSum[rowWindowEnd][colWindowStart-1]-
                  pSum[rowWindowStart-1][colWindowEnd]+
                  pSum[rowWindowStart-1][colWindowStart-1];
          } 
          ans=max(ans,val);        
          colWindowEnd++;
          colWindowStart++;
      }
      rowWindowEnd++;
      rowWindowStart++;
      colWindowEnd=B-1;
      colWindowStart=0;
 }
return ans;

}
