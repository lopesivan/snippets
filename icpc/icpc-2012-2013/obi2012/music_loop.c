#include <stdio.h>

int a,b,c;
int peak;

void check()
{
    if (b>a && c<b) 
	peak++;
    else if (b<a && c>b)
	peak++;
}

void shift()
{
    a=b;
    b=c;
}

int main()
{
    int n,i,inicial,inicial2;
    
    
    scanf("%d",&n);
    
    while (n!=0)
    {
	peak=0;
	scanf("%d%d",&inicial,&inicial2);
	a=inicial, b=inicial2;
	
		
	for (i=0; i<n-2; i++)
	{
	    scanf("%d",&c);
	    check();   
	    shift();
	    
	    
	}
	
	if (n==2)
	{
	    printf("2\n");
	}
	else
	{
	    c=inicial;
	    check();
	    shift();
	    c=inicial2;
	    check();
	    printf("%d\n",peak);
	}
		
	
	
	scanf("%d",&n);
    }
    
    
    
    return 0;
}