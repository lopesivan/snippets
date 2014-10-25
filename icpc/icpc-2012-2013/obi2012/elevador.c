#include <stdio.h>

int main()
{
    int n,c;
    int i;
    int atual=0;
    int ent,sai;
    
    scanf("%d%d",&n,&c);
    
    for (i=0; i<n; i++)
    {
	scanf("%d%d",&sai,&ent);
	
	atual+=(ent-sai);
		
	if (atual>c)
	{
	    printf("S");
	    return 0;
	}
	
    }
    
    printf("N");
    
    return 0;   
    
}