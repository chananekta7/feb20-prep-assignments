/* Input employee information from the user including his employee id, name, address,
 *  salary, birth date and date of joining. Find the age of person when he joined company
 *  (in years) and his experience till date (in months). Also print the date when his
 *  probation period is over, assuming that probation period is of 90 days from date of
 *  joining. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PROBATION_PERIOD 90
typedef struct Date
{
	int day, month, year;
}Date_t;
int arr[2][12]={
						{ 31,28,31,30,31,30,31,31,30,31,30,31},
						{ 31,29,31,30,31,30,31,31,30,31,30,31}
			   };
int leap_year( int year )
{
	if( ( year % 4 == 0 && year % 100 != 0 ) ||  year % 400 == 0 )
		return 1;
	return 0;
}
int get_days( Date_t firstDate, Date_t secondDate )
{
	int days = 0;
	if( !leap_year(firstDate.year))
	{
		days = arr[ 0 ][ firstDate.month - 1 ] - firstDate.day;
		for( int month = firstDate.month; month < 12;  ++ month )
			days += arr[ 0 ][ month ];
	}
	else
	{
		days = arr[ 1 ][ firstDate.month - 1 ] - firstDate.day;
		for( int month = firstDate.month; month < 12;  ++ month )
			days += arr[ 1 ][ month ];
	}
	for( int year = firstDate.year + 1; year < secondDate.year ; ++ year )
	{
		if( leap_year(year))
			days += 366;
		else
			days += 365;
	}
	if( !leap_year( ( secondDate.year ) ) )
	{
		for( int month = 1; month < secondDate.month;  ++ month )
			days += arr[ 0 ][ month - 1 ];
	}
	else
	{
		for( int month = 1; month <  secondDate.month;  ++ month )
			days += arr[ 1 ][ month - 1 ];
	}
	days += secondDate.day;
	return days;
}
Date_t add_days( Date_t joinDate , int days )
{
	Date_t pbDate = joinDate;
	if( !leap_year( pbDate.year))
	{
		while( days > arr[ 0 ][ pbDate.month - 1 ] )
		{
			days = days - ( arr[ 0 ][ pbDate.month - 1 ] - pbDate.day );
			pbDate.day = 0;
			if( pbDate.month == 12 )
			{
				++ pbDate.year;
				pbDate.month = 1;
			}
			else
				++ pbDate.month;
		}
		pbDate.day = days + 1;
	}
	else
	{
		while( days > arr[ 1 ][ pbDate.month - 1 ] )
		{
			days = days - ( arr[ 1 ][ pbDate.month - 1 ] - pbDate.day ) ;
			pbDate.day = 0;
			if( pbDate.month == 12 )
			{
				++ pbDate.year;
				pbDate.month = 1;
			}
			else
				++ pbDate.month;
		}
		pbDate.day = days + 1;
	}
	return pbDate;
}
typedef struct Employee
{
	char name[ 50 ];
	int id;
	char address[ 100 ];
	float salary;
	Date_t birthDate;
	Date_t joinDate;
	Date_t probPeriodDate;
}Employee_t;
void accept_record( Employee_t *ptr )
{
	printf("Name		:	");
	scanf("%s",ptr->name);
	printf("Emp id		:	");
	scanf("%d",&ptr->id);
	printf("Salary		:	");
	scanf("%f",&ptr->salary);
	printf("BirthDate	:	");
	scanf("%d/%d/%d",&ptr->birthDate.day, &ptr->birthDate.month, &ptr->birthDate.year);
	printf("JoinDate	:	");
	scanf("%d/%d/%d",&ptr->joinDate.day, &ptr->joinDate.month, &ptr->joinDate.year);
}
void print_record( Employee_t *ptr )
{
	printf("Name			:	%s\n", ptr->name);
	printf("Emp id			:	%d\n", ptr->id);
	printf("Salary			:	%f\n", ptr->salary);
	printf("BirthDate		:	%d/%d/%d\n", ptr->birthDate.day, ptr->birthDate.month, ptr->birthDate.year);
	printf("JoinDate		:	%d/%d/%d\n", ptr->joinDate.day, ptr->joinDate.month, ptr->joinDate.year);
	printf("Join Time Age		:	%d(Yrs)\n", get_days( ptr->birthDate,  ptr->joinDate ) / 365);
	Date_t pbDate = add_days(ptr->joinDate, PROBATION_PERIOD );
	printf("Probation Over Date	:	%d/%d/%d\n", pbDate.day, pbDate.month, pbDate.year);
	time_t t = time( NULL ); struct tm *dt = localtime( &t );
	Date_t currentDate = { dt->tm_mday, dt->tm_mon + 1, dt->tm_year + 1900 };
	printf("Work Exp.		:	%d(Months)\n", get_days( ptr->joinDate, currentDate) / 30 );
}
int main( void )
{
	Employee_t emp;
	accept_record(&emp);
	print_record(&emp);
	return 0;
}
