//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
        
    // your code here
    int v[1000000];
    memset(v,0,sizeof v);
    for(int i=0;i<size;i++)
      v[a[i]]+=a[i];
    for(int i=0;i<size;i++)
      if(v[a[i]]/a[i] > size/2) return a[i]; 
    return -1;    
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends
