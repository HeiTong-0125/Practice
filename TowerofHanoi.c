/*��⺺ŵ������ִ�в���*/
#include<stdio.h>
#define PillarA 'a'   //��������
#define PillarB 'b'
#define PillarC 'c'
void TowerOfHanoi(int, char, char, char, int*);
int GetNumber(void);
int main()
{
	int cnt=0;  //�����������㵱ǰ���貽��
	TowerOfHanoi(GetNumber(), PillarA, PillarB, PillarC, &cnt);
	printf("Total Step:%d", cnt);
	return 0;
}


int GetNumber()     //��ȡ��ȷ����������
{
	int n;
	char ch;
	printf("Please enter a number: ");
	while ((scanf_s("%d", &n)) != 1)
	{
		printf("Please enter the number!\n");
		while ((ch = getchar()) != '\n')   //���������ڸô����ַ���������ַ�
		{
			continue;
		}
	}
	return n;
}
//n�ǲ�����departure��ʼ������medium����Ϣ����destination��Ŀ����
void TowerOfHanoi(int n, char departure, char medium, char destination, int* cnt)
{
	if (n>3)
	{
		TowerOfHanoi(n - 1, departure, destination, medium,cnt);  //��(n-1)�㿴��һ�����壬�����Ƶ���Ϣ����
		printf("Steps[%d] %d:%c->%c\n", *cnt += 1, n, departure, destination);  //����n���Ƶ�Ŀ������
		TowerOfHanoi(n - 1, medium, departure, destination,cnt);  //��(n-1)�����Ϣ���Ƶ�Ŀ������
	}
	else   //��n=3ʱ���ƶ��ľ��岽��
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