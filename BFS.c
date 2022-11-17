#include<stdlib.h>
#include<stdio.h>
#define MAX 100
#define FALSE 0
#define TRUE 1

typedef struct queue *queuePointer;
typedef struct queue
{
	int vertex;
	queuePointer link;
};
queuePointer front=NULL,rear=NULL;
int visited[MAX];
queuePointer first[MAX];

void addq(int v)
{
	queuePointer temp;
	temp=(queuePointer)malloc(sizeof(temp));
	temp->vertex=v;
	temp->link=NULL;
	if(front)
		rear->link=temp;
	else
		front=temp;
	rear=temp;
}
int deleteq()
{
	queuePointer temp1=front;
	int item;

	item=temp1->vertex;
	front=temp1->link;

	return item;
}
void bfs(int v)
{
	FILE *wptr;
	wptr=fopen("result.txt","w");

	queuePointer w;
	printf("%5d",v);
	fprintf(wptr,"%d  ",v);

	visited[v] = TRUE;
	addq(v); /* �[�J��Queue */
	while(front)
	{
		v = deleteq();  /* �qQueue�����X���� */
		for(w = first[v]; w ; w)
		{
			if(!visited[w->vertex])
			{
				printf("%5d", w->vertex);
				fprintf(wptr,"%d  ",w->vertex);

				addq(w->vertex);
				visited[w->vertex]=TRUE;

			}
			 w=w->link;
		}
	}  
	fclose(wptr);
}


void main ()
{
	FILE *ptr;
	queuePointer x;
	int count=0,i=0,j=0,number=0,op=0;


	for(i=0;i<MAX;i++)//��l��
	{
		first[i]=NULL;
		visited[i]=FALSE;
	}

	ptr=fopen("t1.txt","r");
	fscanf(ptr,"%d",&count);

	for(i=1;i<=count;i++)
	{
		for(j=1;j<=count;j++)
		{
			fscanf(ptr,"%d",&number);
			if(number==1)
			{
				x=(queuePointer)malloc(sizeof(x));
				x->link=NULL;
				x->vertex=j;
				x->link=first[i];
				first[i]=x;
			}
		}
	}

	printf("�п�J�_�I:");
	scanf("%d",&op);
	bfs(op);


	fclose(ptr);

}
