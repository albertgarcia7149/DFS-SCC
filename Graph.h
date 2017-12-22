//-----------------------------------
//Albert Garcia
//awgarcia
//pa4
//-----------------------------------

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_

#include "List.h"

#define INF -1
#define NIL 0

typedef struct GraphObj* Graph;

//CONSTRUCTORS-DESTRUCTORS-----------------------------------------
Graph newGraph(int);
void freeGraph(Graph* pG);

//ACCESS FUNCTIONS-------------------------------------------------
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);

//MANIPULATION PROCEDURES------------------------------------------
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);

//OTHER OPERATIONS-------------------------------------------------
void printGraph(FILE* out,Graph G);

#endif