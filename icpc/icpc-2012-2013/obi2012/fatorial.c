#include <stdio.h>

int main()
{
    int n,v=0,quociente,resto,resultado,mod4;

    while (scanf("%d",&n)==1)
    {
        v++;
        quociente=n/10;
        resto=n%10;
        mod4=quociente%4;

        switch(resto)
        {
            case 0:
                resto=1;
                break;
        	case 1:
        		resto=1;
        		break;
        	case 2:
        		resto=2;
        		break;
		case 3:
			resto=6;
			break;
		case 4:
			resto=4;
			break;
		case 5:
			resto=2;
			break;
		case 6:
			resto=2;
			break;
		case 7:
			resto=4;
			break;
		case 8:
			resto=2;
			break;
		case 9:
			resto=8;
			break;
	}

        switch(mod4)
        {
            case 0:
                mod4=6;
                break;
            case 1:
                mod4 = 8;
                break;
            case 2:
                mod4=4;
                break;
            case 3:
                mod4=2;
                break;
        }

        if (quociente)
        {
            resultado=(resto * mod4)%10;
        }
        else
            resultado=resto;

        printf("Instancia %d\n%d\n\n",v,resultado);

    }

    return 0;
}


