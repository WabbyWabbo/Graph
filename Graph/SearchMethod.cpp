#include "ALGraph.h"

//Breadth-First-Search
void BFS(ALGraph G, int v) {
	visit(G,v);
	visited[v] = true;
	queue<int> Q;
	Q.push(v);
	while (!Q.empty()) {
		int temp = Q.front();
		Q.pop();
		for (int w = FirstNeighbor(G, temp); w >= 0; w = NextNeighbor(G, temp, w)) {
			if (!visited[w]) {
				visit(G,w);
				visited[w] = true;
				Q.push(w);
			}
		}
	}
}

//Depth-First-Search
void DFS(ALGraph G, int v) {
	visit(G, v);
	visited[v] = true;
	for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
		if (!visited[w]) {
			DFS(G, w);
		}
	}
}

//test method
int main(void) {
	ALGraph G1 = CreateOneInstance();
	BFS(G1, 0);
	cout << "\n--------\n";
	ALGraph G2 = CreateOneInstance();
	DFS(G2, 0);

	return 0;
}