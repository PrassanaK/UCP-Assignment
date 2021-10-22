/*
 * Name: Prassana Kamalakanna
 * Date Modified: 27/05/18
 * Function: contains functions that define a double ended double linkedlist
 * 
 * NOTE: I have previously submitted this file for worksheet6 in the practical. It has since been modified from single ended linked list to a doubly ended double linked list
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/*Creates empty linked list and allocates memory to it */

LinkedList* createLinkedList()
{
    LinkedList* linkedlist;
    linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    return linkedlist;
}

/*Inserts element into linked list
 *newNode's next points to first node
 *head points to newNode */
void insertFirst(LinkedList* linkedlist, void* data)
{
    LinkedListNode* newNode;
    /*linkedlist->head;*/
    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = data;
    newNode->next = linkedlist->head;
    newNode->prev = NULL;
    linkedlist->head->prev = newNode;
    linkedlist->head = newNode;
}
/*
 * Inserts Element into end of linked list
 * newNode's prev points to last node
 * tail points to newNode*/
void insertLast(LinkedList* linkedlist, void* data)
{
    LinkedListNode* newNode; 
    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = data;
    newNode->next = linkedlist->tail->next;
    newNode->prev = linkedlist->tail;
    linkedlist->tail = newNode;
}

/*Deletes an element
 * Copy of head pointer made
 * head pointer set to second element
 * first value freed
 * first node freed */
void removeFirst(LinkedList* linkedlist)
{
    LinkedListNode* temp;
    temp = (linkedlist->head);
    (linkedlist->head) = linkedlist->head->next;
    free(temp->data);
    free(temp);
}

/*current node points to head 
 * while current exists iterate through linked list
 * if count = linked list index, return that data
 * point current to the next node */
void* retrieveElement(LinkedList* linkedlist, int index)
{
    int count = 0;
    void* data = NULL;
    LinkedListNode* current;
    current=linkedlist->head;

    while(current != NULL)
    {
        if (count == index)
        {
            data = current->data;
        }
        count++;
        current = current->next;
    }
    return data;
}

/*
 * Frees memory allocated to linked list after we have finished with it*/ 
void freeLinkedList(LinkedList* list)
{
    LinkedListNode *current, *nextNode;
    current = list->head;

    while(current != NULL)
    {
        nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }
    free(list);
}
