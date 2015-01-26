#include <stdlib.h>
#include ".\linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) {
    LLElement *nelement;
    nelement=(LLElement *)malloc(sizeof(LLElement));
    if(nelement!=NULL){
        nelement->next=first;
        nelement->key=key;
        first=nelement;
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) {
    LLElement *nelement;
    LLElement ** temp; 
    nelement=(LLElement*)malloc(sizeof(LLElement));
    if(nelement!=NULL){             
    	temp=&first;
        while(*temp!=NULL)
        temp= &(*temp)->next;
        nelement->next=NULL;
        nelement->key=key;
        *temp=nelement;      
    }
    return first;        
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) {
    LLElement * nelement;
    LLElement ** temp;
    int i;
    nelement=(LLElement *)malloc(sizeof(LLElement));
    if(nelement!=NULL){
        temp = &first;
	for(i=0; i<position; i++){
            temp = &((*temp)->next);
        }
        nelement->next = *temp;
        nelement->key = key;
        *temp = nelement;
    }
    return first;   
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) {
    int i=0;
    while(first!=NULL){
	i++;
	first=first->next;
    }
    return i;
}   

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) {
    int i;
    for(i=0;i<position;i++){
        first=first->next;
    }
    return first->key;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) {
    int r = -1;
    int i;
    for(i=0; i<startPosition; i++) {
        first = first->next;
    }
    while(first != NULL && r == -1) {
        if(first->key == key) {
            r = i;
	}
	first = first->next;
	i++;
    }
    return r;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) {
    if(first!=NULL){
        LLElement *temp;
        temp=first;
	first=first->next;
	free(temp);
    }
    return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) {
    LLElement **temp;
    if(first!=NULL){
	temp=&first;
	while((*temp)->next!=NULL){
            temp = &((*temp)->next);
	}
	free(*temp);
	*temp=NULL;
    }
    return first;     
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) {
    LLElement ** temp;
    LLElement * pDelete;
    int i;
    temp = &first;
    for(i=0; i<position; i++){
        temp = &((*temp)->next);
    }
    pDelete = *temp;
    if((*temp)->next != NULL) {
	*temp = (*temp)->next;
    }
    free(pDelete);
    return first;      
}

/* Empties the list */
LLElement * LLEmptyList(LLElement *first) {
    LLElement *temp;
    while(first!=NULL){
        temp=first;
	first=first->next;
	free(temp);
    }
    return NULL;
}
