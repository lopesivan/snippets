#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

std::multiset<int> v;
std::multiset<int>::iterator it;

int mediana()
{
	std::set<int>::iterator m=v.begin();
	unsigned int i,stop;
	
	stop = (v.size()-1)/2;
	
	for (i=0; i<stop; i++)
		m++;
	
	return *m;
}

int main()
{
	int i;
	int t,a,b,c,n,next,sum;
	
	scanf("%d",&t);
	
	while (t--)
	{
		sum = 0;
		v.clear();
		v.insert(1);
		
		scanf("%d%d%d%d",&a,&b,&c,&n);
		
		//printf("%d %d %d %d %d",a,b,c,n,t);
		
		for (i=2; i<=n; i++)
		{
			next = (a*mediana() + b*i + c) % 1000000007;
			//printf("%d\n",next);
			v.insert(next);
		}
		
		for (it=v.begin(); it!=v.end(); it++)
			sum+=*it;
		
		printf("%d\n", sum);
	}
	return 0;
}