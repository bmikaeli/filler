/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:19:24 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:40:41 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_printf_flag(const char *flag, va_list ptr)
{
	if (*flag == 'Z')
		return (ft_printf_putchar('Z', 0));
	else if (*flag == '%')
		return (ft_printf_putchar('%', 0));
	else if (*flag == 'c')
		return (ft_printf_putchar(va_arg(ptr, int), 0));
	else if (*flag == 's')
		return (ft_printf_putstr(va_arg(ptr, char*)));
	else if (*flag == 'u')
		return (ft_putnbr_base_u(va_arg(ptr, unsigned int), "0123456789"));
	else if (*flag == 'o')
		return (ft_putnbr_base_u(va_arg(ptr, unsigned int), "01234567"));
	else if (*flag == 'x')
		return (ft_putnbr_base_u(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (*flag == 'Y')
		return (ft_printf_putstr("YY"));
	else if (*flag == '\0')
		return (ft_printf_putchar('0', 0));
	else if (*flag == 'X')
		return (ft_putnbr_base_u(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (*flag == 'b')
		return (ft_putnbr_base_u(va_arg(ptr, unsigned int), "01"));
	else
		return (ft_printf_flag2(flag, ptr));
}

long	ft_printf_flag2(const char *flag, va_list ptr)
{
	if (*flag == 'S')
		return (ft_printf_putstr_flag(va_arg(ptr, unsigned char*), 0));
	else if (*flag == 'd' || *flag == 'i')
	{
		ft_putnbr(va_arg(ptr, int));
		return (1);
	}
	else if (*flag == ' ')
	{
		ft_printf_putstr(" ");
		ft_putnbr(va_arg(ptr, int));
		return (1);
	}
	else if (*flag == 'p')
	{
		ft_putpaddress_printf(va_arg(ptr, void*));
		return (1);
	}
	else
		return (ft_printf_flag3(flag, ptr));
}

long	ft_printf_flag3(const char *flag, va_list ptr)
{
	int	i;
	int	z;

	if (*flag == '+')
	{
		z = va_arg(ptr, int);
		i = ft_atoi((flag + 1));
		while (--i > ft_strlen(ft_itoa(z)))
			ft_printf_putstr(" ");
		ft_printf_putchar('+',0);
		ft_putnbr(z);
		return (1);
	}
	else if (*flag == '-')
	{
		z = va_arg(ptr, int);
		i = ft_atoi((flag + 1));
		ft_putnbr(z);
		while (i-- > ft_strlen(ft_itoa(z)))
			ft_printf_putstr(" ");
		return (1);
	}
	else
		return (ft_printf_flag4(flag, ptr));
}

long	ft_printf_flag4(const char *flag, va_list ptr)
{
	if (*flag == '*')
	{
		int	i;
		int	z;

		z = va_arg(ptr, int);
		i = va_arg(ptr, int);
		if (z >= 0)
		{
			while (z-- > ft_strlen(ft_itoa(i)))
				ft_printf_putstr(" ");
			ft_putnbr(i);
		}
		else
		{
			z *= -1;
			ft_putnbr(i);
			while (z-- > ft_strlen(ft_itoa(i)))
				ft_printf_putstr(" ");
		}
		return (1);
	}
	else
		return (ft_printf_flag5(flag, ptr));
}

long	ft_printf_flag5(const char *flag, va_list ptr)
{
	int	i;
	int	z;

	if (ft_isdigit(*flag) == 1)
	{
		z = va_arg(ptr, int);
		i = ft_atoi((flag));
		while (i-- > ft_strlen(ft_itoa(z)))
			ft_printf_putstr(" ");
		ft_putnbr(z);
		return (1);
	}
	else
		return (-1);
}
