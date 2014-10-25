#include <stdio.h>

int main()
{
	int input,sum1,sum2,sum3;
	
	scanf("%d",&input);
	
	sum1=input/100000 + (input/10000)%10 + (input/1000)%10;
	input++;
	sum2=(input/100)%10 + (input/10)%10 + input%10;
	input-=2;
	sum3=(input/100)%10 + (input/10)%10 + input%10;
	
	if (sum1 == sum2 || sum1==sum3)
		puts("Yes");
	else
		puts("No");
	
	
	return 0;
}