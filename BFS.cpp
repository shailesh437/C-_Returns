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

	void bfs(T src) {
		queue<T> q;
		map<T, bool> visited;
		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			T frontMember = q.front();
			cout << frontMember << "  ";
			q.pop();
			for (T nbr : l[frontMember]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};
int main() {
	/*Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs(0);
	*/cout << endl;
	Graph<int> g1;
	g1.addEdge(0, 3);
	g1.addEdge(0, 2);
	g1.addEdge(0, 1);
	g1.addEdge(3, 4);
	g1.addEdge(3, 5);
	g1.bfs(0);

}
