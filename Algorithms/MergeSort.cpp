/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void combine (int A[], int start, int mid, int end)
{
  int L_size = mid - start + 1;
  int R_size = end - mid + 1;
  int *L = new int[L_size];
  int *R = new int[R_size];
  int l_counter = 0;
  int r_counter = 0;
  for (int k = start; k <= mid; k++)
    {
      L[l_counter++] = A[k];
    }
  L[l_counter] = INT_MAX;
  for (int k = mid + 1; k <= end; k++)
    {
      R[r_counter++] = A[k];
    }
  R[r_counter] = INT_MAX;
  l_counter = 0;
  r_counter = 0;
  for (int k = start; k <= end; k++)
    {
      if (L[l_counter] < R[r_counter])
	{
	  A[k] = L[l_counter++];
	}
      else
	{
	  A[k] = R[r_counter++];
	}
    }
}

void mergeSort (int A[], int start, int end)
{
  if (start < end)
    {
      int mid = (start + end) >> 1;
      mergeSort (A, start, mid);
      mergeSort (A, mid + 1, end);
      combine (A, start, mid, end);
    }
}

int main ()
{
  int A[] = { 10, 9, 8, 7, 6, 5, 1000, 67, -9, 100 };
  mergeSort (A, 0, (sizeof (A) / sizeof (A[0])) - 1);
  cout << endl;
for (int x:A)
    {
      cout << " " << x;
    }
  return 0;
}
