//-----------------------------------
//Albert Garcia
//awgarcia
//pa4
//-----------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Graph.h"

#define MAX_LEN 160

int main(int argc, char* argv[]){
	
	//Variables
	int n,count=0;
	FILE *in, *out;
	char line[MAX_LEN];
	char tokenlist[MAX_LEN];
	char* token;
	//Check for correct number of files
	if(argc!=3){
		printf("Usage: %s <input file> <output file> \n",argv[0]);
		exit(1);
	}
	//Open files
	in=fopen(argv[1], "r");
	out= fopen(argv[2],"w");
	//Check if infile opened
	if(in==NULL){
		printf("Unable to open file %s for reading\n",argv[1]);
		exit(1);
	}
	//Check if outfile opened
	if(out==NULL){
		printf("Unable to open file %s for writing\n",argv[2]);
		exit(1);
	}
	//Gets Graph Order
	n=atoi(fgets(line,MAX_LEN,in));
	//Create Graph
	Graph A=newGraph(n);
	//Create List
	List L=newList();
	//Get edges
	
	while( fgets(line, MAX_LEN, in) != NULL)  {
		int n1,n2;
		token = strtok(line, " \n");
		n1=atoi(token);
		tokenlist[0] = '\0';
		token = strtok(NULL, " \n");
		n2=atoi(token);
		if(n1==0 && n2==0){
			count++;
		}
		//If count is 0 then we are entering edges
		if(count==0){
			addEdge(A,n1,n2);
		}
		//If count is 1 then we are getting distances and paths
		else if(count==1){
			//Skip 0 0
			if(n1==0 &&n2==0){
				printGraph(out,A);
			}else{
				fprintf(out,"\n");
				BFS(A,n1);
				int a=getDist(A,n2);
				if(a!=INF){
					fprintf(out,"The distance from %d to %d is %d \n",n1,n2,a);
				}else{
					fprintf(out,"The distance from %d to %d is infinity \n",n1,n2);
				}
				getPath(L,A,n2);
				if(length(L)>0&& front(L)!=0){
					fprintf(out,"A shortest %d-%d path is:",n1,n2);
					printList(out,L);
				}else{
					fprintf(out,"No %d-%d path exists\n",n1,n2);
				}
				clear(L);
			}
			
			
		}
		//If count > 1 then we are done
		else{
			
		}
		
   }
	
	
	//Close Files
	fclose(in);
	fclose(out);
	//Free Graphs
	freeGraph(&A);
	//Free List
	freeList(&L);
	
	/*
	Graph A = newGraph(100);
	List L = newList();
	List C = newList();
	
	addArc(A, 54, 1);
        addArc(A, 54, 2);
        addArc(A, 54, 3);
        addArc(A, 1, 54);
        addArc(A, 1, 55);
	
	 addArc(A, 55, 1);
	 
	addArc(A, 64, 4);
        addArc(A, 64, 3);
        addArc(A, 42, 2);
        addArc(A, 2, 64);
        addArc(A, 4, 2);
        addArc(A, 3, 42);
		
		addArc(A, 64, 4);
        addArc(A, 64, 3);
        addArc(A, 42, 2);
        addArc(A, 2, 64);
        addArc(A, 4, 2);
        addArc(A, 3, 42);
		
		addArc(A, 64, 4);
        addArc(A, 64, 3);
        addArc(A, 42, 2);
        addArc(A, 2, 64);
        addArc(A, 4, 2);
        addArc(A, 3, 42);
        BFS(A, 3);
        getPath(L, A, 64);
        append(C, 3);
        append(C, 42);
        append(C, 2);
        append(C, 64);
		
		moveFront(L);
        BFS(A, 2);
        getPath(L, A, 2);
        append(C, 2);
	
		getPath(L, A, 99);
		clear(L);
        clear(C);
        append(C, NIL);
        BFS(A, 99);
		getPath(L, A, 2);
		printList(stdout,L);
		printList(stdout,C);
		printf("eq: %d\n",!equals(C, L));*/
	
	return (0);
}