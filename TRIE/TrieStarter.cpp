#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	char data;
	bool isTerminal;
	unordered_map<char,Node*> children;
	Node(char ch){
		this->data = ch;
		this->isTerminal = false;
	}
};

class Trie{
public:
	Node* root;
	Trie(){
		this->root = new Node('\0');
	}
	void insert(string str){
		Node* temp = this->root;
		for(int i=0;i<str.length();i++){
			char c = str[i];
			if(temp->children.count(c)){
				temp = temp->children[c];
			}else{
				Node *N = new Node(c);
				temp->children[c] = N;
				temp = N;
			}
		}
		temp->isTerminal = true;
		return;
	}

	bool search(string str){
		Node* temp = this->root;
		for(int i=0;i<str.length();i++){
			char c = str[i];
			if(temp->children.count(c)){
				temp = temp->children[c];
			}else{
				return false;
			}
		}
		return temp->isTerminal == true;
	}

	void dfs_(Node *root, string str,string tillNow){
		if(root == NULL){
			return;
		}
		if(root->isTerminal){
			cout<<endl<<"terminal reached    "<<str+tillNow;
		}
		for(auto nod: root->children){
			dfs_(nod.second,str,tillNow + nod.first);
		}
	}
	void printPrefix(string str){
		Node *temp = this->root;
		for(int i=0;i<str.length();i++){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}else{
				cout<<" NOT PRESENT";
				return ;
			}
			dfs_(temp,str,"");
		}
	}
	/*
	void printTrie(){
		Node *temp = this->root;
		cout<<"\5t"<<temp->data<<endl;
		queue<Node*> nodeQ;
		nodeQ.push(temp);
		while(!nodeQ.empty()){
			Node* poppedElement = nodeQ.front();
			nodeQ.pop();
			for(auto child : poppedElement->children){
				cout<<child.first<<" ";
				nodeQ.push(child.second);
			}
			cout<<endl;
		}

	}*/


};
int main(){
	Trie tr;
	string str;
	for(int i=0;i<5;i++){
		cin>>str;
		tr.insert(str);
	}
	cout<<"Enter string u want to search :: ?";
	cin>>str;
	cout<<tr.search(str);
	tr.printPrefix(str);
	//tr.printTrie();
	return 0;
}
