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
struct TrieNode{
	char data;
	TrieNode* child[26];
	bool eow;
	TrieNode(char x) : data(x), eow(false) {}
};
void insertIntoTrie(TrieNode* &root,string S){
	TrieNode* curr=root;
	for(int i=0;i<S.length();i++){
		char x = S[i];
		int idx=x-'a';
		if(curr->child[idx]==NULL){ 
			curr->child[idx]=new TrieNode(x);
			for(int i=0;i<26;i++){
				curr->child[idx]->child[i]=NULL;
			}	
		}
		curr=curr->child[idx];
			
	} 
	curr->eow=true;
}
int searchInTrie(TrieNode* root,string S){
	TrieNode* curr=root;
	for(int i=0;i<S.length();i++){
		int idx = S[i]-'a';
		if(curr->child[idx]!=NULL){ 
			curr=curr->child[idx];	
		}else{
			return 0;
		}
	}
	if(curr->eow==true){
		return 1;
	}
	return 0;
}
vector<int> solve(vector<string> &A, 
	vector<string> &B) {
	vector<int> ans;
	TrieNode* root = new TrieNode('-');
	for(int i=0;i<26;i++){
		root->child[i]=NULL;
	}
	for(int i=0;i<A.size();i++){
		insertIntoTrie(root,A[i]);
	}
	for(int i=0;i<B.size();i++){
		ans.push_back(searchInTrie(root,B[i]));
	}
	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<string> A = { "hat", "cat", "rat"};
		vector<string> B = {"cat","hall","rat","hat"}; 
		vector<int> ans = solve(A,B);
		logarr(ans,0,ans.size()-1);
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
