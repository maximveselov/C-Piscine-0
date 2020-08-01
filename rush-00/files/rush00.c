#include <stdio.h>
#include <unistd.h>

void puttfirst(int q)
{
    int scounter;
    int i;

    scounter = 0;
    i = q - 1;
    while (scounter <= i)
    {
        if (scounter == 0 || scounter == i)
        {
            ft_putchar('o');
        }
        else
        {
            ft_putchar('-');
        }
        scounter++;
    }
    ft_putchar('\n');
}

void puttsecond(int w)
{
    int scounter;
    int j;

    scounter = 0;
    j = w - 1;
    while (scounter <= j)
    {
        if (scounter == 0 || scounter == j)
        {
            ft_putchar('|');
        }
        else
        {
            ft_putchar(' ');
        }
        scounter++;
    }
    ft_putchar('\n');
}

void	rush(int x, int y)
{
	int lcount;
	int scount;
    int a;

	a = y - 1;

	lcount = 0;
	while (lcount <= a)
	{
		scount = 0;
		if (lcount == 0 || lcount == a)
		{
			puttfirst(x);
		}
		else
		{
			puttsecond(x);
		}
		lcount++;
	}
}