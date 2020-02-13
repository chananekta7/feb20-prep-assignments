/* Simulate string library functions strcpy, strcat, strcmp and strrev. */

#include<stdio.h>
void swap( char *const ch1, char *const ch2 )
{
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}
int string_length( const char *str )
{
	int length = 0;
	int index = 0;
	while( str[ index ++ ] != '\0')
		++ length;
	return length;
}
char* string_reverse( char *str )
{
	int i = 0;
	int j = string_length(str) - 1;
	while( i < j )
		swap( &str[ i ++ ], &str[ j -- ] );
	return str;
}
char* string_copy( char *dest, const char *src )
{
	int index = 0;
	while( src[ index ] != '\0' )
	{
		dest[ index ] = src[ index ];
		++ index;
	}
	dest[ index ] = '\0';
	return dest;
}
char* string_concat( char *dest, const char *src )
{
	int i = 0, j = 0;
	while( dest[ i ] != '\0') ++ i;
	while( src[ j ] != '\0' )
		dest[ i ++ ] = src[ j ++ ];
	dest[ i ] = '\0';
	return dest;
}
int string_compare( const char *s1, const char *s2 )
{
	if( string_length(s1) > string_length(s2))
		return 1;
	else if( string_length(s1) < string_length(s2))
		return -1;
	else
	{
		int i = 0;
		while( s1[ i ] != '\0' && s2[ i ] != '\0')
		{
			if( s1[ i ] - s2[ i ] == 0 )
			{
				++ i;
				continue;
			}
			else
				return s1[ i ] > s2[ i ]  ? 1 : -1;
		}
		return 0;
	}
}
void accept_record( char *message, char *str )
{
	printf("%s",message);
	scanf("%s",str);
}
void print_record( char *message, char *str )
{
	printf("%s%s\n",message, str);
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.String Copy\n");
	printf("2.String Concat\n");
	printf("3.String Compare\n");
	printf("4.String Reverse\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}
int main( void )
{
	int choice;
	char src[ 50 ];
	char dest[ 50 ];
	while( ( choice = menu_list( ) ) != 0 )
	{
		char *retStr = NULL;
		switch( choice )
		{
		case 1:
			accept_record("Enter source string	:	", src);
			retStr = string_copy(dest, src);
			print_record("Destination String is : ", dest);
			break;
		case 2:
			accept_record("Enter source string	:	", src);
			accept_record("Enter dest string	:	", dest);
			retStr = string_concat(dest, src);
			print_record("Destination String is : ", dest);
			break;
		case 3:
			accept_record("Enter first string	:	", src);
			accept_record("Enter second string	:	", dest);
			int status = string_compare(src, dest);
			printf("%s\n", ( status == 0 ? "Strings are equal" : "Strings are not equal" ) );
			break;
		case 4:
			accept_record("Enter string	:	", src);
			retStr = string_reverse(src);
			print_record("Reverse String is : ", retStr);
			break;
		}
	}
	return 0;
}
