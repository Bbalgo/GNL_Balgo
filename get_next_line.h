#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#  endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

size_t		ft_strlen(const char *s);
int		next(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
