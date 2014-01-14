/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:17:12 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:40:28 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arglist;

	va_start(arglist, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '#')
				format++;
			if (ft_printf_flag(format, arglist) == -1)
				ft_printf_putchar(*format, 0);
		}
		else
			if (*format != 'i' && *format != 'd' )
				ft_printf_putchar(*format, 0);
		format++;
		while ((ft_isdigit(*format) == 1))
			format++;
	}
	ret = ft_printf_putchar('\1', 0);
	ft_printf_putchar('\1', 1);
	va_end(arglist);
	return (ret);
}
