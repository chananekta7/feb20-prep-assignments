/* Problem Statement : Input a string from user on command line. String may have multiple
commas e.g. "Welcome,to,Sunbeam,CDAC,Diploma,Course". Print each word individually.
Hint: use strtok() function. */

#include<stdio.h>
#include<string.h>
int main( int argc, char *argv[] )
{
	char *str = argv[ 1 ];
	const char *sep = ",-";
	str =  strtok(str, sep);
	while( str != NULL )
	{
		printf("%s\n", str);
		str =  strtok(NULL, sep);
	}
	return 0;
}
