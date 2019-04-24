%{
#include <stdio.h>
#include <string.h>

void yyerror( const char *str )
{
	fprintf( stderr, "error: %s\n", str );
}

int main()
{
	FILE *infp;

	infp = fopen("config.file", "r");

	yyrestart( infp );

	yyparse();

	fclose( infp );

	return 0;
}



char address[10][80];
int  addrCount = 0;

%}

%token ALLOW OPEN_BRACE CLOSE_BRACE DISALLOW WORD ATSYM PERIODSYM

%%

configs: 
	| configs config
	;

config:
	allowed 
	|
	disallowed 
	;

allowed: ALLOW OPEN_BRACE targets CLOSE_BRACE
	{
		int i;
		printf("Allow these addresses:\n");
		for (i = 0 ; i < addrCount ; i++) {
			printf( "\t%s\n", address[i] );
		}
		addrCount = 0;
	}
	;

disallowed: DISALLOW OPEN_BRACE targets CLOSE_BRACE
	{
		int i;
		printf("Disallow these addresses:\n");
		for (i = 0 ; i < addrCount ; i++) {
			printf( "\t%s\n", address[i] );
		}
		addrCount = 0;
	}
	;


targets: 
	|
	targets email_address
	;

email_address:
	WORD ATSYM WORD PERIODSYM WORD
	{
		if (addrCount < 10) {
		  sprintf(address[addrCount++], "%s@%s.%s", $1, $3, $5);
                  free($1);  free($3);  free($5);
		}
	}
	;

