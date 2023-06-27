#include	"get_next_line.h"

char	*stach(int fd, char *buf)
{
	int		nbytes;
	char	*new_line;

	nbytes = 1;
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_line)
		return (NULL);
	while (nbytes > 0)
	{
		nbytes = read(fd, new_line, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(new_line);
			return (NULL);
		}
		new_line[nbytes] = '\0';
		buf = ft_strjoin(buf, new_line);
		if (next(buf, '\n'))
			break;
	}
	free(new_line);
	return (buf);
}

char	*get_line(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[j] != '\n')
		line[i++] = buf[j++];
	if (buf[i] == '\n')
		line[i++] = buf[j++];
	line[i] = '\0';
	return (line);
}

char	*clear_stach(char *buf)
{
	int		i;
	int		j;
	char	*new_buf;

	i = 0;
	j = next(buf, '\n');
	if (j < 1)
	{
		free(buf);
		return (NULL);
	}
	while (buf[i] != '\n')
		i++;
	new_buf = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!new_buf)
		return (NULL);
	i = 0;
	while (buf[j])
		new_buf[i++] = buf[j++];
	new_buf[i] = '\0';
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char		*buf[4096];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 4096)
		return (NULL);
	buf[fd] = stach(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = get_line(buf[fd]);
	buf[fd] = clear_stach(buf[fd]);
	return (line);
}
