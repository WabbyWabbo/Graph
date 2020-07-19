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

void BFSTraverse(ALGraph G) {
	for (int i = 0; i < G.vexNum; i++)
	{
		visited[i] = false;
	}
	//in case that G is not connected
	for (int i = 0; i < G.vexNum; i++)
	{
		if(!visited[i])
			BFS(G, i);
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

void DFSTraverse(ALGraph G) {
	for (int i = 0; i < G.vexNum; i++)
	{
		visited[i] = false;
	}
	//in case that G is not connected
	for (int i = 0; i < G.vexNum; i++)
	{
		if(!visited[i])
			DFS(G, i);
	}
}

//test method
int main(void) {
	ALGraph G1 = CreateOneInstance();
	BFSTraverse(G1);
	cout << "\n--------\n";
	ALGraph G2 = CreateOneInstance();
	DFSTraverse(G2);

	return 0;
}