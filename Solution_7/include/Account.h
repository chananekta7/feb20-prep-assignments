/*
 * Account.h
 *
 *  Created on: 23-Jan-2020
 *      Author: sandeepkulange
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

typedef struct AccountHolder
{
	char name[ 30 ];
	char address[ 100 ];
	char contact[ 15 ];
}AccountHolder_t;
void accept_accountholder( AccountHolder_t *const this );
void print_accountholder( AccountHolder_t *const this );


typedef struct Account
{
	int id;
	char type[ 30 ];
	float balance;
	AccountHolder_t accountHolder;
}Account_t;
void accept_account( Account_t *const this );
void print_account( Account_t *const this );

#endif /* ACCOUNT_H_ */
