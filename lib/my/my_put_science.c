/*
** EPITECH PROJECT, 2024
** PUT_SCIENCE
** File description:
** Science waits for his next revolution : ouais !
*/

#include "my.h"
#include "printf/my_printf.h"
#include <stdio.h>
#include <stdlib.h>

//#include <stdio.h>
//TODO: nan inf etc...
//TODO: sub 1 abs f's
//TODO: sub 1 ABS rounding
//TODO: 0
//printf("'%Lf %i'", f, precision);
//precision -= my_nbrlen(f, 10) - 1;
//printf("%i", my_nbrlen(f, 10));

static int my_put_exponent(int exponent, int is_caps)
{
    int sum = 0;

    sum += my_putchar(is_caps ? 'E' : 'e');
    sum += my_putchar(exponent >= 0 ? '+' : '-');
    if (ABS(exponent) < 10) {
        sum += my_putchar('0');
    }
    sum += my_putnbr(ABS(exponent));
    return sum;
}

static int my_put_pi(long long int aqua, int precision)
{
    int sum = 0;
    int size = 0;
    int power;

    aqua = ((long double)aqua) + (long double)my_pow(10,
    my_nbrlen(aqua, 10) - precision - 1);
    if (aqua == 0) {
        sum += my_putchar('0');
        sum += precision > 0 ? my_putchar('.') : 0;
    }
    for (; my_pow(10, size) <= aqua; size++);
    for (int i = 1; i <= size && i <= precision + 1; i++) {
        power = my_pow(10, size - i);
        sum += my_putchar('0' + (aqua / power) % 10);
        if (i == 1 && precision)
            sum += my_putchar('.');
        if (i > precision)
            break;
    }
    return sum;
}

static int get_exp(long double nb)
{
    long int ced = (long long int)nb;
    long double dec = nb - ced;
    int exponent = -1;

    if (nb == 0) {
        return 0;
    }
    for (int i = 0; !ced; i++) {
        dec *= 10;
        if (((long long int)dec % 10LL) != 0) {
            break;
        }
        dec -= (long long int)(dec);
        exponent--;
    }
    for (; ced; ced /= 10) {
        exponent++;
    }
    return exponent;
}

int my_put_science(long double f, int precision, int is_caps)
{
    int sum = 0;
    int exponent = get_exp(f);

    for (; (long long int)f == 0 && f != 0; f *= 10) {
    }
    if (f < 0) {
        sum += my_putchar('-');
        f *= -1;
    }
    sum += my_put_pi(ABS(f), precision);
    precision -= exponent > 0 ? exponent : 0;
    f = f - (long long int)f;
    if (precision > 0) {
        sum += my_put_round(f, precision);
    }
    sum += my_put_exponent(exponent, is_caps);
    return sum;
}
