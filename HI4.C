#include<stdio.h>
#include<conio.h>
#define SIZE 10
typedef struct queuetype
{
 int front,rear;
 int a[SIZE];
}queue;
void main()
{
 int choice,value=0,item;
 int IsEmpty(queue *);
 int IsFull(queue *);
 void Enqueue(queue *,int);
 int Dequeue(queue *);
 queue q;
 q.front=-1;
 q.rear=-1;
 clrscr();
 while(1)
 {
  printf("Menu : \n");
  printf("1. IsEmpty \n 2. IsFull \n 3. Enqueue \n 4. Dequeue \n 5. Exit\n");
  printf("Enter you choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	 value=IsEmpty(&q);
	 if(value==1)
	 printf("Queue is empty");
	 else
	 printf("Queue is not empty");
	 break;
   case 2:
	value=IsFull(&q);
	if(value==1)
	printf("Queue is full");
	else
	printf("Queue is not full");
	break;
   case 3:
	value=IsFull(&q);
	if(value==0)
	{
	 printf("Enter the element in queue : ");
	 scanf("%d",&item);
	 Enqueue(&q,item);
	}
	else
	printf("Queue is full");
	break;
   case 4:
	 value=IsEmpty(&q);
	 if(value==0)
	 {
	  item=Dequeue(&q);
	  printf("Deleted element : %d",item);
	 }
	 else
	 printf("Queue is empty");
	 break;
   case  5:
	exit(0);
  }
  getch();
 }
}
int IsEmpty(queue *q)
{
 if(q->front==-1)
 return 1;
 else
 return 0;
}
int IsFull(queue *q)
{
 if(q->front==0 && q->rear==SIZE-1)
 return 1;
 else
 return 0;
}
void Enqueue(queue *q,int item)
{
 int i;
 if(q->rear==-1)
{ q->rear=0;
 q->front=0;}
 else if(q->front!=0&&q->rear==SIZE-1)
	{
	 for(i=q->front;i<SIZE;i++)
	 q->a[i-q->front]=q->a[q->front];
	 q->rear=q->rear-q->front+1;
	 q->front=0;
	}
 else
 q->rear++;
 q->a[q->rear]=item;
}
int Dequeue(queue *q)
{
 int item;
 item=q->a[q->front];
 q->front++;
 return item;
}