#include <cstdio>
#include <set>

std::set<int> friendlist,myfriends;
std::set<int>::iterator it;

int main()
{
	int n,tmp,num;
	
	scanf("%d",&n);
	
	while (n--)
	{
		scanf("%d",&tmp);
		myfriends.insert(tmp);
		
		scanf("%d",&num);
		
		while (num--)
		{
			scanf("%d",&tmp);
			friendlist.insert(tmp);
		}
	}
	
	for (it=myfriends.begin(); it!=myfriends.end(); it++)
	{
		friendlist.erase(*it);
	}
	
	printf("%d",friendlist.size());
	
	return 0;
}