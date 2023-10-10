/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:45:05 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/10 13:22:43 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int contains(char t, char *o)
{
	while (*o)
	{
		if(t == *o)
			return 1;
		o++;
	}
	return 0;
}

int checktype(char *t, va_list d)
{
	char *options;
	void *temp;
	long temp1;
	
	options = "cspdiuxX%";
	if (!contains(*t, options))
		return 0;
	t++;
	if (*t == 'c')
		ft_putchar_fd(va_arg(d, int), 1);
	else if (*t == 's')
	{
		temp = va_arg(d, char *);
		if (!temp)
			temp = "(null)";
		ft_putstr_fd((char *)temp, 1);
		return ft_strlen(temp);
	}
	else if (*t == 'd' || *t == 'i')
		return putnbr_base(va_arg(d, int), "0123456789");
	else if (*t == 'p')
	{
		ft_putstr_fd("0x", 1);
		temp1 = va_arg(d, unsigned long);
		if (temp1 == LONG_MIN || (unsigned long)temp1 == ULONG_MAX)
		{
			if (temp1 == LONG_MIN)
				ft_putstr_fd("8000000000000000", 1);
			if ((unsigned long)temp1 == ULONG_MAX)
				ft_putstr_fd("ffffffffffffffff", 1);
			return 18;
		}
		return putnbr_base(temp1, "0123456789abcdef") + 2;
	} 
	else if (*t == 'u')
		return putnbr_base(va_arg(d, unsigned int), "0123456789");
	else if (*t == 'x')
		return putnbr_base(va_arg(d, unsigned int), "0123456789abcdef");
	else if (*t == 'X')
		return putnbr_base(va_arg(d, unsigned int), "0123456789ABCDEF");
	else if (*t == '%')
		ft_putchar_fd('%', 1);
	return 1;
}


int    ft_printf(const char *format, ...)
{
	char *f;
	int i;
	va_list data;

	if (!format)
		return -1;
	va_start(data, format);
	f = (char *)format;
	i = 0;
	while (*f)
	{
		if (*f == '%')
		{
			i += checktype(f, data);
			f += 2;
		}
		else
		{
			ft_putchar_fd(*f, 1);
			f++;
			i++;
		}	
	}
	va_end(data);
	return i;
}

// #include <stdio.h>
// int main(void)
// {
// 	// int testnum = NULL;
// 	// char *teststr = NULL;
// 	// ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", testnum, teststr, &testnum, testnum, testnum, testnum, testnum, testnum);
// 	// printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n\n", testnum, teststr, &testnum, testnum, testnum, testnum, testnum, testnum);
	
// 	// ft_printf(" %c %c %c \n", 0, '1', '2');
// 	// printf(" %c %c %c \n\n", 0, '1', '2');
	
// 	printf("m:%d \n",  
// 	ft_printf(" %p %p ", ULONG_MAX, -0)
// 	);
// 	printf("t:%d ", 
// 	printf(" %lu %p ", ULONG_MAX, -0)
// 	);

// 	// printf("%ld, %ld", LONG_MIN, LONG_MAX);
// }
