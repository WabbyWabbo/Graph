#include <queue>
#include <iostream>
using namespace std;

#define MaxVertexNum 100
typedef char VertexType;

//Adjacent List
typedef struct ArcNode {
	int adjVex;//adjacent Vertex's no in vertices
	struct ArcNode* next;
	//InfoType info;
}ArcNode;

typedef struct VNode {
	VertexType data;
	ArcNode* first;
}VNode, AdjList[MaxVertexNum];

typedef struct {
	AdjList vertices;
	int vexNum, arcNum;
}ALGraph;

//visited[]
bool visited[MaxVertexNum];

void visit(ALGraph G, int v) {
	cout << G.vertices[v].data << " ";
}

int FirstNeighbor(ALGraph G, int v) {
	return G.vertices[v].first->adjVex;
}

int NextNeighbor(ALGraph G, int v, int w) {
	ArcNode* arcNode = G.vertices[v].first;
	//find the arc which's adjVex == w
	while (arcNode->next != NULL && arcNode->adjVex != w) {
		arcNode = arcNode->next;
	}
	if (arcNode->next == NULL) {
		return -1;//arcnode list is over
	}
	else {
		return arcNode->next->adjVex;
	}

}

ALGraph CreateOneInstance() {
	ALGraph G;
	G.vertices[0].data = 'a';
	G.vertices[1].data = 'b';
	G.vertices[2].data = 'c';
	G.vertices[3].data = 'd';
	G.vertices[4].data = 'e';

	G.vertices[0].first = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[0].first->adjVex = 1;
	G.vertices[0].first->next = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[0].first->next->adjVex = 2;
	G.vertices[0].first->next->next = NULL;

	G.vertices[1].first = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[1].first->adjVex = 0;
	G.vertices[1].first->next = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[1].first->next->adjVex = 3;
	G.vertices[1].first->next->next = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[1].first->next->next->adjVex = 4;
	G.vertices[1].first->next->next->next = NULL;

	G.vertices[2].first = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[2].first->adjVex = 0;
	G.vertices[2].first->next = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[2].first->next->adjVex = 4;
	G.vertices[2].first->next->next = NULL;

	G.vertices[3].first = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[3].first->adjVex = 1;
	G.vertices[3].first->next = NULL;

	G.vertices[4].first = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[4].first->adjVex = 1;
	G.vertices[4].first->next = (ArcNode*)malloc(sizeof(ArcNode));
	G.vertices[4].first->next->adjVex = 2;
	G.vertices[4].first->next->next = NULL;

	G.vexNum = 5;
	G.arcNum = 5;

	for (int i = 0; i < G.vexNum; i++)
	{
		visited[i] = false;
	}

	return G;
}