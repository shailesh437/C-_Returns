#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	cout<<endl;for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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

//given array, find pairs, such that,
//their sum is closest to given No.

 
long long int getClosestSum(vector<int> &A,
				  int si,
				  int ei,		
				  int expectedSum){
	//A is sorted 
	long long int currSum=A[si]+A[ei];
	long long int diff = abs(expectedSum-currSum);
	long long int closestSum=currSum;
	while(si<ei){ 
		if(currSum==expectedSum)
			return currSum;
		if(abs(expectedSum-currSum)<diff){
			closestSum=currSum;
            diff=abs(expectedSum-currSum);
		}
		if(currSum>expectedSum){
			ei--;
		}else{
			si++;
		}
		currSum=A[si]+A[ei];
	}
	return closestSum;
}
int threeSumClosest(vector<int> &A, int B) {
	if(A.size()==3) return A[0]+A[1]+A[2];
	sort(A.begin(),A.end());
	long long  int ans;
	long long int minDiff=3000000000;
	long long int BLL=(long long int) B;
	for(int i=0;i<A.size()-2;i++){
		int currEle=A[i];
		long long int remainingSum=(long long int)B-(long long int)currEle;
		long long int closestToRemaining=getClosestSum(A,i+1,A.size()-1,remainingSum);
		if(closestToRemaining==remainingSum) 
				return B;
		if(abs(BLL-((long long int)currEle+closestToRemaining)) < minDiff){
			minDiff=abs(BLL-(currEle+closestToRemaining));
			ans=currEle+closestToRemaining;
		}	
	} 
	return (int)ans;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//vector<int> A = {-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3 };
		//int B  =  -6;
		//vector<int> A = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
		//int B = -3;
		//vector<int> A = {-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
		//int B = -1;
		//vector<int> A = {9, -3, -7, 5, 2, -6, 3, -9, -10, 5, -2, -5, 5, 2, -7, 6, -4, -7, -9, -7, -8, -6, 6, 7, 8, -6, 2, -10, -6, -1, -4, -1, 1, 5, -4, -9, -10, 2, -10, 4, -3, 4, 10, 2, 3};
		//int B = -2;
		//vector<int> A = {-4, -8, -10, -9, -1, 1, -2, 0, -8, -2};
		//int B = 0;
		//vector<int> A={ 7, -6, 2, 10};
		//int B = 3;
		//vector<int> A={10, -6, 3, 4, -8, -5};
		//int B=3;//2
		vector<int> A={-99999999,-99999999,-99999999,-99999999,
						-99999999,-99999999,-99999999,-99999999,
						-99999999,-99999999,-99999999,-99999999};
	    for(int i=0;i<10000;i++)
	    		A.push_back(-99999999);
	    int B=0;//2
		//int B=-2147483648;
		int ANS = threeSumClosest(A,B);
		//int ANS = getClosestSum(A,0,A.size()-1,B);
		cout<<endl<<"ANS = "<<ANS;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
