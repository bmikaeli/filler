/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:18:17 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:18:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*res;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (ptr);
	if ((res = (char *)(malloc(size))))
	{
		ft_strncpy(res, (const char *)ptr, ft_strlen((char *)ptr));
		free (ptr);
		return (res);
	}
	return (NULL);
}


void	cpy_into_line(char **line, char *buff, int *i, int fd)
{
	int	j;
	int	ret;

	j = 0;
	while (buff[*i] && buff[*i] != '\n')
	{
		(*line)[j++] = buff[*i];
		if (buff[*i + 1] == '\0' && (ret = read(fd, buff, BUFF_SIZE)))
		{
			*line = ft_realloc((void *)*line, ft_strlen(*line) + BUFF_SIZE + 1);
			buff[ret] = '\0';
		 *i = 0;
		}
		else
		(*i)++;
	}
	(*line)[j] = '\0';
}

int		get_next_line(int const fd, char **line)
{
	static	char	buff[BUFF_SIZE + 1];
	static	int		i = 0;
	static	int		ret = 0;

	if ((*line = (char *)(malloc(BUFF_SIZE + 1))) == NULL)
		return (-1);
	ft_bzero((void *)*line, ft_strlen(*line));
	if (ret == 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) <= 0)
			return (ret);
		buff[ret] = '\0';
	}
	cpy_into_line(line, buff, &i, fd);
	if (buff[i] == '\n' && buff[i + 1])
		i++;
	else
	{
		ret = 0;
		i = 0;
	}
	return (1);
}
