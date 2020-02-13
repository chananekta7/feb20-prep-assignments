#include<stdio.h>
#include"../include/Bank.h"
void init_bank( Bank_t *const this )
{
	init_linkedlist( &this->accounts );
}
void add_account_first( Bank_t *const this, Account_t *account )
{
	add_first(&this->accounts, account);
	printf("Account is inserted successfully.\n");
}
void add_account_last( Bank_t *const this, Account_t *account )
{
	add_last(&this->accounts, account);
	printf("Account is inserted successfully.\n");
}
void search_account_by_name( Bank_t *const this, const char *name )
{
	Account_t *account = find_account_by_name(&this->accounts, name);
	if( account != NULL )
		print_account(account);
	else
		printf("Account not found.\n");
}
void delete_account_by_name( Bank_t *const this, const char *name )
{
	if ( remove_account_by_name(&this->accounts, name) )
		printf("Account is removed successfully.\n");
	else
		printf("Account not found\n");
}
void search_account_by_id( Bank_t *const this, int id )
{
	Account_t *account = find_account_by_id(&this->accounts, id);
	if( account != NULL )
		print_account(account);
	else
		printf("Account not found.\n");
}
void delete_account_by_id( Bank_t *const this, int id )
{
	if( remove_account_by_id(&this->accounts, id) )
		printf("Account is removed successfully.\n");
	else
		printf("Account not found\n");
}
void print_account_list_forward( Bank_t *const this )
{
	print_forward(&this->accounts);
}
void print_account_list_backward( Bank_t *const this )
{
	print_backward(&this->accounts);
}
void remove_all_accounts( Bank_t *const this )
{
	clear(this->accounts);
}
