#include<string>
#include<iostream>
#define ARRAYSIZE 7
using namespace std;

void recSelectionSort(int a[],int i, int j);
int getMinIndex(int a[],int minIndex,int from, int to);
void display(int x[],int N){    
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void swap(int a[],int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int main(){
    int a[ARRAYSIZE];
    cout<<" Please enter the elements for Sorting::";
    for(int i=0;i<ARRAYSIZE;i++){
        cin>>a[i];
    }
    cout<<endl<<"Before sort : ";
    display(a,ARRAYSIZE);
    int minIndex=0;
    int min =0;
    //Selection Sort 
    for(int i=0;i<ARRAYSIZE;i++){
        minIndex = i;
        min = a[i];
        for(int j=i+1;j<ARRAYSIZE;j++){
           if(min>a[j]){
               minIndex = j ;
               min = a[j];
           } 
        }
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    cout<<endl<<"After sort : ";
    display(a,ARRAYSIZE);
    cout<<endl<<"Lets do with Recursion Now : "<<endl;
    cout<<" Please enter the elements again:"
    for(int i=0;i<ARRAYSIZE;i++){
        cin>>a[i];
    }
    cout<<endl<<"Before sort : ";
    display(a,ARRAYSIZE);
    recSelectionSort(a,0,ARRAYSIZE);
    cout<<endl<<"After sort : ";
    display(a,ARRAYSIZE);
    return 0;
}

void recSelectionSort(int a[],int sortedTill,int total){
    if(sortedTill == total -1 )
    return;
    int minIndex = getMinIndex(a,sortedTill,sortedTill+1,total);
    swap(a,sortedTill,minIndex);
    recSelectionSort(a, sortedTill+1,total);    
}

int getMinIndex(int a[],int minIndex,int from, int to){
    if(from==to){
        return minIndex;
    }
    if(a[from]<a[minIndex]){
        minIndex=from;
    }
    return getMinIndex(a,minIndex,from+1,to);
}
