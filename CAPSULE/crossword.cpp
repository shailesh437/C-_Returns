// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
 void LTR(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){ 
	//if (grid[0].size()-startCol<(word.length()))
    if((startCol+word.length()) > grid[0].size()){
		return;
	}

	int w ;
	for(int j=startCol;j<(word.length()+startCol);j++){
		 w = j-startCol;
		if(grid[startRow][j]!=word[w])
			return;
	}
	if(w<(word.length()-1))
		return;
	pair<int,int> xy = make_pair(startRow,startCol);
	ans.insert(xy);
}
void RTL(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){
	if (startCol<(word.length()-1)){
		return;
	} 
	int w;
	for(int j=startCol;j>=abs(startCol-(word.length()-1));j--){
		w = startCol-j;
		if(grid[startRow][j]!=word[w])
			return;
	}
	if(w<(word.length()-1))
		return;
	pair<int,int> xy = make_pair(startRow,startCol);
	ans.insert(xy);
}
void TTD(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){
	
	if ((grid.size()-startRow)<(word.length())){
		return;
	}
	int w;
	for(int j=startRow;j<(startRow+word.length());j++){
		w = j-startRow;
		if(grid[j][startCol]!=word[w])
			return;
	}
	if(w<(word.length()-1))
		return;
	pair<int,int> xy = make_pair(startRow,startCol);
	ans.insert(xy);

}
void DTT(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){
	if (startRow<(word.length()-1)){
		return;
	}
	int w;
	for(int j=startRow;j>=abs(startRow-(word.length()-1));j--){
		w = startRow-j;
		if(grid[j][startCol]!=word[w])
			return;
	}
	if(w<(word.length()-1))
		return;
	pair<int,int> xy = make_pair(startRow,startCol);
	ans.insert(xy);	
}
void NE(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){

	if(
		startRow<(word.length()-1)
		or
		startCol>(grid[0].size()-word.length())
		){
		return;
	} 
	int w;	
for(int i=startRow,j=startCol ;
	j<(startCol+word.length()); i--,j++){
	w = j-startCol;
	if(grid[i][j] != word[w]){
		return;
	}
}
if(w<(word.length()-1))
		return;
ans.insert(make_pair(startRow,startCol));	
}
void  NW(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){
	if(
		startRow<(word.length()-1)
		or
		startCol<(word.length()-1)
		){
		return;
}	 
int w;
for(int i=startRow,j=startCol ;
	j>=abs(startCol-(word.length()-1)); i--,j--){
		w = startCol-j;
		if(grid[i][j] != word[startCol-j]){
			return;
		}
	}
	if(w<(word.length()-1))
		return;
	ans.insert(make_pair(startRow,startCol));	
}
void SW(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){
	 
	if(
		startRow>=(grid.size()-(word.length()-1))
		or
		startCol<(word.length()-1)
		){
		return;
}	
int w;
 for(int i=startRow,j=startCol ;
	j>=abs(startCol-(word.length()-1))
	and
	i<(grid.size())
	; i++,j--){
	    w = (startCol-j);
		if(grid[i][j] != word[w]){
			return;
		}
	}
	if(w<(word.length()-1))
		return;
	ans.insert(make_pair(startRow,startCol));

}
void SE(vector<vector<char>>grid,
	int startRow,
	int startCol,
	string word,
	set<pair<int,int>> &ans){
	if(
		startRow>(grid.size()-(word.length()-1))
		or
		startCol>(grid[0].size()-(word.length()-1))
		){
		return;
		}
		int w;
for(int i=startRow,j=startCol ;
	j<=(startCol+word.length()-1) &&
	j<grid[0].size() &&
	i<=(startRow+word.length()-1) &&
	i<grid.size();
	 i++,j++){
	//cout<<grid[i][j];
	//cout<<word[j-startCol];
	w = j - startCol;
	if(grid[i][j] != word[j-startCol]){
		return;
	}
}
if(w<(word.length()-1))
		return;
ans.insert(make_pair(startRow,startCol));	
}
vector<vector<int>> searchWord(vector<vector<char>> grid, 
	string word){
	    // Code here
	set<pair<int,int>> ans;
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			if(grid[i][j]==word[0]){
				LTR(grid,i,j,word,ans);
				RTL(grid,i,j,word,ans);
				DTT(grid,i,j,word,ans);
				TTD(grid,i,j,word,ans);
				NE(grid,i,j,word,ans);
				NW(grid,i,j,word,ans);
				SE(grid,i,j,word,ans);
				SW(grid,i,j,word,ans);
			}
		}
	}
	//cout<<"---------------------->"<<ans.size();
	vector<vector<int>> ANS;

	for(auto x: ans){
		vector<int> xy;
		xy.push_back(x.first);
		xy.push_back(x.second);
		ANS.push_back(xy);

	}

	
	return ANS;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends
