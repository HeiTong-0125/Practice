/*Լɪ�������Ǹ����������⣺
N����Χ��һȦ���ӵ�һ����ʼ��������M������ɱ����
���ʣ��һ���������˶�����ɱ����
���� N=6��M=5����ɱ����˳���ǣ�5��4��6��2��3��1��*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node 	//���������� 
{	int value;
	struct node *next;
}Node; 
Node* CreatLinklist(int number);
void StarToKill(Node*head,int number,int count);
int main()
{	int number=0;
	int count=0;
	printf("Number:\n");
	scanf("%d",&number);
	printf("Count:\n");
	scanf("%d",&count);
	Node *head=CreatLinklist(number);
	StarToKill(head,number,count);
	return 0;
}

Node* CreatLinklist(int number)
{	//����һ������
	Node *head=NULL;
	Node *last=NULL;
	int i;
	for (i=1;i<=number;i++)
	{	//����һ���µĽڵ� 
		Node *p=malloc(sizeof(Node));
		p->value=i;
		p->next=NULL;
		//Ѱ�����һ���ڵ�,�����½ڵ����� 
		last=head;
		if (last)
		{	while(last->next)
			{	last=last->next;} 
			last->next=p;
		}
		else{head=p;} 
	}
	//���ӵ�һ���������һ����㣬����ѭ������ 
	last=last->next;
	last->next=head; 
	return head;
 }
 
void StarToKill(Node*head,int number,int count)  //ɱ�� 
{	Node *q=NULL;
	Node *p=head;
	int i;
	int cnt =0;
	for (i=1;p->next&&cnt<number-1;i++)		 //ѭ������ÿcount����㣬ɾ��һ����� 
	{	if (i==count)							//�����ý���ǰһ���ͺ�һ������ 
		{	printf("Kill:%d\n",p->value);
			q->next=p->next;
			free(p);
			p=q->next;
			i=0;
			cnt++;
		}
		else
		{	q=p;
			p=p->next;
		}
	}
	printf("Alive:%d\n",p->value);
} 
