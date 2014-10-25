#include <stdio.h>

int main()
{
	int x, y, _x, _y;
	int moves;
	
	while ( scanf("%d%d%d%d", &x, &y, &_x, &_y) == 4)
	{
		if (  ! ( x || y || _x || _y) )
			break;
		
		if (x == _x && y == _y)
			moves = 0;
		else if ( x == _x || y == _y || x - y == _x - _y || x + y == _x + +_y)
			moves = 1;
		else
			moves = 2;
		
		printf("%d\n", moves);
	}
	
	return 0;
}