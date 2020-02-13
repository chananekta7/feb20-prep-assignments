/*
 * LinkedList.h
 *
 *  Created on: 23-Jan-2020
 *      Author: sandeepkulange
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include"../include/Account.h"

typedef int bool;
#define TRUE	1
#define FALSE	0

typedef struct Node
{
	struct Node *prev;
	Account_t *data;
	struct Node *next;
}Node_t;
typedef struct LinkedList
{
	Node_t *head;
	Node_t *tail;
}LinkedList_t;

Node_t* create_node( Account_t *data );
void init_linkedlist( LinkedList_t *const this );
bool empty( LinkedList_t *const this );
void add_first( LinkedList_t *const this, Account_t *data );
void remove_first( LinkedList_t *const this );
void add_last( LinkedList_t *const this, Account_t *data );
void remove_last( LinkedList_t *const this );
void remove_node( LinkedList_t *const this, Node_t *node );
void print_forward( LinkedList_t *const this );
void print_backward( LinkedList_t *const this );
Account_t* find_account_by_id( LinkedList_t *const this, int id );
bool remove_account_by_id( LinkedList_t *const this, int id );
Account_t* find_account_by_name( LinkedList_t *const this, const char *name );
bool remove_account_by_name( LinkedList_t *const this, const char *name );


#endif /* LINKEDLIST_H_ */
