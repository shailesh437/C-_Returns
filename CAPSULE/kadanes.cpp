  // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long currentMaxSum=arr[0];
        long long overallMaxSum=arr[0];
        for(int i=1;i<n;i++){
            if(currentMaxSum+arr[i]>arr[i]){
                currentMaxSum+=arr[i];
            }else{
                currentMaxSum=arr[i];
            }
            if(currentMaxSum>overallMaxSum){
                overallMaxSum = currentMaxSum; 
            }
        }
        return overallMaxSum;
    }
