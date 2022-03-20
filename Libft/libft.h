/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:51:57 by lbusi             #+#    #+#             */
/*   Updated: 2022/03/19 12:42:13 by lbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>

int	            ft_isalpha(int c);
int	            ft_isdigit(int c);
int	            ft_isalnum(int c);
int	            ft_isascii(int c);
int	            ft_isprint(int c);
int             ft_tolower(int letter);
int             ft_toupper(int letter);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int             ft_atoi(const char *str);
char            *ft_strchr(const char *str, int c);
char            *ft_strrchr(const char *str, int c);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
unsigned int	ft_strlcat(char *dst, char *src, unsigned int	size);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
size_t          ft_strlen (const char *str);
void            *ft_memset(void *str, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void            ft_bzero(void *s, size_t n);
void			*ft_calloc (size_t nitems, size_t size);

#endif