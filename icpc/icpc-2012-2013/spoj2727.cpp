#include <cstdio>
#include <vector>

#define MAX (2000000000)

int min (int a, int b)
{
	return a<b? a : b;
}

std::vector<int> god, mecha;

int main()
{
	int ng,nm,tt,tmp;
	int posgod, posmecha, mingod, minmecha;
	unsigned int i;
	
	scanf("%d",&tt);
	
	while (tt--)
	{
		mecha.clear();
		god.clear();
		
		scanf("%d%d",&ng,&nm);
		
		while (ng--)
		{
			scanf("%d",&tmp);
			god.push_back(tmp);
		}
		
		while (nm--)
		{
			scanf("%d",&tmp);
			mecha.push_back(tmp);
		}
		
		/*processa luta a luta*/
		while (god.size() > 0 && mecha.size() > 0)
		{
			mingod=minmecha=MAX;
			
			/*percorre god*/
			for (i = 0; i < god.size(); i++)
				if ( god[i] < mingod)
				{
					posgod=i;
					mingod=god[i];
				}
				
			/*percorre mecha*/
			for (i = 0; i < mecha.size(); i++)
				if ( mecha[i] < minmecha)
				{
					posmecha=i;
					minmecha=mecha[i];
				}
				
			if (minmecha <= mingod)
				mecha.erase(mecha.begin() + posmecha);
			else
				god.erase(god.begin() + posgod);
		}
		
		if (!god.size())
			puts("MechaGodzilla");
		else
			puts("Godzilla");
		
	}
	
	
	return 0;
}