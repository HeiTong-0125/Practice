#include <stdio.h>
int StarToKill(int number,int count,int array[]);
int main(void)
{	int number,count,lastalive,i;
	printf("Number:\n");
	scanf("%d",&number);
	printf("Count:\n");
	scanf("%d",&count);
	//����һ������,����ʼ��Ϊ1��1��������0��������
	int array[number];
	for (i=0;i<number;i++)
	{	array[i]=1;}
	
	lastalive=StarToKill(number,count,array);
	printf("Alive:%d",lastalive);
	return 0;
}

int StarToKill(int number,int count,int array[])	//ɱ�˳��� 
{	int cnt,i;
	int status=1;	//ѭ��״̬ 
	int sound=0;	//������������ 
	int lastalive;  //������ 
	int alive=number;
	while (status)
	{	for(cnt=0;cnt<number;cnt++)
		{	for (i=0;i<number;i++) //������������������λ������������� 
			{	if (array[i]==0)
				{	alive--;}
				else {lastalive=i+1;} 
			}
			if (array[cnt]==1)
			{	sound++;	 
				if (sound==count&&alive>1)	 
				{	array[cnt]=0;			
					printf("Kill:%d\n",cnt+1);
					sound=0;
				}
				else if(alive==1) //��������ֻʣһ��ʱ����ֹѭ�� 
				{	status=0;}
			}
			alive=number;	//���ã���ֹ���������ظ����� 
		} 
	}
	return lastalive;
 } 
