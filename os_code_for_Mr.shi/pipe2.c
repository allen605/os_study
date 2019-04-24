#include<string.h>

char	string[]="Hello,world";

main()
{
	int	count,i;
	int	to_par[2],to_chil[2];					//到父、子进程的管道
	char 	buf[256];
//两次执行系统调用pipe分别在数组to_par和to_chil中分配了两个文件描述符。
	pipe(to_par);
	pipe(to_chil);

	if(fork()==0){
	//子进程在此执行，子进程从父进程继承了文件描述符0和1。
		close(0);								//关闭老的标准输入
		dup(to_chil[0]); 					    //将管道的读复制到标准输入
		close(1);								//关闭老的标准输出
		dup(to_par[1]);						//将管道的写复制到标准输出
		close(to_par[1]);						//关闭不必要的管道描述符
		close(to_chil[0]);		close(to_par[0]);		close(to_chil[1]);
		for(;;){
			if((count=read(0,buf,sizeof(buf)))==0)
				return 0;
			write(1,buf,count);
		}

	}

	//父进程在此执行
	close(1);									//重新设置标准输入、输出
	dup(to_chil[1]);
	close(0);
	dup(to_par[0]);
	close(to_chil[1]); 			close(to_par[0]);
	close(to_chil[0]); 			close(to_par[1]);
	for(i=0;i<15;i++){
		write(1,string,strlen(string));
		read(0,buf,sizeof(buf));
	}
}
