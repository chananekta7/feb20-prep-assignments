/* A CSV file contains movies data in given form. Read the file and load data into a
 * singly linked list of movie objects. Also give facility to find movies by name
 * and by genre.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int bool;
#define TRUE	1
#define FALSE	0

typedef struct Movie
{
	char *name;
	int year;
	char **genre;
	int genreCount;
}Movie_t;
typedef struct Node
{
	Movie_t *data;
	struct Node *next;
}Node_t;
typedef struct LinkedList
{
	Node_t *head;
	Node_t *tail;
}LinkedList_t;
typedef void (*Print)( Movie_t*);
void print_movie( Movie_t *movie )
{
	if( movie != NULL )
	{
		printf("Movie Name	:	%s\n",movie->name);
		printf("Year		:	%d\n", movie->year);
		printf("Genre		:	");
		for( int index = 0; index < movie->genreCount; ++ index )
			printf("%s ", movie->genre[ index ] );
		printf("\n");
	}
	else
		printf("Movie not found\n");
}
void print_movies( Movie_t **movie, int count )
{
	if( movie != NULL )
	{
		for( int index = 0; index < count; ++ index )
			print_movie( movie[ index ] );
	}
}
Movie_t* create_movie( char *name, int year, char **genre, int count )
{
	name[ strlen(name) - 1 ] = '\0';
	Movie_t *movie = ( Movie_t* )malloc( sizeof( Movie_t ) );

	movie->name = ( char* )malloc( sizeof( char ) * 50 );
	strcpy(movie->name, name);

	movie->year = year;

	movie->genreCount = count;

	movie->genre = ( char ** )malloc( sizeof( char* ) * movie->genreCount );
	for( int index = 0; index < movie->genreCount; ++ index )
	{
		movie->genre[ index ] = ( char* ) malloc( sizeof( char ) * 50 );
		strcpy(movie->genre[ index ], genre[ index ] );
	}

	return movie;
}
Node_t* create_node( Movie_t *data )
{
	Node_t* newNode = ( Node_t* )malloc( sizeof( Node_t ) );
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
void add_last( LinkedList_t *const this, Movie_t *data )
{
	Node_t* newNode = create_node(data);
	if( empty(this) )
		this->head = newNode;
	else
		this->tail->next = newNode;
	this->tail = newNode;
}
Movie_t* find_by_name( LinkedList_t *const this, char *name )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		if( strcmp(trav->data->name, name) == 0 )
			return trav->data;
		trav = trav->next;
	}
	return NULL;
}
Movie_t** find_by_genre( LinkedList_t *const this, char *name, int *count )
{
	*count = 0;
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		for( int index = 0; index < trav->data->genreCount; ++ index )
		{
			if( strcasecmp(trav->data->genre[ index ], name ) == 0 )
				++ ( *count );
		}
		trav = trav->next;
	}

	Movie_t** movie = NULL;
	if( count > 0 )
	{
		int j = 0;
		movie = ( Movie_t** )malloc( sizeof( Movie_t* ) * (*count) );
		trav = this->head;
		while( trav != NULL )
		{
			for( int index = 0; index < trav->data->genreCount; ++ index )
			{
				if( strcasecmp(trav->data->genre[ index ], name ) == 0 )
				{
					movie[ j ] = trav->data;
					++ j;
				}
			}
			trav = trav->next;
		}
	}
	return movie;
}
void remove_first( LinkedList_t *const this )
{
	if( !empty(this))
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
			{
				trav = trav->next;
			}
			this->tail = trav;
			free( this->tail->next->data );
			free( this->tail->next );
			this->tail->next = NULL;
		}
	}
}
void print_list( LinkedList_t *const this, Print print )
{
	Node_t *trav = this->head;
	while( trav != NULL )
	{
		print( trav->data );
		trav = trav->next;
	}
}
void clear_list( LinkedList_t *const this )
{
	while( ! empty(this) )
		remove_first(this);
}
const char *fileName = "Movies.csv";

int count_tokens( char *text, const char *sep )
{
	int count = 0;
	text =  strtok(text, sep);
	while( text != NULL )
	{
		++ count;
		text =  strtok(NULL, sep);
	}
	return count;
}
char** get_names( char *text, const char *sep, int *tokens )
{
	char *temp = ( char* )malloc( strlen(text) + 1 );
	strcpy(temp, text);
	int index = 0;
	*tokens = count_tokens(temp, sep);
	free( temp );

	char **arr = ( char** )malloc( sizeof( char* ) * ( *tokens ) );
	text =  strtok(text, sep);
	while( text != NULL )
	{
		arr[ index ] = ( char*)malloc( 50 );
		strcpy( arr[ index ], text );
		text =  strtok(NULL, sep);
		++ index;
	}
	return arr;
}
void free_tokens( char ** arr, int tokens )
{
	for( int index = 0; index < tokens; ++ index )
		free( arr[ tokens ] );
	free( arr );
}
void load( LinkedList_t *list )
{
	FILE *fp = fopen(fileName, "r");
	if( fp != NULL )
	{
		char text[ 250 ];
		while( !feof(fp))
		{
			fgets(text,250,fp);

			int token1;
			char **ptrStr1 = get_names(text,",()", &token1);

			int token2;
			char **ptrStr2 = get_names(ptrStr1[ 3 ], "|", &token2 );

			Movie_t *movie = create_movie( ptrStr1[ 1 ], atoi(ptrStr1[ 2 ] ),  ptrStr2, token2 );
			add_last(list, movie);
		}
		fclose(fp);
	}
}
void accept_name( const char *message, char *name )
{
	fflush(stdin);
	printf("%s", message );
	scanf("%[^\n]s", name );
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Print Movie Details\n");
	printf("2.Find Movie By Name\n");
	printf("3.Find Movie By Genre\n");
	printf("Enter choice	:	");
	scanf("%d", &choice );
	return choice;
}
int main( void )
{
	char name[ 30 ];
	int choice, count;

	LinkedList_t list;
	init_linkedlist(&list);
	load(&list);

	while( ( choice = menu_list( ) ) != 0 )
	{
		Movie_t *movie = NULL;
		Movie_t **movies = NULL;
		switch( choice )
		{
		case 1:
			print_list(&list, print_movie );
			break;
		case 2:
			accept_name("Enter Name	:	", name);
			movie = find_by_name(&list, name);
			print_movie(movie);
			break;
		case 3:
			accept_name("Enter genre	:	",name);
			movies = find_by_genre(&list, name, &count);
			print_movies(movies, count);
			break;
		}
	}
	return 0;
}
