/* Implement doubly linked list of bank accounts. Each account have information including
 * id, type, balance and account holder. The account holder details includes name, address
 * & contact details. Write an menu-driven program to implement add first, add last,
 * display all (forward), display all (backward), find by account id, find by account
 * holder name, delete all functionalities.*/
#include<stdio.h>
#include<stdlib.h>
#include"../include/Bank.h"

void accept_account_id( int *id )
{
	printf("Account id	:	");
	scanf("%d", id );
}
void accept_account_holder_name( char *name )
{
	printf("Account Holder Name	:	");
	scanf("%s", name );
}
void accept_accountholder( AccountHolder_t *const this )
{
	printf("Name		:	");
	scanf("%s", this->name);
	printf("Address		:	");
	scanf("%s", this->address);
	printf("Contact No.	:	");
	scanf("%s", this->contact);
}
void print_accountholder( AccountHolder_t *const this )
{
	printf("%-30s%-30s%-15s\n",this->name, this->address, this->contact);
}
void accept_account( Account_t *const this )
{
	printf("Account id		:	");
	scanf("%d", &this->id);
	printf("Account Type	:	");
	scanf("%s", this->type);
	printf("Account Balance	:	");
	scanf("%f", &this->balance);
	accept_accountholder(&this->accountHolder );
}
void print_account( Account_t *const this )
{
	printf("%-5d%-15s%-10.2f", this->id, this->type, this->balance );
	print_accountholder(&this->accountHolder);
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Add Account( First )\n");
	printf("2.Add Account( Last )\n");
	printf("3.Find Account( By Name )\n");
	printf("4.Find Account( By Id )\n");
	printf("5.Remove Account( By Name )\n");
	printf("6.Remove Account( By Id )\n");
	printf("7.Print Accounts( Forward )\n");
	printf("8.Print Accounts( Backward )\n");
	printf("Enter choice	:	");
	scanf("%d", &choice);
	return choice;
}
int main( void )
{
	int choice, id;
	char name[ 50 ];
	Bank_t bank;
	init_bank(&bank);
	while( ( choice = menu_list( ) ) != 0 )
	{
		Account_t *account = NULL;
		switch( choice )
		{
		case 1:
			account = ( Account_t* )malloc( sizeof( Account_t ) );
			accept_account(account);
			add_account_first(&bank, account);
			break;
		case 2:
			account = ( Account_t* )malloc( sizeof( Account_t ) );
			accept_account(account);
			add_account_last(&bank, account);
			break;
		case 3:
			accept_account_holder_name(name);
			search_account_by_name(&bank, name);
			break;
		case 4:
			accept_account_id(&id);
			search_account_by_id(&bank, id);
			break;
		case 5:
			accept_account_holder_name(name);
			delete_account_by_name(&bank, name);
			break;
		case 6:
			accept_account_id(&id);
			delete_account_by_id(&bank, id);
			break;
		case 7:
			print_account_list_forward(&bank);
			break;
		case 8:
			print_account_list_backward(&bank);
			break;
		}
	}
	remove_all_accounts(&bank);
	return 0;
}
