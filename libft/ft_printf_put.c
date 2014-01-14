/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:14:20 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:40:41 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


unsigned long	ft_printf_putchar(char c, unsigned long reset)
{
	static unsigned long	i = 0;

	if (c != '\1')
		ft_putchar(c);
	i++;
	if (reset)
		i = 0;
	return (i - 1);
}

long			ft_printf_putstr(char *str)
{
	unsigned long			i;

	if (!str)
	{
		ft_putstr("(null)");
		return (7);
	}
	i = 0;
	while (str[i])
	{
		ft_printf_putchar(str[i], 0);
		i++;
	}
	return (i);
}

long			ft_printf_putstr_flag(unsigned char *str, char flag)
{
	long					i;
	long					j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((flag && str[i] < 32) || (str[i] > 126))
		{
			ft_printf_putchar('\\', 0);
			if (str[i] < 64)
				ft_printf_putchar('0', 0);
			if (str[i] < 8)
				ft_printf_putchar('0', 0);
			ft_putnbr_base_u(str[i], "01234567");
			j = j + 4;
		}
		else
			ft_printf_putchar(str[i], 0);
		i = i + 1;
	}
	return (i + j);
}
