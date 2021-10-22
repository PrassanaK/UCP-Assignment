/*
 * Name: Prassana Kamalakannan
 * Date Modified: 27/05/18
 * Purpose: declars sructs and method protypes that define a doubly ended double linkedlist */

/*
 * This struct represents a single node of a linked list
 * Contains the value to be stored and pointers to the next and previous nodes to traverse both ways*/
typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;
}LinkedListNode;

/*
 * This struct represents the linked list.
 * Contains pointers called head and tail that points to the first and last node respectively
 * This is what makes it a doubly ended linked list*/
typedef struct
{
    LinkedListNode* head;
    LinkedListNode* tail;
}LinkedList;

/*
 * Method descriptions for these are in the linkedlist.c file*/
LinkedList* createLinkedList();

void insertFirst(LinkedList* linkedlist, void* data);

void insertLast(LinkedList* linkedlist, void* data);

void removeFirst(LinkedList* linkedlist);

void* retrieveElement(LinkedList* linkedlist, int index);

void freeLinkedList(LinkedList* list);
