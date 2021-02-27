#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Graph {
	int V;
	list<int> *l;
public:
	Graph(int v) {
		this->V = v;
		l = new list<int>[V];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void display(){
		for(int i=0;i<V;i++){
			cout<<"\nvertex: "<<i;
			for(int nbr: l[i]){
				cout<<" "<<nbr;	
			}
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3); 
	g.addEdge(1, 2);
	g.display();
}
