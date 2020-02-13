#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/Inventory.h"
const char *fileName = "Inventory.db";
Item_t* create_item( void )
{
	Item_t* item = ( Item_t* )malloc( sizeof( Item_t ) );
	return item;
}
void init_inventory( Inventory_t *const this )
{
	init_linkedlist( &this->itemList );
}
void add_item( Inventory_t *const this, Item_t *item )
{
	add_last(&this->itemList, item);
}
Item_t* search_item_by_name( Inventory_t *const this, char *name )
{
	Item_t *searchItem = create_item( );
	strcpy(searchItem->name, name );
	Item_t *item = find_by_name(&this->itemList, searchItem);
	free( searchItem );
	return item;
}
Item_t* search_item_by_id( Inventory_t *const this, int id )
{
	Item_t *searchItem = create_item( );
	searchItem->id = id;
	Item_t *item = find_by_id(&this->itemList, searchItem);
	free( searchItem );
	return item;
}
bool delete_item_by_name( Inventory_t *const this, char *name )
{
	Item_t *searchItem = create_item( );
	strcpy(searchItem->name, name );
	return remove_item_by_name(&this->itemList, searchItem);
}
bool delete_item_by_id( Inventory_t *const this, int id )
{
	Item_t *searchItem = create_item( );
	searchItem->id = id;
	return remove_item_by_id(&this->itemList, searchItem);
}
void print_items( Inventory_t *const this, void ( *print )( Item_t * ) )
{
	print_list( &this->itemList, print );
}
void save_inventory( Inventory_t *const this )
{
	FILE *fp = fopen( fileName, "wb");
	if( fp != NULL )
	{
		Node_t *trav = this->itemList.head;
		while( trav != NULL )
		{
			fwrite(trav->data, sizeof( Item_t ), 1,  fp );
			trav = trav->next;
		}
		fclose(fp);
	}
}
int get_last_id( )
{
	int id = 0;
	FILE *fp = fopen( fileName, "rb");
	if( fp != NULL )
	{
		fseek(fp, - sizeof( Item_t), SEEK_END);
		if( fp != NULL )
		{
			Item_t *item = ( Item_t* )malloc( sizeof( Item_t ) );
			fread(item, sizeof( Item_t ), 1, fp );
			id = item->id;
			free( item );
		}
		fclose(fp);
	}
	return id;
}
void load_inventory( Inventory_t *const this )
{
	FILE *fp = fopen( fileName, "rb");
	if( fp != NULL )
	{
		while( !feof(fp))
		{
			Item_t *item = ( Item_t* )malloc( sizeof( Item_t ) );
			fread(item, sizeof( Item_t ), 1, fp );
			if( !feof( fp ) )
				add_last(&this->itemList, item);
		}
		fclose(fp);
	}
}
void clear_inventory( Inventory_t *const this )
{
	clear_list( &this->itemList );
}
