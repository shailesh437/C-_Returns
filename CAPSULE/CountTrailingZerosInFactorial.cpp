/*
Given an integer A, return the number of trailing zeroes in A! i.e., factorial of A.
Note: Your solution should run in logarithmic time complexity.*/


int Solution::trailingZeroes(int A) {
    int ans=0;
    for(int i=5;i<=A;i*=5){
        ans+=A/i;
    }
    return ans;
}
