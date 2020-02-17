/*约瑟夫问题是个有名的问题：
N个人围成一圈，从第一个开始报数，第M个将被杀掉，
最后剩下一个，其余人都将被杀掉。
例如 N=6，M=5，被杀掉的顺序是：5，4，6，2，3，1。*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node 	//定义结点类型 
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
{	//创建一个链表
	Node *head=NULL;
	Node *last=NULL;
	int i;
	for (i=1;i<=number;i++)
	{	//创建一个新的节点 
		Node *p=malloc(sizeof(Node));
		p->value=i;
		p->next=NULL;
		//寻找最后一个节点,并与新节点连接 
		last=head;
		if (last)
		{	while(last->next)
			{	last=last->next;} 
			last->next=p;
		}
		else{head=p;} 
	}
	//连接第一个结点和最后一个结点，创建循环链表 
	last=last->next;
	last->next=head; 
	return head;
 }
 
void StarToKill(Node*head,int number,int count)  //杀人 
{	Node *q=NULL;
	Node *p=head;
	int i;
	int cnt =0;
	for (i=1;p->next&&cnt<number-1;i++)		 //循环链表，每count个结点，删除一个结点 
	{	if (i==count)							//并将该结点的前一个和后一个连接 
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
