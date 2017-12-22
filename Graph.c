//-----------------------------------
//Albert Garcia
//awgarcia
//pa4
//-----------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"


//STRUCTS-----------------------------------------------------
typedef struct GraphObj{
	List *g;
	char *color;
	int *parent;
	int *distance;
	int arrsize;
	int source;
	int size;
}GraphObj;

//CONSTRUCTORS-DESTRUCTORS------------------------------------
Graph newGraph(int n){
	Graph G= malloc(sizeof(struct GraphObj));
	G->g=calloc(n+1,sizeof(List));
	G->color=calloc(n+1,sizeof(char));
	G->parent=calloc(n+1,sizeof(int));
	G->distance=calloc(n+1,sizeof(int));
	G->arrsize=n;
	G->source=NIL;
	G->size=0;
	for(int i=1; i<=n;i++){
		G->g[i]=newList();
		G->color[i]='w';
		G->distance[i]=INF;
		G->parent[i]=NIL;
	}
	return G;
}
void freeGraph(Graph* pG){
	Graph temp=*pG;
	if(pG!=NULL && temp!=NULL){
		for(int i=1;i<=getOrder(temp);i++){
			freeList(&(temp->g[i]));
		}
		free(temp->g);
		free(temp->color);
		free(temp->parent);
		free(temp->distance);
		free(*pG);
		*pG=NULL;
	}
}
//HELPER FUNCTIONS-------------------------------------------------
void add(List L,int b){
	if(length(L)>0){
		moveFront(L);
		while(index(L)!=-1&&b>get(L)){
			moveNext(L);
		}
		if(index(L)!=-1){
			insertBefore(L,b);
		}else{
			append(L,b);
		}
	}else{
		append(L,b);
	}
	L=NULL;////possible leak
}
//ACCESS FUNCTIONS-------------------------------------------------
int getOrder(Graph G){//num vertices
	return G->arrsize;
}
int getSize(Graph G){//num edges
	return G->size;
}
int getSource(Graph G){
	return G->source;
}
int getParent(Graph G, int u){
	if(u>0 && u<= getOrder(G)){
		int out=G->parent[u];
		return out;
	}else{
		printf("getParent Error: invalid vertex\n");
		exit(1);
	}
}
int getDist(Graph G, int u){
	if(u>0 && u<= getOrder(G)){
		return G->distance[u];
	}else{
		printf("getDist Error: invalid vertex\n");
		exit(1);
	}
}
void getPath(List L, Graph G, int u){
	if(u>0 && u<= getOrder(G)){
		if(u==G->source){
			append(L,u);			
		}else if(G->parent[u]==NIL){
			//do nothing
			append(L,NIL);
		}else{
			getPath(L,G,G->parent[u]);
			append(L,u);
		}
	}else{
		printf("getParent Error: invalid vertex\n");
		exit(1);
	}
}

//MANIPULATION PROCEDURES------------------------------------------
void makeNull(Graph G){
	for(int i=0;i<getOrder(G);i++){
		if(length(G->g[i])!=0){
			clear(G->g[i]);
		}
	}
}
void addEdge(Graph G, int u, int v){
	if(u>0 && u<=getOrder(G) && v>0 && v<=getOrder(G)){
		//insert u to v
		add(G->g[u],v);
		//insert v to u
		add(G->g[v],u);
		G->size++;
	}
}
void addArc(Graph G, int u, int v){
	if(u>0 && u<=getOrder(G) && v>0 && v<=getOrder(G)){
		//insert u to v
		add(G->g[u],v);
		G->size++;
	}
}
void BFS(Graph G, int s){
	//initialize everything to starting values
	for(int i=1; i<=G->arrsize;i++){
		G->color[i]='w';
		G->distance[i]=INF;
		G->parent[i]=NIL;
	}
	G->source=s;
	G->color[s]='g';
	G->distance[s]=0;
	G->parent[s]=0;
	List L = newList();
	append(L,s);
	while(length(L)>0){
		moveFront(L);
		int x =get(L);
		delete(L);
		if(length(G->g[x])>0){
			for(moveFront(G->g[x]); index(G->g[x])!=-1;moveNext(G->g[x])){
				int y=get(G->g[x]);
				if(G->color[y]=='w'){
					G->color[y]='g';
					G->distance[y]=G->distance[x]+1;
					G->parent[y]=x;
					append(L,y);
				}
			}
			G->color[x]='b';
		}
	}
	freeList(&L);
}

//OTHER OPERATIONS-------------------------------------------------
void printGraph(FILE* out,Graph G){
	for(int i=1;i<=getOrder(G);i++){
		fprintf(out,"%d",i);
		fprintf(out,":");
		printList(out,G->g[i]);
	}
}
//For testing purposes
void printTable(Graph G){
	for(int i=1;i<=getOrder(G);i++){
		printList(stdout,G->g[i]);
		printf(" : ");
		printf("%d",G->distance[i]);
		printf(" : ");
		printf("%d",G->parent[i]);
		printf("\n");
	}
}