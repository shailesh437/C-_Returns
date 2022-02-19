class Solution {
public:
    pair<int,int> getRowRange(vector<vector<int>>& matrix,int startRow, int endRow,int target)     {
        pair<int,int> rowRange = make_pair(startRow,endRow);
        if(startRow<endRow){
        
        int midRow = (startRow + endRow)/2;
        if(matrix[midRow+1][0]>target){
            return getRowRange(matrix,startRow,midRow,target);
        }else{
            return getRowRange(matrix,midRow+1,endRow,target);
            }    
        }
        return rowRange;        
    }
    bool binSearch(vector<int> arr,int startIndex, int endIndex,int target){
        if(arr[startIndex] == target or arr[endIndex] == target){
            return true;
        }
        if(startIndex<endIndex){
            int midIndex = (startIndex + endIndex)/2;
            if(target<=arr[midIndex]){
                return binSearch(arr,startIndex,midIndex,target);
            }else{
                return binSearch(arr,midIndex+1,endIndex,target);
            }
        }        
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        pair<int,int> rowRange=getRowRange(matrix,0,matrix.size()-1,target);
        for(int i=rowRange.first;i<=rowRange.second;i++){
            bool eleFound = binSearch(matrix[i],0,matrix[i].size()-1,target);
            if(eleFound){
                return true;
            }
        }   
        return false;
    }
};
