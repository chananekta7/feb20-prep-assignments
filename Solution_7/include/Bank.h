/*
 * Bank.h
 *
 *  Created on: 23-Jan-2020
 *      Author: sandeepkulange
 */

#ifndef BANK_H_
#define BANK_H_

#include"../include/LinkedList.h"

typedef struct Bank
{
	LinkedList_t accounts;
}Bank_t;
void init_bank( Bank_t *const this );
void add_account_first( Bank_t *const this, Account_t *account );
void add_account_last( Bank_t *const this, Account_t *account );
void search_account_by_name( Bank_t *const this, const char *name );
void delete_account_by_name( Bank_t *const this, const char *name );
void search_account_by_id( Bank_t *const this, int id );
void delete_account_by_id( Bank_t *const this, int id );
void print_account_list_forward( Bank_t *const this );
void print_account_list_backward( Bank_t *const this );
void remove_all_accounts( Bank_t *const this );
#endif /* BANK_H_ */
