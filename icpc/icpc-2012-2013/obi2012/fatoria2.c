#include <stdio.h>

int main()
{
    int n,nfat=1,i;

    scanf("%d",&n);

    for (i=1; i<=n; i++)
        nfat*=i;

    if (!n)
        printf("%d",1);
    else
        printf("%d",nfat);

    return 0;
}
