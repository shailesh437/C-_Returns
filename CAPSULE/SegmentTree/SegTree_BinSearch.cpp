/*
Problem Description

Given an array A of size N and Q queries. Perform following queries:

1 V 0 append V in the back of array.
2 X V set A[X] = V.
3 X 0 delete A[X]. Note: All element at back of X move forward to occupy void.
4 X Y find sum in range [X, Y].
NOTE: For the query of type 4 X Y, output the sum % 109 + 7.
*/  

#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define logarr(arr,a,b)	for(ll z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
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

vector<int> segmentTree;
vector<int> segmentTreeForDeletion;
int MODD=1000000007;

void buildSegmentTree(int idx,int l,int r,vector<int> &A){
	if(l==r){
		segmentTree[idx]=A[l];
		return;
	}
	int m = (l+r)/2;
	buildSegmentTree(2*idx+1,l,m,A);
	buildSegmentTree(2*idx+2,m+1,r,A);
	segmentTree[idx]=  (segmentTree[2*idx+1]%MODD+
		segmentTree[2*idx+2]%MODD)%MODD;
}


void buildSegmentTreeForDeletion(int idx,int l,
								int r,vector<int> &A){
	if(l==r){
		segmentTreeForDeletion[idx]=A[l];
		return;
	}
	int m = (l+r)/2;
	buildSegmentTreeForDeletion(2*idx+1,l,m,A);
	buildSegmentTreeForDeletion(2*idx+2,m+1,r,A);
	segmentTreeForDeletion[idx]=   
	segmentTreeForDeletion[2*idx+1]+
	segmentTreeForDeletion[2*idx+2];
}

void update(int idx,int l,int r, int indxToUpdate,int value,
	vector<int> &A){
	if(l==r){
		segmentTree[idx]= value%MODD;
		A[indxToUpdate] = value%MODD;
		return;
	}
	int m=(l+r)/2;
	if(indxToUpdate<=m){
		update(2*idx+1,l,m,indxToUpdate,value,A);	
	}else{
		update(2*idx+2,m+1,r,indxToUpdate,value,A);	
	}
	segmentTree[idx]=	(segmentTree[2*idx+1]%MODD+
		segmentTree[2*idx+2]%MODD)%MODD;
}


void updateForDeletion(int idx,
	int l,int r, int indxToUpdate,int value){
	if(l==r){
		segmentTreeForDeletion[idx] = value;
		return;
	}
	int m=(l+r)/2;
	if(indxToUpdate<=m){
		updateForDeletion(2*idx+1,l,m,indxToUpdate,value);	
	}else{
		updateForDeletion(2*idx+2,m+1,r,indxToUpdate,value);	
	}
	segmentTreeForDeletion[idx] =
	segmentTreeForDeletion[2*idx+1] +
	segmentTreeForDeletion[2*idx+2] ; 
}

int query(int segTreeIndx,int l,int r,int ql,int qr){
	if(ql>r or qr<l) return 0;

	if(ql<=l and qr>=r) return segmentTree[segTreeIndx];
	int m = (l+r)/2;

	return (query(2*segTreeIndx+1,l,m,ql,qr)%MODD+
		query(2*segTreeIndx+2,m+1,r,ql,qr)%MODD)%MODD; 
}


int queryDeletion(int segTreeIndx,int l,int r,int ql,int qr){
	if(ql>r or qr<l) return 0;

	if(ql<=l and qr>=r) return segmentTreeForDeletion[segTreeIndx];
	int m = (l+r)/2;
	return queryDeletion(2*segTreeIndx+1,l,m,ql,qr) +
		   queryDeletion(2*segTreeIndx+2,m+1,r,ql,qr) ;

}

int queryDeletion(int segTreeIndx,int l,int r,int ql,int qr,
	int runningIndx){
	if(ql>r or qr<l) return 0;

	if(ql<=l and qr>=r){

			return segmentTreeForDeletion[segTreeIndx];

	} 
			int m = (l+r)/2;
	return queryDeletion(2*segTreeIndx+1,l,m,ql,qr,runningIndx) +
		   queryDeletion(2*segTreeIndx+2,m+1,r,ql,qr,runningIndx) ;

}


