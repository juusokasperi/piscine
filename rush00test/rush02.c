#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    line(int x, char c1, char c2)
{
    int i;

    ft_putchar(c1);
    i = 1;
    while(i < x - 1)
    {
        ft_putchar(c2);
        i++;
    }
    while(i == x - 1)
    {
        ft_putchar(c1);
        ft_putchar('\n');
        i++;
    }
}

void    rush(int x, int y)
{
    int h;

    h = 0;
    if (x < 1 || y < 1)
    {
        return ;
    }
    while (h == 0)
    {
        line(x, 'A', 'B');
        h++;
    }
    while (h > 0 && h < y - 1)
    {
        line(x, 'B', ' ');
        h++;
    }
    while (h == y - 1)
    {
        line(x, 'C', 'B');
        h++;
    }
}

int    main(void)
{
    rush(0, 0);
    return (0);
}