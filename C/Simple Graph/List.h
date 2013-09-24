/* $Id: List.h,v 1.4 2011-10-08 19:09:41-07 - - $ */

/*
 * List.h 
 * Header file for List.c
 * PA2
 * By B Stewart Bracken
 * bbracken@ucsc.edu
 * ID# 1187817
*/

#ifndef __LISTC_H__
#define __LISTC_H__

/* Useful typedefs */
typedef struct List* ListRef;
typedef enum {FALSE = 0, TRUE = 1} bool;


/* Constructor-Destructor for a List */
ListRef newList(void);
void freeList(ListRef* pL);

/* Access functions */
int getFront(ListRef L);
int getLength(ListRef L);
int isEmpty(ListRef L);
int getIndex(ListRef L);
int offEnd(ListRef L);
int getBack(ListRef L);
int getCurrent(ListRef L);
int equals(ListRef L, ListRef P);

/* Manipulation procedures */
void makeEmpty(ListRef L);
void moveTo(ListRef L, int i);
void movePrev(ListRef L);
void moveNext(ListRef L);
void insertFront(ListRef L, int data);
void insertBack(ListRef L, int data);
void insertBeforeCurrent(ListRef L, int data);
void insertAfterCurrent(ListRef L, int data);
void deleteFront(ListRef L);
void deleteBack(ListRef L);
void deleteCurrent(ListRef L);
void EnList(ListRef L, int data);
void DeList(ListRef L);

/* Other functions */
ListRef copyList(ListRef L);
void printList(FILE* out, ListRef L);
void killProgram(char* error);


#endif
