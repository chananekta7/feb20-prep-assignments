/* Create an array of 10 books with details id, name, price. Sort array in descending
 * order of price using merge sort. Also sort array in ascending order of name using
 * library function qsort().*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE	10
typedef struct Book
{
	char name[ 50 ];
	int id;
	float price;
}Book_t;
void merge( Book_t *arr, int left, int right, int mid )
{
	int i = left, j = mid + 1, k = 0;
	Book_t *temp = ( Book_t* )malloc( sizeof( Book_t ) * ( right - left + 1 ) );
	while( i <= mid && j <= right )
	{
		if( arr[ i ].price > arr[ j ].price)
			temp[ k ++ ] = arr[ i ++ ];
		else
			temp[ k ++ ] = arr[ j ++ ];
	}
	while( i <= mid)
		temp[ k ++ ] = arr[ i ++ ];
	while( j <= right )
		temp[ k ++ ] = arr[ j ++ ];
	for( i = left, j = 0; i <= right; i ++, j ++ )
		arr[ i ] = temp[ j ];
	free( temp );
}
void merge_sort( Book_t *arr, int left, int right )
{
	if( left < right )
	{
		int mid = ( left + right ) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, right, mid);
	}
}
int compare( const void *ptr1, const void *ptr2 )
{
	return ((const Book_t*)ptr1)->price - ((const Book_t*)ptr2)->price;
}
void quick_sort( Book_t *arr )
{
	qsort(arr, SIZE, sizeof( Book_t), compare);
}
void print_books( Book_t *arr )
{
	for( int index = 0; index < SIZE; ++ index )
		printf("%-30s%-5d%-6.2f\n", arr[ index ].name, arr[ index ].id, arr[ index ].price );
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Sort Books[ Ascending	]\n");
	printf("2.Sort Books[ Descending ]\n");
	printf("3.Print Books\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}
int main( void )
{
	Book_t arr[ SIZE ] =
	{
			{"The C Programming Language", 1, 419},
			{"Expert C Programming", 2, 649 },
			{"The C Companion",3, 2775 },
			{"The C++ Programming Language",4,629},
			{"C++ Primer Plus",5,1211},
			{"More Effective C++",6,619},
			{"Effective Java",7,377},
			{"Big Java Early Objects",8,600},
			{"Inside XML",9,1193},
			{"Operating System Concepts",10,575}
	};

	int choice;
	while( ( choice = menu_list( ) ) != 0 )
	{
		switch( choice )
		{
		case 1:
			quick_sort(arr);
			print_books(arr);
			break;
		case 2:
			merge_sort(arr, 0, 9);
			print_books(arr);
			break;
		case 3:
			print_books(arr);
			break;
		}
	}
	return 0;
}
