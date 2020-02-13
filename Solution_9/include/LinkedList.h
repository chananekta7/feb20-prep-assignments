#ifndef LINKEDLIST_C_
#define LINKEDLIST_C_

#include"../include/Item.h"

typedef int bool;
#define TRUE	1
#define FALSE	0

typedef struct Node
{
	Item_t *data;
	struct Node *next;
}Node_t;

typedef struct LinkedList
{
	Node_t *head;
	Node_t *tail;
}LinkedList_t;

Node_t* create_node( Item_t *data );

void init_linkedlist( LinkedList_t *const this );

bool empty( LinkedList_t *const this );

void add_last( LinkedList_t *const this, Item_t *data );

Item_t* find_by_name( LinkedList_t *const this, Item_t *item );

Item_t* find_by_id( LinkedList_t *const this, Item_t *item );

void remove_first( LinkedList_t *const this );

void remove_last( LinkedList_t *const this );

void remove_node( LinkedList_t *const this, Node_t *node );

bool remove_item_by_name( LinkedList_t *const this, Item_t *item );

bool remove_item_by_id( LinkedList_t *const this, Item_t *item );

void print_list( LinkedList_t *const this, void ( *print )( Item_t* ) );

void clear_list( LinkedList_t *const this );

#endif /* LINKEDLIST_C_ */
