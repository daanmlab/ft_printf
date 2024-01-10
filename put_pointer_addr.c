/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:51:10 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/11 16:44:04 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	get_pointer_addr_len(unsigned long n, char *base)
{
	int	baselen;
	int	len;

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

struct				s_temp
{
	char			str[16];
	unsigned long	nb;
	int				base_len;
	int				len;
	char			*base;
	int				i;
}					t_temp;

int	put_pointer_addr(void *p)
{
	struct s_temp	var;

	var.base = "0123456789abcdef";
	var.base_len = 16;
	var.nb = (unsigned long)p;
	if (var.nb == 0)
	{
		write(1, &"(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	var.i = 0;
	while (var.nb != 0)
	{
		var.str[var.i] = var.base[var.nb % var.base_len];
		var.nb /= var.base_len;
		var.i++;
	}
	var.len = var.i;
	var.i--;
	while (var.i >= 0)
		write(1, &var.str[var.i--], 1);
	return (var.len + 2);
}

// #include <stdio.h>
// int main(void)
// {
//     void *p;

//     p = (void *)-8;
//     printf("printf: %d;", printf("%p\n", ""));
//     printf("put_pointer_addr: %d;", put_pointer_addr(""));
// }