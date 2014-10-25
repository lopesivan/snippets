/* LA 3135 */

#include <cstdio>
#include <utility>
#include <map>
#include <queue>

using namespace std;

int main()
{
	map <int, int> dict;
	priority_queue < pair<int, int> > fila;
	pair <int, int> tmp;
	int a, b, count;
	
	while ( scanf("Register %d%d%*c", &a, &b) == 2 )
	{
		dict[a] = b;
		fila.push( make_pair(-b,-a) ); /*pair<int, int> (-b, -a)*/
	}
	
	scanf("%*[^\n]%d", &count);
	
	while (count--)
	{
		tmp = fila.top();
		fila.pop();
		printf("%d\n", -tmp.second);
		tmp.first -= dict[-tmp.second];
		fila.push(tmp);
	}
	
	return 0;
}