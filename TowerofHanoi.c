/*求解汉诺塔具体执行步骤*/
#include<stdio.h>
#define PillarA 'a'   //三根柱子
#define PillarB 'b'
#define PillarC 'c'
void TowerOfHanoi(int, char, char, char, int*);
int GetNumber(void);
int main()
{
	int cnt=0;  //计数器，计算当前步骤步数
	TowerOfHanoi(GetNumber(), PillarA, PillarB, PillarC, &cnt);
	printf("Total Step:%d", cnt);
	return 0;
}


int GetNumber()     //获取正确的数字输入
{
	int n;
	char ch;
	printf("Please enter a number: ");
	while ((scanf_s("%d", &n)) != 1)
	{
		printf("Please enter the number!\n");
		while ((ch = getchar()) != '\n')   //丢弃本行内该错误字符后的所有字符
		{
			continue;
		}
	}
	return n;
}
//n是层数，departure是始发柱，medium是休息柱，destination是目标柱
void TowerOfHanoi(int n, char departure, char medium, char destination, int* cnt)
{
	if (n>3)
	{
		TowerOfHanoi(n - 1, departure, destination, medium,cnt);  //将(n-1)层看作一个整体，将它移到休息柱上
		printf("Steps[%d] %d:%c->%c\n", *cnt += 1, n, departure, destination);  //将第n层移到目标柱上
		TowerOfHanoi(n - 1, medium, departure, destination,cnt);  //将(n-1)层从休息柱移到目标柱上
	}
	else   //当n=3时，移动的具体步骤
	{
		printf("Steps[%d] 1:%c->%c\n", *cnt += 1, departure, destination);
		printf("Steps[%d] 2:%c->%c\n", *cnt += 1, departure, medium);
		printf("Steps[%d] 1:%c->%c\n", *cnt += 1, destination, medium);
		printf("Steps[%d] 3:%c->%c\n", *cnt += 1, departure, destination);
		printf("Steps[%d] 1:%c->%c\n", *cnt += 1, medium, departure);
		printf("Steps[%d] 2:%c->%c\n", *cnt += 1, medium, destination);
		printf("Steps[%d] 1:%c->%c\n", *cnt += 1, departure, destination);
	}
}