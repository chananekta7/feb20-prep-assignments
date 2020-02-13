#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/LinkedList.h"

Node_t* create_node( Item_t *data )
{
	Node_t *newNode = ( Node_t* )malloc( sizeof( Node_t) );
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
	return this->head == NULL;
}

void add_last( LinkedList_t *const this, Item_t *data )
{
	Node_t *newNode = create_node(data);
	if( empty(this))
		this->head = newNode;
	else
		this->tail->next = newNode;
	this->tail = newNode;
}

Item_t* find_by_name( LinkedList_t *const this, Item_t *item )
{
	if( !empty(this))
	{
		Node_t *trav = this->head;
		while( trav != NULL )
		{
			if( strcmp(trav->data->name, item->name) == 0 )
				return trav->data;
			trav = trav->next;
		}
	}
	return NULL;
}

Item_t* find_by_id( LinkedList_t *const this, Item_t *item)
{
	if( !empty(this))
	{
		Node_t *trav = this->head;
		while( trav != NULL )
		{
			if( trav->data->id == item->id )
				return trav->data;
			trav = trav->next;
		}
	}
	return NULL;
}

void remove_first( LinkedList_t *const this )
{
	if( !empty(this) )
	{
		if( this->head == this->tail )
		{
			free( this->head->data );
			free( this->head );
			this->head = this->tail = NULL;
		}
		else
		{
			Node_t *ptrNode = this->head;
			this->head = this->head->next;
			free( ptrNode->data );
			free( ptrNode );
		}
	}
}

void remove_last( LinkedList_t *const this )
{
	if( !empty(this) )
	{
		if( this->head == this->tail )
		{
			free( this->head->data );
			free( this->head );
			this->head = this->tail = NULL;
		}
		else
		{
			Node_t *trav = this->head;
			while( trav->next != this->tail )
				trav = trav->next;
			this->tail = trav;
			free( this->tail->next->data );
			free( this->tail->next );
			this->tail->next = NULL;
		}
	}
}

void remove_node( LinkedList_t *const this, Node_t *node )
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
			free( ptrNextNode );
		}
	}
}

bool remove_item_by_name( LinkedList_t *const this, Item_t *item )
{
	if( !empty(this))
	{
		Node_t *trav = this->head;
		while( trav != NULL )
		{
			if( strcmp(trav->data->name, item->name) == 0 )
			{
				remove_node(this, trav);
				return TRUE;
			}
			trav = trav->next;
		}
	}
	return FALSE;
}

bool remove_item_by_id( LinkedList_t *const this, Item_t *item )
{
	if( !empty(this))
	{
		Node_t *trav = this->head;
		while( trav != NULL )
		{
			if( trav->data->id == item->id )
			{
				remove_node(this, trav);
				return TRUE;
			}
			trav = trav->next;
		}
	}
	return FALSE;
}

void print_list( LinkedList_t *const this, void ( *print )( Item_t* ) )
{
	if( !empty(this) )
	{
		Node_t *trav = this->head;
		while( trav != NULL )
		{
			print( trav->data );
			trav = trav->next;
		}
	}
}
void clear_list( LinkedList_t *const this )
{
	while( !empty(this))
		remove_first(this);
}
