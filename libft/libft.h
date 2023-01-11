/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:19:22 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 17:55:07 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strequ(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *ds, const char *src, size_t size);
char		*ft_itoa(int nb);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, const char *str);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s, const char *needle);
char		*ft_strnstr(const char *src, const char *little, size_t len);
char		*ft_strtrim(const char *s);
char		*ft_strnew(size_t size);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char ));
char		**ft_split(char const *s, char c);
void		ft_putendl(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_strclr(char *s);
void		ft_memdel(void **ap);
void		ft_strdel(char **as);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_calloc(size_t nmemb, size_t size);
float		ft_atold(char *str);

#endif
