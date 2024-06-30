#include<bits/stdc++.h>
#define ll long long int

vector<int> segmentTree;

int countOnes(int x){
        return __builtin_popcount(x);
}


void buildSegmentTree(int indxOfST,int l,int r, vector<int> &Arr){
    if(l==r){
        segmentTree[indxOfST]=Arr[l];
        return;
    }
    int m = (l+r)/2;
    buildSegmentTree(2*indxOfST+1,l,m,Arr);
    buildSegmentTree(2*indxOfST+2,m+1,r,Arr);
    segmentTree[indxOfST]=segmentTree[2*indxOfST+1]+
                          segmentTree[2*indxOfST+2];
}


void update(int indxOfST,int l,int r, int idxToUpdate,int valueNew,
            vector<int> &Arr){
    if(l==r){
        Arr[idxToUpdate]=valueNew;        
        segmentTree[indxOfST]=countOnes(valueNew);
        return;
    }
    int m = (l+r)/2;
    if(idxToUpdate<=m)
    update(2*indxOfST+1,l,m,idxToUpdate,valueNew,Arr);
    else
    update(2*indxOfST+2,m+1,r,idxToUpdate,valueNew,Arr);
    segmentTree[indxOfST]=      segmentTree[2*indxOfST+1]+
                                segmentTree[2*indxOfST+2];
}

int query(int segTreeIndx,int l,int r, int ql,int qr){
    if(ql>r or qr<l) return 0;
    if(ql<=l and qr>=r) return segmentTree[segTreeIndx];


    int m = (l+r)/2;
    return query(2*segTreeIndx+1,l,m,ql,qr)+
    query(2*segTreeIndx+2,m+1,r,ql,qr);
}


vector<int> Solution::solve(int A, vector<vector<int> > &B) {

    int x = (int)(ceil(log2(A)));
    int segTreeSize = 2*pow(2,x)-1;
    segmentTree.clear();
    segmentTree.resize(segTreeSize,0);    
    vector<int> Arr;
    Arr.clear();
    Arr.resize(segTreeSize,0);
    buildSegmentTree(0,0,A-1,Arr); 

    vector<int> ANS;
    ANS.clear();
    for(int i=0;i<B.size();i++){
        if(B[i][0]==1){
            update(0,0,A-1,B[i][1]-1,2*Arr[B[i][1]-1]+1,Arr);
        }
        if(B[i][0]==2){
            update(0,0,A-1,B[i][1]-1,(ceil)(Arr[B[i][1]-1]/2),Arr);
        }
        if(B[i][0]==3){
            ANS.push_back(query(0,0,A-1,B[i][1]-1,B[i][2]-1));
        } 

    }
    return ANS;
}
