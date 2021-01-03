/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int parition (int A[], int start, int end)
{
  int pivot = A[start];
  int s = start + 1;
  int e = end;
  while (s < e)
    {
        while(pivot>A[s]){
            s++;
        }
        while(pivot<A[e]){
            e--;
        }
      if (s < e)
    	{
    	  swap (A[s], A[e]);
    	}
    }
    swap(A[start],A[e]);
    return e;
}

void quickSort(int A[],int start, int end){
    if(start<end){
        int pivotAtPlace=parition(A,start,end);
        quickSort(A,start,pivotAtPlace-1);
        quickSort(A,pivotAtPlace+1,end);
    }
}

int main ()
{
  int A[]={10,9,8,7,6,5,1,1000,90000,0,12345,-5};
  quickSort(A,0,(sizeof(A)/sizeof(A[0]))-1);
  for(int x:A){
      cout<<x<<" ";
  }

  return 0;
}
