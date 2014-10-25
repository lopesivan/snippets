#include <stdio.h>
#include <string.h>

#define MAX (30000)

int main()
{
	int i,j,p=0,tam;
	char s[MAX], t[MAX];
	
	while (gets(s))
	{
		tam = strlen(s);
		
		for (i=0, j=0; i < tam; ++i)
		{
			if (s[i] == '"')
			{
				if (p==0)
				{
					t[j++]='`';
					t[j++]='`';
					p=1;
				}
				else
				{
					t[j++]='\'';
					t[j++]='\'';
					p=0;
				} 
			}
			else
				t[j++]=s[i];
		}
		t[j]='\0';
		
		puts(t);
	}
	
	return 0;
}