#include <stdio.h>

int main()
{
    int n;
    int i,j;
    char vec[10][10];
    char vec2[10][10];
    
    scanf("%d",&n);
    
    while(n)
    {
	//adquire as 2 matrizes
	for (i=0; i<n; i++)
	{
	    for (j=0; j<n; j++)
	    {
		scanf("%c",&vec[i][j]);
	    }
	    for (j=0; j<n; j++)
	    {
		scanf("%c",&vec2[i][j]);
	    }
	}
	
	
	
	scanf("%d",&n);
    }
    
    return 0;
}