int getRequiredIndex(int inpIndex,int arrSize){
	cout<<endl<<"inpIndex="<<inpIndex;
	int start=0;
	int end=arrSize;
	int effective_index=0;	
	while(start<=end){
		int mid=(start+end)/2;
		int elem_removed = queryDeletion(0,0,arrSize,0,mid);
		if(elem_removed+inpIndex==mid){
			end=mid-1;
			effective_index=mid;
		}else if(elem_removed+inpIndex>mid){
			start=mid+1;
		} else{
			end = mid-1;
		}   	
	}
	return effective_index;
}

vector<int> solve(vector<int> &Arr, vector<vector<int> > &B) {

	vector<int> ANS;

	vector<int> A;
	vector<int> A_deleted;
	A.clear();
	for(int x:Arr) 
		A.push_back(x);
	int end_index=A.size()-1;
	for(int i=0;i<B.size();i++){
		A.push_back(0);
	}

	
	
	int x = (int)(ceil(log2(A.size())));
	int segTreeSize = (int)2*(int)pow(2,x)-1;
	segmentTree.clear();
	segmentTree.resize(segTreeSize,0);
	buildSegmentTree(0,0,A.size()-1,A);
	A_deleted.resize(A.size(),0);
	segmentTreeForDeletion.resize(segTreeSize,0);
	buildSegmentTreeForDeletion(0,0,A_deleted.size()-1,A_deleted);

	int option4=0;
	for(int i=0;i<B.size();i++){
		if(B[i][0]==1){
			end_index++;			
			update(0,0,A.size()-1,end_index,B[i][1],A); 
		}

		if(B[i][0]==2){

			/*int elementsDeletedBeforeIndx= 
			queryDeletion(0,0,A.size()-1,0,B[i][1]-1); 

			int indxToUpdate=B[i][1]-1;
			bool last_elem_del=false;
			while(indxToUpdate<=end_index and A[indxToUpdate]==0){
				indxToUpdate++;
				last_elem_del=true;
			}
			if(last_elem_del)
				elementsDeletedBeforeIndx--;   
			while(elementsDeletedBeforeIndx)
			{
				indxToUpdate++;
				if(A[indxToUpdate]==0){ 
					continue;
				}  
				elementsDeletedBeforeIndx--;		 
			} 

*/			
			int indxToUpdate=getRequiredIndex(B[i][1]-1,A.size()-1);
			update(0,0,A.size()-1,
				indxToUpdate,
				B[i][2],A);

		}
		if(B[i][0]==3){
			/*int elementsDeletedBeforeIndx= 
			queryDeletion(0,0,A.size()-1,0,B[i][1]-1,i); 
			int indxToUpdate=B[i][1]-1;
			bool last_elem_del=false;
			while(indxToUpdate<=end_index and A[indxToUpdate]==0){
				indxToUpdate++;
				last_elem_del=true;
			} 
			if(last_elem_del)
				elementsDeletedBeforeIndx--;

			
			if(i==19){
				int _elementsDeletedBeforeIndx= 
				queryDeletion(0,0,A.size()-1,0,11,i); 
				cout<<endl<<"_elementsDeletedBeforeIndx="<<_elementsDeletedBeforeIndx<<endl;
				cout<<endl<<"elementsDeletedBeforeIndx"<<elementsDeletedBeforeIndx;
				cout<<endl<<"indxToUpdate"<<indxToUpdate;
			}

			while(elementsDeletedBeforeIndx)
			{
				indxToUpdate++;
				if(A[indxToUpdate]==0){
					continue;
				}  
				elementsDeletedBeforeIndx--;		 
			}*/
			

			int indxToUpdate=getRequiredIndex(B[i][1]-1,A.size()-1);
			
			update(0,0,A.size()-1,
				indxToUpdate,
				0,A); 

			updateForDeletion(0,0,A.size()-1,indxToUpdate,1); 

		}
		if(B[i][0]==4){
			option4++;
			/*int rangeCount=B[i][2]-B[i][1]+1;

			int elementsDeletedBeforeIndx= 
			queryDeletion(0,0,A.size()-1,0,B[i][1]-1);
			int indxToStart=B[i][1]-1;

			if(i==32){ 
				logarr(A,0,A.size()-1);
				int check_x = getRequiredIndex(B[i][1]-1,A.size()-1);
				cout<<endl<<"check_x = "<<check_x;
				int check_y = getRequiredIndex(B[i][2]-1,A.size()-1);
				cout<<endl<<"check_y = "<<check_y;
				cout<<endl<<"elementsDeletedBeforeIndx="<<elementsDeletedBeforeIndx<<endl;
			
			}

		//	cout<<"\n elementsDeletedBeforeIndx = "<<elementsDeletedBeforeIndx;
			bool last_elem_del=false;
			while(indxToStart<=end_index and A[indxToStart]==0){
				indxToStart++;
				last_elem_del=true;
			} 
			if(last_elem_del)
				elementsDeletedBeforeIndx--;
			while(elementsDeletedBeforeIndx)
			{
				indxToStart++;
				if(A[indxToStart]==0){
					continue;
				}  
				elementsDeletedBeforeIndx--;		 
			}


			int indexToEnd = indxToStart;

			rangeCount--;
			while(rangeCount){
				indexToEnd++;
				if(A[indexToEnd]==0){ 
					continue;
				}
				rangeCount--;
			}

			if(i==32){ 
				cout<<endl<<"and indxToStart = "<<indxToStart;
				cout<<endl<<"and indexToEnd = "<<indexToEnd;
			}*/


		//	cout<<endl<<"indexToEnd="<<indexToEnd<<endl;



		///	cout<<"\n-----------------\n";
		///	cout<<indxToStart<<":"<<indexToEnd<<":"<<A.size()<<endl;

			/*for(int v=indxToStart;v<=indexToEnd;v++){
				cout<<A[v]<<" ";
			}*/
			int indxToStart = getRequiredIndex(B[i][1]-1,A.size()-1);
			int indexToEnd = getRequiredIndex(B[i][2]-1,A.size()-1);
			int sub_ans=query(0,0,A.size()-1,
				indxToStart,
				indexToEnd);

			ANS.push_back(sub_ans);
		}
		//logarr(A,0,A.size()-1);
	}
	return ANS;

}



