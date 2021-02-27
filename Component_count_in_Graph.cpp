#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(y);
	}
	void dfs_helper(T src, map<T, bool> &visited) {
		//recursive func
		cout << src << " ";
		visited[src] = true;
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void dfs_countComponent() {
		map<T, bool> visited;
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		int component=1;
		for(auto p: l){
			if(!visited[p.first]){
				cout<<"\nComponent : "<<component<<"-->";
				dfs_helper(p.first,visited);
			}
		}
	}
};
int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 3);
	/* 2nd component */
	g.addEdge(5, 6);
	g.addEdge(6,7);

	g.dfs_countComponent();	
}
