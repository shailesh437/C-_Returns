/*
Given a list of integers and a number K 
find the pair of numbers such that the differenne between
MAX and MIN(from k) is minimum*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={16,21,1,2,7,23,22};
    int k=3;
    int ans=1000000;
    sort(arr+0,arr+7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    for(int start=0;start<=(7-k);start++){
        ans=min(ans,arr[start+k-1]-arr[start]);
    }
    cout<<endl<<" ANS = "<<ans;
    return 0;
}
