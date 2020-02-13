/* Implement a circular queue of students. Each student information includes
 * roll, name, std, subject names and corresponding subject marks. Assume that each
 * student hold subject names & marks of 6 subjects. Write a menu-driven program to
 * implement push and pop functionality.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct SubjectDetails
{
	char name[ 50 ];
	int marks;
}SubjectDetails_t;
#define SUBJECT_COUNT	2
typedef struct Student
{
	char name[ 50 ];
	int roll;
	char std[5];
	SubjectDetails_t arr[ SUBJECT_COUNT ];
}Student_t;
void accept_subject_deatils( SubjectDetails_t *arr )
{
	for( int index = 0; index < SUBJECT_COUNT; ++ index )
	{
		fflush( stdin);
		printf("Subject	:	");
		scanf("%s", arr[ index ].name);
		printf("Marks	:	");
		scanf("%d", &arr[ index ].marks);
	}
}
void accept_student_record( Student_t *ptrStudent )
{
	printf("Name		:	");
	scanf("%s", ptrStudent->name);
	printf("Roll Number	:	");
	scanf("%d", &ptrStudent->roll);
	accept_subject_deatils(ptrStudent->arr);
}
void print_subject_deatils( SubjectDetails_t *arr )
{
	for( int index = 0; index < SUBJECT_COUNT; ++ index )
		printf("%-30s%-3d\n",arr[ index ].name, arr[ index ].marks );
}
void print_student_record( Student_t *ptrStudent )
{
	if( ptrStudent != NULL )
	{
		printf("Name		:	%s\n", ptrStudent->name);
		printf("Roll Number	:	%d\n", ptrStudent->roll);
		print_subject_deatils(ptrStudent->arr);
	}
}
typedef int bool;
#define TRUE	1
#define FALSE	0
#define SIZE	5
typedef struct Queue
{
	int rear, front;
	Student_t *arr[ SIZE ];
}Queue_t;
typedef void (*Error)( const char* );
void init_queue( Queue_t *const this )
{
	this->rear = -1;
	this->front = -1;
}
bool empty( Queue_t *const this )
{
	if( this->rear == -1 )
		return TRUE;
	return FALSE;
}
bool full( Queue_t *const this )
{
	if( ( this->rear + 1 ) % SIZE == this->front )
		return TRUE;
	return FALSE;
}
void print_error_message( const char *message )
{
	printf("%s\n", message );
}
void enqueue( Queue_t *const this, Student_t *ptrStudent, Error error )
{
	if( full(this) )
		error("Queue is full.");
	else
	{
		if( this->rear == -1 )
			this->front = 0;
		this->rear = ( this->rear + 1 ) % SIZE;
		this->arr[ this->rear ] = ptrStudent;
	}
}
Student_t* peek( Queue_t *const this )
{
	if( empty(this) )
		return NULL;
	return this->arr[ this->front ];
}
void dequeue( Queue_t *const this, Error error )
{
	if( empty(this) )
		error("Queue is empty.");
	else
	{
		if( this->rear == this->front )
		{
			free( this->arr[ this->front ] );
			this->arr[ this->front ] = NULL;
			this->rear = this->front = -1;
		}
		else
		{
			free( this->arr[ this->front ] );
			this->arr[ this->front ] = NULL;
			this->front = ( this->front + 1 ) % SIZE;
		}
	}
}
void clear( Queue_t *const this )
{
	while( !empty(this))
		dequeue(this, NULL);
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.EnQueue\n");
	printf("2.Dequeue\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}
int main( void )
{
	int choice;
	Queue_t que;
	init_queue(&que);
	while( ( choice = menu_list( ) ) != 0 )
	{
		Student_t *student = NULL;
		switch( choice )
		{
		case 1:
			student = ( Student_t* )malloc( sizeof( Student_t ) );
			accept_student_record(student);
			enqueue(&que, student, print_error_message);
			break;
		case 2:
			student = peek(&que );
			print_student_record(student);
			dequeue(&que, print_error_message);
			break;
		}
	}
	clear(&que);
	return 0;
}
