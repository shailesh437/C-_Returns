#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> l;
	list<T> ordering;
public:
	void addEdge(string x, string y) {
		l[x].push_back(y);
	}
	void dfs_helper(T src, map<T, bool> &visited,list<T> &ordering) {
		//recursive func
	//	cout << src << " ";
		visited[src] = true;
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}			
		}
		ordering.push_front(src);
	}

	void dfs(T source) {
		map<T, bool> visited;
		
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}
		for(auto p: l){
			if(!visited[p.first]){
				dfs_helper(p.first,visited,ordering);
			}
		}
	}
	void displayTopologicalSort(){
		for(auto node:ordering){
			cout<<node<<" ";
		}
	}
};
int main() {
	Graph<string> g;
	g.addEdge("Python", "Data Preprocessing");
	g.addEdge("Python", "Pytorch");
	g.addEdge("Python", "MLBasics");
	g.addEdge("MLBasics", "DeepLearning");
	g.addEdge( "DeepLearning","FaceRecognition");
	g.addEdge( "DataSet","FaceRecognition");
	
	g.dfs("Python");	

	g.displayTopologicalSort();
}
