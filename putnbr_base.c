/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:27:23 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/10 11:56:22 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int get_int_len(long n, char *base)
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

int putnbr_base(long n, char *base)
{
    char *str;
    long long nb;
    int num_len;
    int base_len;
    int i;

    nb = n;
    if (nb == 0)
    {
        write(1, &"0", 1);
        return (1);
    }
    base_len = 0;
    if (nb < 0)
    {
        write(1, &"-", 1);
		// if (nb == )
        nb = -nb;
    }
    while (base[base_len])
        base_len++;
    num_len = get_int_len(nb, base);
    str = ft_calloc(num_len, sizeof(char));
    i = 0;
    while (nb != 0) 
    {
        str[i] = base[nb % base_len];
        nb /= base_len;
        i++;
    }
    i--;
    while (i >= 0)
    {
        write(1, &str[i], 1);
        i--;
    }
    free(str);
    return(num_len + (n < 0));
}

// struct		s_meta_data
// {
// 	int		*len;
// 	long	*num;
// 	char	*base;
// }			t_meta_data;

// void init_meta_data(struct s_meta_data *md, long n, char *base)
// {
	
// }

// int    putnbr_base(long n, char *base)
// {
// 	static struct s_meta_data    md;
// 	char temp;

// 	if (!(md.len))
// 	{
// 		md.len = malloc(sizeof(int));
// 		*(md.len) = get_int_len(n, base);
// 	}
// 	if (!(md.num))
// 		md.num = &n;
// 	temp = (*(md.num) % 10) + '0';
// 	*(md.num) = (*(md.num) / 10);
	
// 	if (*(md.num) == 0)
// 	{
// 		write(1, &temp, 1);
// 		return *(md.len);
// 	}
// 	putnbr_base(n, base);
// 	write(1, &temp, 1);
// 	return 0;
// }

// #include <limits.h>
// int	main(void)
// {
// 	char *base = "0123456789";
// 	long test = LONG_MIN;
// 	// printf("%d", get_int_len(test, base));
// 	// putnbr_base(test, base);
// 	printf("%li", test);
// }