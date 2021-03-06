//-----------------------------------
//Albert Garcia
//awgarcia
//pa4
//-----------------------------------

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_

typedef struct ListObj* List;

//CONSTRUCTOR
List newList(void);
//DESTRUCTOR
void freeList(List* pL);

//HELPER FUNCTIONS
int isEmpty(List L);

//ACCESS FUNCTIONS
int length(List L);
int index(List L);
int front(List L);
int back(List L);
int get(List L);
int equals(List A,List B);

//MANIPULATION PROCEDURES
void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L,int data);
void insertBefore(List L,int data);
void insertAfter(List L,int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);

//OTHER OPERATIONS
void printList(FILE* out,List L);
List copyList(List L);


#endif