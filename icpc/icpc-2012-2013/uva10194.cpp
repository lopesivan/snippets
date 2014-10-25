#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

char name1[50], name2[50];
int am, tam;

typedef struct
{
	char name[50];
	int points, games, wins, ties, losses, gd, gs, ga;
	
	
} standings;

inline int cmp (const void *a, const void *b)
{
	standings *t1 = (standings*)a;
	standings *t2 = (standings*)b;
	
	if (t1->points != t2->points)
		return (t2->points - t1->points);
	else
	{
		if (t1->wins != t2->wins)
			return (t2->wins - t1->wins);
		else
		{
			if (t1->gd != t2->gd)
				return (t2->gd - t1->gd);
			else
			{
				if (t1->gs != t2->gs)
					return (t2->gs - t1->gs);
				else
				{
					if (t1->games != t2->games)
						return (t1->games - t2->games);
					else
					{
						strcpy(name1, t1->name);
						strcpy(name2, t2->name);
						
						tam = strlen(name1);
						for (am = 0; am < tam; ++am)
							name1[am] = toupper(name1[am]);
						
						tam = strlen(name2);
						for (am = 0; am < tam; ++am)
							name2[am] = toupper(name2[am]);
						
						return (strcmp(name1, name2));
					}
				}
			}
		}
	}
		
}

int main()
{
	int n, t, i, j, partidas;
	char tournament[110];
	char time1[50], time2[50];
	int gols1, gols2;
	standings time[30];
	standings *pt1, *pt2, *winner, *loser, *p;
	
	scanf("%d%*c", &n);
	
	while (n--)
	{
		/*zera times*/
// 		for (i = 0; i <30; ++i)
// 		{
// 			p = &time[i];
// 			
// 			p-> points = p-> games = p->wins = p-> ties = p-> losses = p-> gd = p->gs = p->ga = 0;
// 		}
		memset(time, 0, sizeof time);
		
		gets(tournament);
		scanf("%d%*c", &t);
		
		for ( i = 0; i < t; ++i)
			scanf("%[^\n]\n", time[i].name );
		
		scanf("%d%*c", &partidas);
		
		for (i = 0; i < partidas; ++i)
		{
			scanf("%[^#]#%d@%d#%[^\n]\n", time1, &gols1, &gols2, time2);
			/*printf("%s %d %d %s\n", time1, gols1, gols2, time2);*/
			
			for (j = 0; j < t; ++j)
				if (!strcmp(time1, time[j].name))
				{
					pt1 = &time[j];
					break;
				}
				
			for (j = 0; j < t; ++j)
				if (!strcmp(time2, time[j].name))
				{
					pt2 = &time[j];
					break;
				}
 			/*printf("%s %s\n", pt1->name, pt2->name);*/

			pt1->games++;
			pt2->games++;
			pt1->gs += gols1;
			pt2->gs += gols2;
			pt1->ga += gols2;
			pt2->ga += gols1;
			pt1->gd += (gols1 - gols2);
			pt2->gd += (gols2 - gols1);
			
			if (gols1 != gols2)
			{
				if (gols1 > gols2)
				{
					winner = pt1;
					loser = pt2;
				}
				else
				{
					winner = pt2;
					loser = pt1;
				} 
				
				winner->wins++;
				loser->losses++;
				winner->points += 3;
			}
			else
			{
				pt1->points++;
				pt2->points++;
				pt1->ties++;
				pt2->ties++;
			}
		}
		
		/*ordenar*/
		qsort( time, t, sizeof time[0], cmp);
		
		/*imprimir*/
		puts(tournament);
		for (i = 0; i < t; ++i)
		{
			p = &time[i];
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, p->name, p->points, p->games, p->wins, p->ties, p->losses, p->gd, p->gs, p->ga);
		}
		
		if (n)
			puts("");
	}
	
	return 0;
}