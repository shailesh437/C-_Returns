bool canPlaceCowsWithMinDistance(int dist,
                                 int B, //no of cows
                                 vector<int> &A
                                 ){

int lastPosition=A[0];
int cowsPlaced=1;
for(int i=1;i<A.size() and cowsPlaced<=B;i++){
    if(A[i]-lastPosition >= dist){
        cowsPlaced++;
        lastPosition=A[i];
    }
}
if(cowsPlaced<B) return false;
return true;
}
int Solution::solve(vector<int> &A, int B) {
sort(A.begin(),A.end());
int minDistance=1;
int maxDistance=A[A.size()-1]-A[0];
int ans;
while(minDistance<=maxDistance){
    int idealDistance=minDistance+(maxDistance-minDistance)/2;
    if(canPlaceCowsWithMinDistance(idealDistance,
                                   B,
                                   A)){
                                       ans= idealDistance;
                                       minDistance=idealDistance+1;
                                   }else{
                                       maxDistance=idealDistance-1;
                                   }
}
return ans;
}
