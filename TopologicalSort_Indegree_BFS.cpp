#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<cstring>
using namespace std;


class Graph {
	list<int> *l;
	int V;
public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
	}

	void topologicalSort() {
		int *indegree = new int[V];
		for (int i = 0; i < V; i++) {
			indegree[i] = 0;
		}

		//update indegree by traversing edges x->y
		//indegree[y]++
		for (int i = 0; i < V; i++) {
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}
		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int node = q.front();
			cout<<node<< " ";
			q.pop();
			for (int nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}



	}
};
int main() {
	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(2, 5);
	g.addEdge(4, 5);
	g.addEdge(1, 4);

	g.topologicalSort();

}
