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
    while (i < x)
    {
        if (i < x - 1)
            ft_putchar(c2);
        if (i == x -1)
            ft_putchar(c1);
        i++;
    }
    ft_putchar('\n');
}

void    rush(int x, int y)
{
    int h;

    h = 0;
    if (x < 1 || y < 1)
        return ;
    while (h < y)
    {
        if (h == 0)
            line(x, 'A', 'B');
        if (h > 0 && h < y - 1)
            line(x, 'B', ' ');
        if (h == y - 1)
            line(x, 'C', 'B');
        h++;
    }
}

int    main(void)
{
    rush(1, 5);
    return (0);
}