int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<int> A=
		{6430,648,5697,1429,7620,203,8471,5114,3195,1185,665,6829,2418,8657,3784,9168,3139,8696,9509,6963};

		vector<vector<int>> B = 

		{
		{2,6,5663},
		{1,6195,0},
		{1,5466,0},
		{3,16,0},
		{2,4,2673},
		{3,6,0},
		{2,14,5389},
		{2,7,4883},
		{3,12,0} ,
	{4,5,14}, 
	{4,3,10} ,
		{1,9153,0},
		{3,19,0},
		{3,7,0},
		{2,6,3184},
		{2,13,609},
		{3,12,0},//
		{3,10,0},
		{2,3,148},
	{4,14,14}, 
	{4,5,6},
		{2,8,4987},
		{3,6,0},
		{1,2642,0},
		{3,15,0},
		{3,9,0},
		{1,4870,0},
		{3,9,0},
		{3,9,0},
		{1,3292,0},
		{1,6516,0},
		{1,8685,0},
	{4,4,14}, 
		{2,12,4372},{1,1184,0},{3,2,0},
	{4,8,14},
	{4,11,11},
	{4,8,10},
	{4,12,13},
		{3,8,0},{2,8,2456},
	{4,13,15},
		{3,7,0},{2,11,8210},{1,2360,0},{3,9,0},{1,3004,0},
		{2,2,8549},{1,5784,0},
	{4,6,14},{1,9023,0},
	{4,14,15},
		{3,9,0},{1,2743,0},{3,4,0},
	{4,5,6},{1,2398,0},{3,9,0},
		{2,3,9452},{1,9977,0},
	{4,4,15},
	{4,11,12},{3,7,0},
		{3,11,0},{3,6,0},{2,11,8189},{1,7286,0},
		{3,15,0},{3,1,0},{2,11,5592},{2,6,9400},
		{3,13,0},{4,4,4},{3,7,0},{1,2151,0},
		{2,9,4085},{4,2,5},
	{4,1,1},{1,7823,0},
		{1,5877,0}
		 ,{3,2,0},
	{4,9,9},{1,4213,0},{1,2408,0},{4,8,13}
		 ,{3,7,0},{1,7994,0},{1,6018,0},{1,9735,0},{3,16,0}}; 
		 
		vector<int> ANS = solve(A,B);
		cout<<"\n----ANSWER---------------"<<endl;
		if(ANS.size()){
			logarr(ANS,0,ANS.size()-1);
		}
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
