#include <unistd.h>

void ft_print_comb(void)
{
    int a;
    int b;
    int c;
    char charA;
    char charB;
    char charC;

    a = 0;
    while(a <= 7)
    {
        b = a + 1;
        while(b <= 8)
        {
            c = b + 1;
            while (c <= 9)
            {
                charA = a + '0';
                charB = b + '0';
                charC = c + '0';
                write(1, &charA, 1);
                write(1, &charB, 1);
                write(1, &charC, 1);
                if (a == 7 && b == 8 && c == 9)
                {
                    return;
                }
                write(1, ",", 1);
                write(1, " ", 1);
                c++;
            }
            b++;
        }
        a++;
    }
}

int main(void)
{
    ft_print_comb();
}