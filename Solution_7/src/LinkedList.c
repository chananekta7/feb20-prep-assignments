#include<string.h>
#include<stdlib.h>
#include"../include/LinkedList.h"
Node_t* create_node( Account_t *data )
{
	Node_t* newNode = ( Node_t* )malloc( sizeof( Node_t ) );
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void init_linkedlist( LinkedList_t *const this )
{
	this->head = NULL;
	this->tail = NULL;
}
bool empty( LinkedList_t *const this )
{
	if( this->head == NULL )
		return TRUE;
	return FALSE;
}
void add_first( LinkedList_t *const this, Account_t *data )
{
	Node_t *newNode = create_node(data);
	if( empty(this))
		this->tail = newNode;
	else
	{
		newNode->next = this->head;
		this->head->prev = newNode;
	}
	this->head = newNode;
}
void remove_first( LinkedList_t *const this )
{
	if( !empty(this))
	{
		if( this->head == this->tail)
		{
			free( this->head->data );
			free( this->head );
			this->head = this->tail = NULL;
		}
		else
		{
			Node_t *ptrNode = this->head;
			this->head = this->head->next;
			this->head->prev = NULL;
			free( ptrNode->data );
			free( ptrNode );
		}
	}
}
void add_last( LinkedList_t *const this, Account_t *data )
{
	Node_t *newNode = create_node(data);
	if( empty(this))
		this->head = newNode;
	else
	{
		this->tail->next = newNode;
		newNode->prev = this->tail;
	}
	this->tail = newNode;
}
void remove_last( LinkedList_t *const this )
{
	if( !empty(this))
	{
		if( this->head == this->tail)
		{
			free( this->head->data );
			free( this->head );
			this->head = this->tail = NULL;
		}
		else
		{
			this->tail = this->tail->prev;
			free( this->tail->next->data );
			free( this->tail->next );
			this->tail->next = NULL;
		}
	}
}
void remove_node( LinkedList_t *const this, Node_t *node )
{
	if( node != NULL )
	{
		if( node == this->head )
			remove_first(this);
		else if( node == this->tail )
			remove_last(this);
		else
		{
			Node_t *ptrNextNode = node->next;
			free( node->data );
			node->data = ptrNextNode->data;
			ptrNextNode->data = NULL;
			if( ptrNextNode == this->tail )
				remove_last(this);
			else
			{
				node->next = ptrNextNode->next;
				ptrNextNode->next->prev = node;
				free( ptrNextNode );
			}
		}
	}
}
void print_forward( LinkedList_t *const this )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		print_account( trav->data );
		trav = trav->next;
	}
}
void print_backward( LinkedList_t *const this )
{
	Node_t *trav = this->tail;
	while( trav != NULL )
	{
		print_account( trav->data );
		trav = trav->prev;
	}
}
Account_t* find_account_by_id( LinkedList_t *const this, int id )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		if( trav->data->id == id )
			return trav->data;
		trav = trav->next;
	}
	return NULL;
}
bool remove_account_by_id( LinkedList_t *const this, int id )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		if( trav->data->id == id )
		{
			remove_node(this, trav);
			return TRUE;
		}
		trav = trav->next;
	}
	return FALSE;
}
Account_t* find_account_by_name( LinkedList_t *const this, const char *name )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		if( strcmp( trav->data->accountHolder.name, name ) == 0 )
			return trav->data;
		trav = trav->next;
	}
	return NULL;
}
bool remove_account_by_name( LinkedList_t *const this, const char *name )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		if( strcmp( trav->data->accountHolder.name, name ) == 0 )
		{
			remove_node(this, trav);
			return TRUE;
		}
		trav = trav->next;
	}
	return FALSE;
}
void clear( LinkedList_t *const this )
{
	while( !empty(this))
		remove_first(this);
}

