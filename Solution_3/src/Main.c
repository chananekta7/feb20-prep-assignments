/* Maintain an array of ten positive numbers. Initially all elements are set to zero
 * (indicating array is empty). Write a menu driven program to perform operations like
 * add number, delete number, find maximum number (along with its index), find minimum
 * number (along with its index) and sum of numbers. While adding number display
 * available indexes and user can select any of them. If no index is free, display
 * appropriate message. Also while deleting number display available indexes along with
 * values and user can clear value there (set to zero) */

#include<stdio.h>
#include<string.h>
#define SIZE	5
void initialize_array( unsigned int *arr )
{
	memset(arr, 0, sizeof( int ) * SIZE );
}
void insert_element( unsigned int *arr )
{
	int empty = 0;
	for( int index = 0; index < SIZE; ++ index )
	{
		if( arr[ index ] == 0 )
		{
			printf("[ %d ]	:	%d\n",index, arr[ index ] );
			empty = 1;
		}
	}
	if( empty )
	{
		int element,index;
		printf("Enter element	:	");
		scanf("%d", &element);
		printf("Enter index	:	");
		scanf("%d", &index);
		if( index >= 0 && index < SIZE && arr[ index ] == 0 )
			arr[ index ] = element;
		else
			printf("Invalid index.\n");
	}
	else
		printf("Array is full.\n");
}
void delete_element( unsigned int *arr )
{
	int empty = 1;
	for( int index = 0; index < SIZE; ++ index )
	{
		if( arr[ index ] != 0 )
		{
			printf("[ %d ]	:	%d\n",index, arr[ index ] );
			empty = 0;
		}
	}
	if( !empty )
	{
		int index;
		printf("Enter index	:	");
		scanf("%d", &index);
		if( index >= 0 && index < SIZE && arr[ index ] != 0 )
		{
			printf("%d is deleted.\n",arr[ index ]);
			arr[ index ] = 0;
		}
		else
			printf("Invalid index.\n");
	}
	else
		printf("Array is empty.\n");
}
unsigned int find_maximum( unsigned int *arr, int *index )
{
	int i = 0, j = SIZE - 1;
	while( i < j )
	{
		if( arr[ i ] < arr[ j ] )
			++ i;
		else
			 -- j;
	}
	*index = j;
	return arr[ j ];
}
unsigned int find_minimum( unsigned int *arr, int *index )
{
	int i = 0, j = SIZE - 1;
	while( i < j )
	{
		if( arr[ i ] > arr[ j ] )
			++ i;
		else
			 -- j;
	}
	*index = j;
	return arr[ j ];
}
int sum( unsigned int *arr )
{
	unsigned int result = 0;
	for( int index = 0; index < SIZE; ++ index )
		result = result + arr[ index ];
	return result;
}
void print_elements( unsigned int *arr )
{
	for( int index = 0; index < SIZE; ++ index )
		printf("[ %d ]	:	%d\n",index, arr[ index ] );
}
void print_record( const char *message, int element )
{
	printf("%s%d\n",message,element);
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Insert Element\n");
	printf("2.Delete Element\n");
	printf("3.Find Maximum\n");
	printf("4.Find Minimum\n");
	printf("5.Sum of elements\n");
	printf("6.Print elements\n");
	printf("Enter choice	:	");
	scanf("%d", &choice );
	return choice;
}
int main( void )
{
	unsigned int arr[ SIZE ],element;
	initialize_array( arr );
	int choice, index;
	while( ( choice = menu_list( ) ) != 0 )
	{
		switch( choice )
		{
		case 1:
			insert_element( arr );
			break;
		case 2:
			delete_element( arr );
			break;
		case 3:
			element = find_maximum( arr, &index );
			print_record("Maximum element : ", element );
			print_record("Found at index : ", index );
			break;
		case 4:
			element = find_minimum( arr, &index );
			print_record("Minimum element : ", element );
			print_record("Found at index : ", index );
			break;
		case 5:
			print_record("Sum of elements is	:	", sum( arr ) );
			break;
		case 6:
			print_elements(arr);
			break;
		}
	}
	return 0;
}
