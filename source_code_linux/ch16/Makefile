#

all:	mqcreate mqsend mqrecv mqdel mqconf mqrdset mqstats

mqcreate:	mqcreate.c
	gcc -Wall -o mqcreate mqcreate.c

mqsend:		mqsend.c
	gcc -Wall -o mqsend mqsend.c

mqrecv:		mqrecv.c
	gcc -Wall -o mqrecv mqrecv.c

mqdel:		mqdel.c
	gcc -Wall -o mqdel mqdel.c

mqconf:		mqconf.c
	gcc -Wall -o mqconf mqconf.c

mqrdset:	mqrdset.c
	gcc -Wall -o mqrdset mqrdset.c

mqstats:	mqstats.c
	gcc -Wall -o mqstats mqstats.c

clean:
	rm -rf mqcreate mqsend mqrecv mqdel mqconf mqrdset mqstats

