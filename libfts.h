#ifndef LIBFTS_H
# define LIBFTS_H

#include <unistd.h>

int 	ft_isprint(int c);
int 	ft_isalpha(int c);
int 	ft_isalnum(int c);
int 	ft_isdigit(int c);
int 	ft_isascii(int c);

int		ft_tolower(int c);
int		ft_toupper(int c);

size_t	ft_strlen(const char *s);

int		ft_puts(const char *s);
void	ft_bzero(void *s , size_t n);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

char	*ft_strdup(const char *s1);
// char	*ft_strdup(int c);

#endif
