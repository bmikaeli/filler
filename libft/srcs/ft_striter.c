/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:22:52 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:45 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f) (char *))
{
	int	i;

	i = 0;
	if (s && f)
	{
	while (*(s + i))
		f(s + i++);
	}
}
