#include<iostream>
#include<bits/stdc++.h>
using namespace std; 



struct TrieNode{
    char data;
    unordered_map<int,TrieNode*> child;
    bool eow;
    vector<int> weightPossibleIndexes;
    TrieNode(char x) : data(x), eow(false) {}
};

void insertIntoTrie(TrieNode* &root,
                         string S, 
                         int weight,
                         int index){
    TrieNode* curr = root;
    for(int i=0;i<S.length();i++){
        int idx=S[i]-'a';
        if(curr->child.find(idx)==curr->child.end()){
            curr->child[idx] = new TrieNode(S[i]);
        }
        curr=curr->child[idx];
        if(curr->weightPossibleIndexes.size()>=5) continue;
        curr->weightPossibleIndexes.push_back(index);
    }  
    curr->eow=true;
} 
vector<int> searchInTrie(TrieNode* root,
    string prefix){
   vector<int> ans;                             
   TrieNode * curr=root; 
   for(int i=0;i<prefix.length();i++){
       int idx = prefix[i]-'a';
       if(curr->child.find(idx)!=curr->child.end()){
           curr=curr->child[idx];
       }else{
           return ans;
       }
   }
   return curr->weightPossibleIndexes; 
}   

int main()  { 
    int TC;
    cin>>TC;
    while(TC--){ 
    TrieNode* root = new TrieNode('-'); 
    int M,N;
    cin>>M>>N;
    string S[M];
    for(int i=0;i<M;i++)
        cin>>S[i];
    int weight[M];
    for(int i=0;i<M;i++)
        cin>>weight[i];

    string P[N];
    for(int i=0;i<N;i++)
        cin>>P[i];
    unordered_map<string,TrieNode*> processedStringMap;
    vector<pair<int,string>> weightMap;
    for(int i=0;i<M;i++){
        weightMap.push_back(make_pair(weight[i],S[i]));
    }
    sort(weightMap.rbegin(),weightMap.rend());

    for(int i=0;i<weightMap.size();i++){
            insertIntoTrie(root,
                           weightMap[i].second,
                           weightMap[i].first,
                           i); 
    }
    for(int i=0;i<N ;i++){
        vector<int> prefixApplicableTo = searchInTrie(root,P[i]);
        if(prefixApplicableTo.size()==0){
            cout<<"-1 "<<endl;
        }else{
            for(int i=0;i<prefixApplicableTo.size();i++){
                cout<<weightMap[prefixApplicableTo[i]].second<<" ";
            }
            cout<<endl;
        }
    }
            
    }
    return 0;
}
