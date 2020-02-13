/*An inventory management system needs to manage data of the items into binary file.
 * Each item have id, name, price and quantity. Write a menu-driven program to implement
 * add, find, display all, edit and delete operations from the items file.
 * Order id (int) should be generated automatically and must be unique.*/

#include<stdio.h>
#include"../include/Inventory.h"
int lastItemId;
void accept_record( Item_t *item )
{
	printf("Enter item details	:	\n");
	//Item id
	item->id = ++ lastItemId;
	printf("Name	:	");
	scanf("%s", item->name);
	printf("Price	:	");
	scanf("%f", &item->price);
	printf("Quantity	:	");
	scanf("%d", &item->quantity);
}
void update_record( Item_t *item )
{
	if( item != NULL )
	{
		printf("Enter item details	:	\n");
		printf("Id	:	%d\n",item->id );
		printf("Name	:	%s\n",item->name);
		printf("New Name	:	");
		scanf("%s", item->name);
		printf("Price	:	%f\n",item->price);
		printf("New Price	:	");
		scanf("%f", &item->price);
		printf("Quantity	:	%d\n", item->quantity);
		printf("New Quantity	:	");
		scanf("%d", &item->quantity);
	}
	else
		printf("Item not found\n");
}
void accept_name( char *name )
{
	printf("Enter name	:	");
	scanf("%s", name );
}
void accept_item_id( int *id )
{
	printf("Enter id	:	");
	scanf("%d", id );
}
void print_record( Item_t *item )
{
	if( item != NULL )
		printf("%-5d%-30s%-8.2f%-5d\n", item->id, item->name, item->price, item->quantity);
}
void print_status( bool removedStatus )
{
	if( removedStatus )
		printf("Item removed successfully.\n");
	else
		printf("Item not found.\n");
}

int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Add Item.\n");
	printf("2.Find Item.\n");
	printf("3.Edit Item.\n");
	printf("4.Remove Item.\n");
	printf("5.Print Item(s)\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}

int find_sub_menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Find Item By Id.\n");
	printf("2.Find Item By Name.\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}

int remove_sub_menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Remove Item By Id.\n");
	printf("2.Remove Item By Name.\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}

int main( void )
{
	int choice, id;
	char name[ 30 ];
	bool removedStatus;

	Inventory_t inventory;
	init_inventory(&inventory);

	load_inventory(&inventory);
	lastItemId = get_last_id( );

	while( ( choice = menu_list( ) ) != 0 )
	{
		Item_t *item = NULL;
		switch( choice )
		{
		case 1:
			item = create_item();
			accept_record(item);
			add_item(&inventory, item);
			break;
		case 2:
			while( ( choice = find_sub_menu_list( ) ) != 0 )
			{
				switch( choice )
				{
				case 1:
					accept_item_id(&id);
					item = search_item_by_id(&inventory, id);
					print_record(item);
					break;
				case 2:
					accept_name(name);
					item = search_item_by_name(&inventory, name);
					print_record(item);
					break;
				}
			}
			break;
		case 3:
			accept_item_id(&id);
			item = search_item_by_id(&inventory, id);
			update_record(item);
			break;
		case 4:
			while( ( choice = remove_sub_menu_list( ) ) != 0 )
			{
				switch( choice )
				{
				case 1:
					accept_item_id(&id);
					removedStatus = delete_item_by_id(&inventory, id);
					print_status(removedStatus);
					break;
				case 2:
					accept_name(name);
					removedStatus = delete_item_by_name(&inventory, name);
					print_status(removedStatus);
					break;
				}
			}
			break;
		case 5:
			print_items(&inventory, print_record );
			break;
		}
	}
	save_inventory(&inventory);
	clear_inventory( &inventory);
	return 0;
}
