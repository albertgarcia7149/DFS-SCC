//-----------------------------------
//Albert Garcia
//awgarcia
//pa4
//-----------------------------------

#include<stdio.h>
#include "Graph.h"

int main(int argc, char* argv[]){
	//Set graph vertice amount
	int n=4;
	//Make graph of that vertice amount
	Graph A=newGraph(n);
	//Add edges
	printf("adding edge 1,2\n");
	addEdge(A,1,2);
	printf("adding edge 1,4\n");
	addEdge(A,1,4);
	printf("adding edge 1,3\n");
	addEdge(A,1,3);
	printf("adding edge 3,4\n");
	addEdge(A,3,4);
	//Print Adj Matrix
	printGraph(stdout,A);
	//Print order 
	printf("The order of A is: ");
	printf("%d",getOrder(A));
	printf("\n");
	//Add arc
	addArc(A,4,2);
	//Print Adj Matrix
	printGraph(stdout,A);
	//Do BFS
	printf("Calculate BFS of 4\n");
	BFS(A,3);
	//Print parent
	printf("parent of 2:");
	printf("%d",getParent(A,2));
	printf("\n");
	freeGraph(&A);
	
	return (0);
}