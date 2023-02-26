struct TrieNode{
    char data;
    TrieNode* child[26];
    int freq;
    bool eow;
    TrieNode(char x) : data(x), eow(false),freq(0) {}
};

void insertToTrie(TrieNode* root,string s){
    TrieNode* curr=root;
    for(int i=0;i<s.length();i++){
        int idx = s[i]-'a';
        if(curr->child[idx]==NULL){
            curr->child[idx]= new TrieNode(s[i]);
            for(int i=0;i<26;i++)
                curr->child[idx]->child[i]=NULL;
        }
        curr->child[idx]->freq++;
        curr=curr->child[idx];
    }
    curr->eow=true;
}
string getMinPrefix(TrieNode* root,string S){
    TrieNode* curr=root;
    vector<char> ans;
    int charCount=0;
    for(int i=0;i<S.length();i++){
        int idx=S[i]-'a';
        if(curr->child[idx]->freq > 1){ 
            charCount++;
            curr=curr->child[idx];
        }else{
            break;
        }
    }
    if(charCount==0) return S.substr(0,1);
    return S.substr(0,charCount+1);
}
vector<string> Solution::prefix(vector<string> &A) {
    TrieNode * root = new TrieNode('-');
    for(int i=0;i<26;i++){
        root->child[i]=NULL;
    }
    for(string s: A){
        insertToTrie(root,s);
    }
    vector<string> ANS;
    for(string s: A){
        ANS.push_back(getMinPrefix(root,s));
    }
    return ANS;
}
