#include<string.h>

char	string[]="Hello,world";

main()
{
	int	count,i;
	int	to_par[2],to_chil[2];					//�������ӽ��̵Ĺܵ�
	char 	buf[256];
//����ִ��ϵͳ����pipe�ֱ�������to_par��to_chil�з����������ļ���������
	pipe(to_par);
	pipe(to_chil);

	if(fork()==0){
	//�ӽ����ڴ�ִ�У��ӽ��̴Ӹ����̼̳����ļ�������0��1��
		close(0);								//�ر��ϵı�׼����
		dup(to_chil[0]); 					    //���ܵ��Ķ����Ƶ���׼����
		close(1);								//�ر��ϵı�׼���
		dup(to_par[1]);						//���ܵ���д���Ƶ���׼���
		close(to_par[1]);						//�رղ���Ҫ�Ĺܵ�������
		close(to_chil[0]);		close(to_par[0]);		close(to_chil[1]);
		for(;;){
			if((count=read(0,buf,sizeof(buf)))==0)
				return 0;
			write(1,buf,count);
		}

	}

	//�������ڴ�ִ��
	close(1);									//�������ñ�׼���롢���
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
