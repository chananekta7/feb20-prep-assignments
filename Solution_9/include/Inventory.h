#ifndef INCLUDE_INVENTORY_H_
#define INCLUDE_INVENTORY_H_

#include"../include/LinkedList.h"
typedef struct InventoryManagementSystem
{
	LinkedList_t itemList;
}Inventory_t;
Item_t* create_item( void );
void init_inventory( Inventory_t *const this );
void add_item( Inventory_t *const this, Item_t *item );
Item_t* search_item_by_name( Inventory_t *const this, char *name );
Item_t* search_item_by_id( Inventory_t *const this, int id );
bool delete_item_by_name( Inventory_t *const this, char *name );
bool delete_item_by_id( Inventory_t *const this, int id );
void print_items( Inventory_t *const this, void ( *print )( Item_t * ) );
void save_inventory( Inventory_t *const this );
int get_last_id( );
void load_inventory( Inventory_t *const this );
void clear_inventory( Inventory_t *const this );

#endif /* INCLUDE_INVENTORY_H_ */
