#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>

//# define BUFFER_SIZE 10000000

# define MALLCHECK(x) if (!x) return (-1);

char        *ft_strcpy(char *dest, char *src);

void		ft_bzero(void *b, size_t n);

char		*ft_strjoin(char const *s1, char const *s2);

char        *ft_strchr(const char *str, int c);

char	    *ft_strnew(size_t size);

char	    *ft_strdup(char *src);

int	ft_strlen(char const *str);

int		    get_next_line(const int fd, char **line);
#endif