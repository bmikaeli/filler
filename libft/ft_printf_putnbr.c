/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:12:35 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:40:40 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printaddress(unsigned long int n);

void			ft_putpaddress_printf(void *ptr)
{
	unsigned long	n;

	n = (char *)ptr - (char *)0;
	ft_printf_putchar('0', 0);
	ft_printf_putchar('x', 0);
	ft_printaddress(n);
}

static void		ft_printaddress(unsigned long int n)
{
	if (n / 16 > 0)
		ft_printaddress(n / 16);
	if (n % 16 < 10)
		ft_printf_putchar((n % 16) + '0', 0);
	else
		ft_printf_putchar(((n % 16) - 10) + 'a', 0);
}

long			ft_putnbr_base_s(long nbr, char *base)
{
	if (nbr < 0)
	{
		ft_printf_putchar('-', 0);
		ft_putnbr_base_u(-nbr, base);
	}
	if (nbr >= ft_strlen(base))
		ft_putnbr_base_u(nbr / ft_strlen(base), base);
	if (nbr >= 0)
		ft_printf_putchar(base[nbr % ft_strlen(base)], 0);
	return (nbr);
}

long			ft_putnbr_base_u(long nbr, char *base)
{
	if (nbr >= ft_strlen(base))
		ft_putnbr_base_u(nbr / ft_strlen(base), base);
	ft_printf_putchar(base[nbr % ft_strlen(base)], 0);
		return (nbr);
}
