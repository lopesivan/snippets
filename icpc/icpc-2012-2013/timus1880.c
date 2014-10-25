#include <stdio.h>
#include <string.h>

#define MAX (4000+10)

int main()
{
	int i,j,i2,n,n2,tmp;
	int v[MAX],v2[MAX];
	
	memset(v,0,sizeof v);
	memset(v2,0,sizeof v2);
	
	scanf("%d",&n);
	
	for (i=0; i<n; i++)
	{
		scanf("%d",&v[i]);
	}
	
	scanf("%d",&n2);
	
	for (j=0,i2=0; j<n2; j++)
	{
		scanf("%d",&tmp);
		
		for (i=0; i<n && v[i]<=tmp; i++)
			if (v[i]==tmp)
				v2[i2++]=tmp;
	}
	
	scanf("%d",&n2);
	memset(v,0,sizeof v);
	
	for (j=0,i=0; j<n2; j++)
	{
		scanf("%d",&tmp);
		
		for (n=0; n<i2 && v[n]<=tmp ; n++)
			if (v2[n]==tmp)
				v[i++]=tmp;
	}
	
	printf("%d",i);
	
	
	return 0;
}