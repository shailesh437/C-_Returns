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
vector<int> slidingMaximum(const vector<int> &A, 
	int B) {

//store the index of elements in DQ
	deque<int> DQ;

	int maxElem=A[0];
	int maxElemIndex=0;
	for(int i=1;i<B;i++){
		if(A[i]>maxElem){
			maxElemIndex=i;
			maxElem=A[i];
		}
	}
	int startWindow=0;
	int endWindow=B-1;
	vector<int> ans;
	//ans.push_back(A[maxElemIndex]);
	DQ.push_back(maxElemIndex);
	for(int i=maxElemIndex+1;i<B;i++){
		if(A[i]<A[DQ.back()]){
			
			DQ.push_back(i);
		}else{
			while(!DQ.empty() and
				A[i]>A[DQ.back()]) DQ.pop_back();
			DQ.push_back(i);
		}
	}
	cout<<endl<<A[maxElemIndex]<<endl;
	while(endWindow<A.size()){
		while(DQ.size()>0 and startWindow>DQ.front()){
			//cout<<endl<<"removing:"<<A[DQ.front()];
			DQ.pop_front();
		}	
		while(DQ.size()>0 and 
			A[endWindow]>A[DQ.back()]){
			//cout<<endl<<"removing:"<<A[DQ.back()];
			DQ.pop_back();
		}
		DQ.push_back(endWindow);
		ans.push_back(A[DQ.front()]);
		startWindow++;
		endWindow++;	
	}
 return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		/*vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
		int B = 3;
*/		/*vector<int> A = {1, 2, 3, 4, 2, 7, 1, 3, 6};
		int B = 6;*/
		/*vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		int B = 2;*/
		/*vector<int> A = {648, 614, 490, 138, 657, 544, 745, 
			             582, 738, 229, 775, 665, 876, 448, 
			             4, 81, 807, 578, 712, 951, 867, 328, 
			             308, 440, 542, 178, 637, 446, 882, 
			             760, 354, 523, 935, 277, 158, 698, 
			             536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368 };
		int B = 2;*/

		/*vector<int> A = {648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};
		int B = 9;*/
		/*vector<int> A = {90, 943, 777, 658, 742, 559, 623, 263, 880, 176, 354, 434, 699, 501, 551, 821, 563, 974, 701, 479, 238, 87, 61, 910, 204, 534, 369, 845, 566, 19, 939, 87, 708, 323, 662, 32, 655, 835, 67, 360, 550, 173, 488, 420, 680, 805, 630, 48, 791, 991, 791, 819, 772, 228, 123, 303, 642, 780, 115, 89, 919, 830, 271, 853, 588, 249, 20, 940, 851, 749, 340, 587, 235, 106, 125, 32, 319, 590, 354, 751, 761, 564, 484, 51, 202, 370, 216, 130, 146, 632 };
		int B = 6;*/
		vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		int B=2;
		vector<int> ANS = slidingMaximum(A,B);
		logarr(ANS,0,ANS.size()-1);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
