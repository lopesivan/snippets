#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (10000+100)
/*Inicio em LEFT*/

struct carro
{
	int time;
	char align[8];
	
} car[MAX];

int left_top, left_bottom, right_top, right_bottom;
int left_queue[MAX], right_queue[MAX];
int n,t,m;

void reset()
{
	left_top=left_bottom=right_top=right_bottom=0;
	
}

void push_left(int a)
{
	left_queue[left_top++]=a;
}

void push_right(int a)
{
	right_queue[right_top++]=a;
}

int pop_left()
{
	return left_top==left_bottom ? (-1) : (left_queue[left_bottom++]);
}

int pop_right()
{
	return right_top==right_bottom ? (-1) : (right_queue[right_bottom++]);
}

void process()
{
	int i,time=0,capacity;
	
	/*empilhamento*/
	for (i=0; i<m; i++)
	{
		if (!strcmp(car[k].align, "left"))
			push_left(car[k].time);
		else
			push_right(car[k].time);
	}
	
	{
		capacity=0;
		
		if (capacity)
			
	}
}

int main()
{
	int c;
	int k,j;
	
	
	scanf("%d",&c);
	
	for (j=0; j<c; j++)
	{
		reset();
		scanf("%d%d%d",&n,&t,&m);
		
		for (k=0; k<m; k++)
		{
			scanf("%d%*c",&car[k].time);
			scanf("%s%*c",car[k].align);
			
		}
		
		for (k=0; k<m; k++)
		{
			printf("%d %s\n",car[k].time,car[k].align);
		}
		
		process();
		
	}
		
	
	return 0;
}