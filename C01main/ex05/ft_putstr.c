#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str != '\0')
    {
        write(1, str, 1);
        str = str + 1;
    }
}

int    main(void)
{
    char    *str;

    str = "Lollero";
    ft_putstr(str);
    return (1);
}
