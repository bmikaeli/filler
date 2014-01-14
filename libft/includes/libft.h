/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:28:39 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:41:51 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE	32
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int				ft_atoi(const char *str);
void			*ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *s1, const void * s2, int c, size_t n);
void			*ft_memcpy(void *s1, const void * s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
int				ft_strlen(const char *str);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_itoa(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_memmove(void *s1, const void *s2, size_t n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			cpy_into_line(char **line, char *buff, int *i, int fd);
void			*ft_realloc(void *ptr, size_t size);
int				get_next_line(int const fd, char **line);
long			ft_putstr_flag(unsigned char *str);
long			ft_printf_flag(const char *flag, va_list ptr);
long			ft_printf_flag2(const char *flag, va_list ptr);
long			ft_printf_flag3(const char *flag, va_list ptr);
long			ft_printf_flag4(const char *flag, va_list ptr);
long			ft_printf_flag5(const char *flag, va_list ptr);
int				ft_printf(const char *format, ...);
unsigned long	ft_printf_putchar(char c, unsigned long reset);
long			ft_printf_putstr(char *str);
long			ft_printf_putstr_flag(unsigned char *str, char flag);
unsigned long	ft_countdigits(unsigned nbr, char *base);
int				ft_isanyof(char c, char const *seps);
long			ft_putnbr_base_s(long nbr, char *base);
long			ft_putnbr_base_u(long nbr, char *base);
void			ft_putpaddress_printf(void *ptr);

# endif /* LIBFT_H */
