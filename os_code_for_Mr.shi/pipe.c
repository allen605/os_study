#include<fcntl.h>
#include <stdio.h>


int  fdrd,fdwt;
char 	c;

rdwrt( )
{
	for( ; ; ){
		if(read(fdrd,&c,1)!=1)	return;
		sleep(1);
		write(fdwt,&c,1);
	}
}
main(int argc,char *argv[])
{
	if(argc!=3){
		//exit(1);
		return 0;
	}
	if((fdrd=open(argv[1],O_RDONLY))==-1)
	{
		//exit(1);
		return 0;
	}
	if((fdwt=creat(argv[2],0666))==-1)
	{
		//exit(1);
		return 0;
	}

	fork( );	
	rdwrt( ); 				//两个进程执行同样的代码
	//exit(0);
	return 0;
}
