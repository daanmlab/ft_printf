/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:50:08 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/08 22:05:17 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int putnbr_base(long n, char *base);
int    ft_printf(const char *format, ...);

#endif