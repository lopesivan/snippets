#include <stdio.h>
#include <string.h>
#define MAX 110

char str1[27]="abcdefghijklmnopqrstuvwxyz"; /*string normal*/
char str2[27]="yhesocvxduiglbkrztnwjpfmaq"; /*string em googlerese*/
char s[MAX+1];

void mapping ()
{
	int i;
	int tam=strlen(s);
	
	for (i=0; i<tam; i++)
	{
		if (s[i]!=' ')
			s[i]=str2[(int)s[i]-'a'];
	}
	
}

int main()
{
	int n,i,v=0;
	
	scanf("%d%*c",&n);
	
	for (i=0; i<n; i++)
	{
		if (v)
			printf("\n");
		
		fgets(s,102,stdin);
		s[strlen(s)]='\0';
		mapping();
		printf("Case #%d: %s",++v,s);
		
	}
	
	return 0;
}