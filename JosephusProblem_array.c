#include <stdio.h>
int StarToKill(int number,int count,int array[]);
int main(void)
{	int number,count,lastalive,i;
	printf("Number:\n");
	scanf("%d",&number);
	printf("Count:\n");
	scanf("%d",&count);
	//创建一个数组,并初始化为1（1代表生，0代表死）
	int array[number];
	for (i=0;i<number;i++)
	{	array[i]=1;}
	
	lastalive=StarToKill(number,count,array);
	printf("Alive:%d",lastalive);
	return 0;
}

int StarToKill(int number,int count,int array[])	//杀人程序 
{	int cnt,i;
	int status=1;	//循环状态 
	int sound=0;	//报过数的人数 
	int lastalive;  //生还者 
	int alive=number;
	while (status)
	{	for(cnt=0;cnt<number;cnt++)
		{	for (i=0;i<number;i++) //计算生还人数，并定位编号最大的生还者 
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
				else if(alive==1) //当生还者只剩一人时，终止循环 
				{	status=0;}
			}
			alive=number;	//重置，防止生还人数重复计数 
		} 
	}
	return lastalive;
 } 
