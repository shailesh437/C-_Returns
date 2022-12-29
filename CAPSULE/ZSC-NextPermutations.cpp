#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
vector<int> nextPermutation(vector<int> &A) {
    int N=A.size();
    int dipIndex=N-1;
    int maxEleIndex=N-1;
    for(int i=N-2;i>=0;i--){
        if(A[i]<A[i+1]){
            dipIndex=i;
            break;
        }
    }
    if(dipIndex==N-1){
        sort(A.begin(),A.end());
        return A;
    }
    int dippedElement=A[dipIndex];
    cout<<endl<<":dipIndex:"<<dipIndex<<":A[dipIndex]="<<A[dipIndex]<<endl;
    //replace dipIndex elem with next higher from index thereafter
    //indexThereafter = dipIndex+1;
    int minElemGreaterThanDippedIndex=dipIndex+1;
    for(int i=dipIndex+2;i<A.size();i++){
    	if(A[i]>dippedElement){
    		minElemGreaterThanDippedIndex=i;
    	}
    }
    cout<<endl<<"A[minElemGreaterThanDippedIndex]:"<<A[minElemGreaterThanDippedIndex]<<endl;
    swap(A[dipIndex],A[minElemGreaterThanDippedIndex]);
    sort(A.begin()+dipIndex+1,A.end());
    return A;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A = { 626, 436, 819, 100, 382, 173, 817, 581, 220, 95, 814, 660, 397, 852, 15, 532, 564, 715, 179, 872, 236, 790, 223, 379, 83, 924, 454, 846, 742, 730, 689, 112, 110, 516, 85, 149, 228, 202, 988, 212, 69, 602, 887, 445, 327, 527, 347, 906, 54, 460, 517, 376, 395, 494, 827, 448, 919, 799, 133, 879, 709, 184, 812, 514, 976, 700, 156, 568, 453, 267, 547, 8, 951, 326, 652, 772, 213, 714, 706, 972, 318, 768, 506, 59, 854, 422 };
		vector<int> ANS=nextPermutation(A);
		for(int i=0;i<ANS.size();i++){
			cout<<ANS[i]<<endl;
		}
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
