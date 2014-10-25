#include <stdio.h>

int h, m, flag;
int _h, _m;

void pal()
{
	/* 12:25 */
	
	if (h >= 10)
		_m = (h%10)*10 + h/10;
	else
		_m = h;
	
	if (h == 0 && m < 10)
		_h = m;
	else
		_h = (m%10)*10 + m/10;
	
	
	if (h == _h && m == _m)
		flag = 1;
}

int main()
{
	int t;
	
	scanf("%d", &t);
	
	while (t--)
	{
		flag = 0;
		
		scanf("%d:%d", &h, &m);
		
		do
		{
			++m;
			if (m == 60)
			{
				m = 0;
				h = (h+1)%24;
			}
			
			pal();
			
		} while (flag == 0);
		
		printf("%02d:%02d\n", h, m);
	}
	
	return 0;
}