
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_putchar(char c)
{
    int i = 0;

    i += write(1, &c, 1);
    return (i);
}

// Si la chaine n´existe pas, écrire (null)

int ft_putstr(char *str)
{
    int i = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return(i);
}

// passage par un long pour le que le int min s´affiche

int ft_putnbr(int nbr)
{
    long nb = nbr;
    char strnb[10] = "0123456789";;
    int count = 0;

    if (nb < 0)
    {
        nb *= -1;
        count += ft_putchar('-');
    }

    if (nb >= 10)
        ft_putnbr(nb / 10);
    count += ft_putchar(strnb[nb % 10]);
    return (count);
}

int ft_putexa(unsigned int nb)
{
    char strnb[16] = "0123456789abcdef";
    int count;
    int sign;

    count = 0;
    if (nb >= 16)
        ft_putexa(nb / 16);
    count += ft_putchar(strnb[nb % 16]);
    return (count);
}

int ft_convert(va_list args, const char str)
{
    int count = 0;

    if (str == 's')
        count += ft_putstr(va_arg(args, char *));
    if (str == 'd')
        count += ft_putnbr(va_arg(args, int));
    if (str == 'x')
        count += ft_putexa(va_arg(args, unsigned int));
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int i = 0;
    int count = 0;    

    va_start(args, str);
    while(str[i])
    {
        if (str[i] == '%')
            count += ft_convert(args, str[++i]);
        else 
            count += ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return(count);
}

#include <limits.h>
#include <stdio.h>

int main()
{
    ft_printf("%s, %s, %s\n", "hello", "", NULL);
    printf("%s, %s, %s\n\n", "hello", "", NULL);

    ft_printf("%d, %d, %d, %d, %d\n", 42, NULL, -42, INT_MIN, INT_MAX);
    printf("%d, %d, %d, %d, %d\n\n", 42, NULL, -42, INT_MIN, INT_MAX);

    ft_printf("%x, %x, %x, %x, %x\n", 42, NULL, -42, INT_MIN, INT_MAX);
    printf("%x, %x, %x, %x, %x\n", 42, NULL, -42, INT_MIN, INT_MAX);
}
