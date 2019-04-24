%{
#include <stdio.h>
#include "grammar.tab.h"
%}

NUM	[0-9]
VAR	[a-zA-Z]
WS	[ \t]

%%
set		return SET;
{NUM}+		return NUMBER;
{VAR}+		return VARIABLE;
-		return OP_MINUS;
\+		return OP_PLUS;
=		return ASSIGN;
;		return END;
\n		/* Ignore whitespace */
{WS}+		/* Ignore whitespace */
%%
