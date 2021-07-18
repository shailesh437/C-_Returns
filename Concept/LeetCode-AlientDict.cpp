#include<bits/stdc++.h>
using namespace std;

string getOrderOfAlpha(vector<string> inputWords){
    unordered_map<char,list<char>> adhacencyList;
    unordered_map<char,int> indegree;

    //initialize Graph
    for(string s: inputWords){
        for(char ch: s){
            indegree[ch]=0;
            list<char> lst;
            adhacencyList[ch]=lst;
        }
    }

    //depenency 
    for(int i=0;i<inputWords.size()-1;i++){
        string word1=inputWords[i];
        string word2=inputWords[i+1];
        auto check = mismatch(word2.begin(),word2.end(),word1.begin());
        if(word1.size()>word2.size() and  word2.end()==check.first){
            return "";
        }
        for(int j=0;j<min(word1.size(),word2.size());j++){
            if(word1[j]!=word2[j]){
                indegree[word2[j]]+=1;
                adhacencyList[word1[j]].push_back(word2[j]);
            }
        }
    }

    //PRE-BFS;
    queue<char> q;
    string ans="";
    //push al nodes with indegree=ZERO in Queue
    for(auto it=indegree.begin();it!=indegree.end();it++){
        if(it->second==0){
            q.push(it->first);
        }
    }
    //BFS
    while(!q.empty()){
        char X = q.front();
        q.pop();
        ans+=X;
        for(char neighbour: adhacencyList[X]){
            indegree[neighbour]-=1;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
            //cout<<endl<<"IN FOR :: ans till now "<<ans<<endl;
            //cin>>FF;
        }

    }

    //if cycle is there
    if( ans.length() < indegree.size()){
       ans =  "";
    }
    return ans;
}
int main(){
    vector<string> inputWords(5);
    inputWords[0]="wrt";
    inputWords[1]="wrf";
    inputWords[2]="er";
    inputWords[3]="ett";
    inputWords[4]="rftt";

    cout<<getOrderOfAlpha(inputWords);
    return 0;
}
