/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:51:10 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/11 15:33:30 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int get_pointer_addr_len(unsigned long n, char *base)
{
    int baselen;
    int len;

    baselen = 0;
    while (base[baselen])
        baselen++;
    len = 0;
    while (n != 0)
    {
        n /= baselen;
        len++;
    }
    return (len);
}

int put_pointer_addr(void *p)
{
    char str[16];
    unsigned long nb;
    int base_len;
    int len;
    char *base;
    int i;

    base = "0123456789abcdef";
    base_len = 16;

    nb = (unsigned long)p;
    if (nb == 0)
    {
        write(1, &"(nil)", 5);
        return (5);
    }
    write(1, "0x", 2);
    i = 0;
    while (nb != 0) 
    {
        str[i] = base[nb % base_len];
        nb /= base_len;
        i++;
    }
    len = i;
    i--;
    while (i >= 0)
    {
        write(1, &str[i], 1);
        i--;
    }
    return(len + 2);
}

// #include <stdio.h>
// int main(void)
// {
//     void *p;

//     p = (void *)-8;
//     printf("printf: %d;", printf("%p\n", ""));
//     printf("put_pointer_addr: %d;", put_pointer_addr(""));
// }