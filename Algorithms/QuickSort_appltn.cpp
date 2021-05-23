#include<iostream>
using namespace std;

void  sortDoubleArrays(int *arrLock,int *arrKey,int start,int end);

void swap(int *arr,int x,int y){
    int temp = arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}
int doPartitionAndGetPivotIndex(int *arr,int start,int end,int pivot){
    int placedCount=0;
    for(int i=start;i<end;i++){
        if(arr[i]==pivot){
            swap(arr,i,end);
            i--;
        }else if(arr[i]<pivot){
            swap(arr,i,start+placedCount);    
            placedCount++;
        }
    }
    swap(arr,start+placedCount,end);
    return placedCount;
}

void sortDoubleArrays(int *arr1,int *arr2, int start, int end){
    if(start>=end) return;
    int pivot = arr1[end];
    int pivotIndex= doPartitionAndGetPivotIndex(arr2,start,end,pivot);
    doPartitionAndGetPivotIndex(arr1,start,end,arr2[pivotIndex]);
    sortDoubleArrays(arr1,arr2,start,pivotIndex-1);
    sortDoubleArrays(arr1,arr2,pivotIndex+1,end);
}
int main(){
    int arrLock[]={10,9,1,2,3};
    int arrKey[]={3,2,1,10,9};
    cout<<" Before Sorting "<<endl;
    for(int i=0;i<5;i++){
        cout<<arrLock[i]<<" "<<arrKey[i]<<endl;
    }
    sortDoubleArrays(arrLock,arrKey,0,4);
    cout<<endl<<"After Sorting "<<endl;
    for(int i=0;i<5;i++){
        cout<<arrLock[i]<<" "<<arrKey[i]<<endl;
    }
    return 0;
}
