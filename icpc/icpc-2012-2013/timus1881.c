#include <stdio.h>
#include <string.h>


int main()
{
	int h,w,n;
	int i,tam,lines=1,sheets, antibuf;
	char word[105];
	
	scanf("%d%d%d",&h,&w,&n);
	
	antibuf=w;
	
	for (i=0; i<n; i++)
	{
		scanf("%s%*c",word);
		tam=strlen(word);
		
		if (tam<=antibuf)
			antibuf-=(tam+1);
		
		else
			antibuf=w-(tam+1), lines++;
		
	}
	
	
	sheets = lines / h + (lines%h != 0? 1 : 0);
	printf("%d",sheets);
	
	return 0;
}