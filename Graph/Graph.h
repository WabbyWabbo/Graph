#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

//1.Matrix
typedef struct {
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
	int vexNum, arcNum;//num in fact
}MGraph;

//2.Adjacent List
typedef struct ArcNode {
	int adjVex;
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

//3.Orthogonal List
typedef struct ArcNode2 {
	int tailVex, headVex;
	struct ArcNode* hLink, * tLink;
	//InfoType info;
}ArcNode2;

typedef struct VNode2 {
	VertexType data;
	ArcNode2* firstIn, * firstOut;
}VNode;

typedef struct {
	VNode2 xList[MaxVertexNum];
	int vexNum, arcNum;
}GLGraph;

//4.Adjacent Multiple List
typedef struct ArcNode3 {
	bool mark;
	int iVex, jVex;
	struct ArcNode3* iLink, * jLink;
	//InfoType info;
}ArcNode3;

typedef struct VNode3 {
	VertexType data;
	ArcNode3* firstEge;
}VNode3;

typedef struct {
	VNode3 adjMutiList[MaxVertexNum];
	int vexNum, arcNum;
}AMLGraph;
