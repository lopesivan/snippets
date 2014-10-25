//complexidade muito alta: não passa. ~10^12

#include <cstdio>
#include <vector>

int max (int a, int b)
{
	return a>b? a : b;
}

std::vector<int> god, mecha;

int main()
{
	int ng,nm,tt,tmp;
	int maxgod, maxmecha;
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
		
		maxgod=maxmecha=-1;
		
		for (i = 0; i < god.size(); i++)
			if ( god[i] > maxgod)
				maxgod=god[i];

		for (i = 0; i < mecha.size(); i++)
			if ( mecha[i] > maxmecha)
				maxmecha=mecha[i];
			
		if (maxgod < maxmecha)
			puts("MechaGodzilla");
		else
			puts("Godzilla");
		
	}
	
	
	return 0;
}