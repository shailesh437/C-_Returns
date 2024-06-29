/*
Given an integer array A of size N.

You have to perform two types of query, in each query you are given three integers x,y,z.

If x = 0, then update A[y] = z.
If x = 1, then output the minimum element in the array A between index y and z inclusive.
Queries are denoted by a 2-D array B of size M x 3 where B[i][0] denotes x, B[i][1] denotes y, B[i][2] denotes z.
Problem Constraints

1 <= N, M <= 105

1 <= A[i] <= 109

If x = 0, 1<= y <= N and 1 <= z <= 109

If x = 1, 1<= y <= z <= N


*/


#define ll long long int
vector<ll> segmentTree;
void buildSegmentTree(ll index,ll left, ll right,vector<int> &A){
	if(left==right){
		segmentTree[index]=A[left];
		//cout<<"\nbaseCase::segmentTree["<<index<<"]="<<segmentTree[index];
		return;
	}
	ll m=(left+right)/2;
	buildSegmentTree(2*index+1,left,m,A);
	buildSegmentTree(2*index+2,m+1,right,A);

	segmentTree[index]=min(segmentTree[2*index+1],
						   segmentTree[2*index+2]);
	//cout<<"\nsegmentTree["<<index<<"]="<<segmentTree[index];
}

void update(ll indexOfST,ll l,ll r,ll indexOfInpArrToUpdate,
								      ll newValue,vector<int> &A){
	if(l==r){
		A[indexOfInpArrToUpdate]=newValue;
		segmentTree[indexOfST]=newValue;
		return;
	}
	ll m=(l+r)/2;
	if(indexOfInpArrToUpdate<=m)
		update(2*indexOfST+1,l,m,indexOfInpArrToUpdate,newValue,A);
	else	
		update(2*indexOfST+2,m+1,r,indexOfInpArrToUpdate,newValue,A);
	segmentTree[indexOfST] = min(segmentTree[2*indexOfST+1],
						   segmentTree[2*indexOfST+2]); 
}

ll query(ll segIndex,ll l,ll r,ll ql,ll qr){

	if(ql>r or qr<l){
		return INT_MAX;
	}
	if(ql<=l and qr>=r){
		return segmentTree[segIndex];
	}
	ll m=(l+r)/2;
	return min(query(2*segIndex+1,l,m,ql,qr),
		       query(2*segIndex+2,m+1,r,ql,qr));

}


vector<int> Solution::solve(vector<int> &A, vector<vector<int>> &B) {
    vector<int> ANS;
	ANS.clear();
    segmentTree.clear();
    ll x = (ll)(ceil(log2(A.size())));
    ll segTreeSize = 2*(ll)pow(2,x)-1;
    segmentTree.resize(segTreeSize,0);
    buildSegmentTree(0,0,A.size()-1,A);
    for(int i=0;i<B.size();i++){
        if(B[i][0]==0){
            update(0,0,A.size()-1,B[i][1]-1,B[i][2],A);
        }else{
            int x = (int) query(0,0,A.size()-1,B[i][1]-1,B[i][2]-1);
            ANS.push_back(x);
        }
    }
    return ANS;
}
