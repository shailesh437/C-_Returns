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
int getLongestLength1(vector<int> &row,int rowSize){
	vector<int> LF(rowSize);
	vector<int> RT(rowSize);
	LF[0]=-1;
	RT[row[rowSize-1]]=rowSize;
	for(int i=1;i<rowSize;i++){
		int j=i-1;
		while(j>=0 and row[j]>=row[i])j--;
		LF[i]=j;
	}
	for(int i=0;i<rowSize;i++){
		int j=i+1;
		while(j<rowSize and row[j]>=row[i])j++;
		RT[i]=j;
	}
	int globalRowMax=0;
	for(int i=0;i<rowSize;i++){
		int localRowMax = row[i]*(RT[i]-LF[i]-1);
		globalRowMax = max(globalRowMax,localRowMax);
	}
	return globalRowMax;
}

int getLongestLength2(vector<int> &row,int rowSize){
	vector<int> LB(rowSize);
	vector<int> RB(rowSize);
	stack<int> STACK;
	LB[0]=-1;
	RB[rowSize-1]=rowSize;
	//index stored .. and area = SELF-VALUE* (RB-LB)
	STACK.push(0);
	//LB
	for(int i=1;i<rowSize;i++){
		while(STACK.size()>0 and row[i]<=row[STACK.top()]){
			STACK.pop();
		}
		if(STACK.empty()){
			LB[i]=-1;
		}else{
			LB[i]= STACK.top();
		}
		STACK.push(i);
	}
	while(!STACK.empty()){
		STACK.pop();
	}

	//RB
	STACK.push(rowSize-1);
	RB[rowSize-1]=rowSize; 
	for(int i=rowSize-2;i>=0;i--){
		while(STACK.size()>0 and row[i]<=row[STACK.top()]){
			STACK.pop();
		}
		if(STACK.empty()){
			RB[i]=rowSize;
		}else{
			RB[i]= STACK.top();
		}
		STACK.push(i);
	}

	int globalRowMax=0;
	cout<<"\n----------------------------\n";
	for(int i=0;i<rowSize;i++){
		int localRowMax = row[i]*(RB[i]-LB[i]-1);
		cout<<endl<<row[i]<<" "<<LB[i]<<":::"<<RB[i]<<"::"<<localRowMax<<endl;
		globalRowMax = max(globalRowMax,localRowMax);
	}
	cout<<"\n----------------------------"<<globalRowMax<<"\n";
	return globalRowMax;
}



int getLongestLength(vector<int> &row,int rowSize){
	stack<int> STACK;
	int globalRowMax=0;
	int localMaxRect=0;
	int i=0;
	while(i<rowSize){
		if(STACK.empty() or row[STACK.top()] <=row[i]){
			STACK.push(i++);
		}else{
			int ht = row[STACK.top()];
			STACK.pop();
			int area = 0;
			if(!STACK.empty()){
				area = ht*(i-STACK.top()-1);
			}else{
				area = ht*i;
			}
			globalRowMax = max(globalRowMax,area);			
		}
	}
	while(!STACK.empty()){
		int ht = row[STACK.top()];
		STACK.pop();
		int area = 0;
		if(!STACK.empty()){
			area = ht*(i-STACK.top()-1);
		}else{
			area = ht*i;
		}
		globalRowMax = max(globalRowMax,area);
	}
	return globalRowMax;
}

void prepareRow(vector<int> &finalRow,
	vector<int> &newRow, int m){
	for(int i=0;i<m;i++){
		if(newRow[i]){
			finalRow[i] += 1;
		}else{
			finalRow[i] = 0;
		}
	}
}

int maxArea(int M[][4], int n, int m) {
        // Your code here
	vector<vector<int>> matrix(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		vector<int> r; 
		for(int j=0;j<m;j++){
			r.push_back(M[i][j]);
		}
		matrix[i]=r;
		//logarr(matrix[i],0,3);
	}
	vector<int> finalRow ;
	//cout<<endl;
	finalRow.insert(finalRow.end(),matrix[0].begin(),matrix[0].end());
	//return 0; 
	int globalMaxRect=getLongestLength(finalRow,m);	
	map<vector<int> ,int> dp;
	for(int i=1;i<n;i++){
		prepareRow(finalRow,matrix[i],m);
		//cout<<endl<<"finalRow = "<<endl;
		//logarr(finalRow,0,3);
		int localMaxRect = getLongestLength(finalRow,m);

		//cout<<endl<<"locMax = "<<localMaxRect<<endl;
		globalMaxRect = max(globalMaxRect,localMaxRect);
	} 
	return globalMaxRect;  
}

int findFor2Col(int M[][2], int n, int m){
	int g=0;
	int l=0;

	for(int i=0;i<n;i++){
		if(M[i][0]){
			l++;
			g=max(g,l);
			continue;
		}
		l=0;
	}
	for(int i=0;i<n;i++){
		if(M[i][1]){
			l++;
			g=max(g,l);
			continue;
		}
		l=0;
	}
	g=0;
	l=0;
	cout<<g<<"{"<<l;
	for(int i=0;i<n;i++){
		if(M[i][1] & M[i][0]){
			l+=2;
			g=max(g,l);
			continue;
		}
		l=0;
	}
	return g;
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){

		int n = 4, m = 4;
		int M[][4] = {{0 ,1 ,1 ,0},
				      {1 ,1 ,1 ,1},
					  {1 ,1 ,1 ,1},
				      {1 ,1 ,0 ,0}};


		/*int n = 2, m= 5;
		int M[][5]={{1 ,1 ,1 ,1 ,1},
					{0 ,1 ,0 ,0 ,0}
	};*/

		/*int n=12,m=2;
		int M[][2]={
			{1, 1}
			,{1, 1}
			,{0, 0}
			,{1, 0}
			,{0, 0}
			,{0, 1}
			,{1, 1}
			,{1, 0}
			,{1, 1}
			,{0, 1}
			,{0, 0}
			,{1, 1}
		}; 
		int finalAns = findFor2Col(M,n,m);  
		cout<<"\n\nANS = "<<finalAns; */
		/*vector<int> test = {3,4,0,0};
		cout<<getLongestLength(test);*/

		int ans1 = maxArea(M,n,m);
		cout<<ans1; 		 	  
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
