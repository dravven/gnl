#include "get_next_line.h"

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char     *if_end(char **end, char **line)
{
	char *p;

	p = NULL;
	if (*end)
		if ((p = ft_strchr(*end, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(*end);
			p++;
			ft_strcpy(*end, p);
		}
		else
		{
			*line = ft_strdup(*end);
			ft_strclr(*end);
		}
	else
		*line = ft_strnew(1);
	return (p);
}

int 	get_next_line(const int fd, char **line)
{
	static char     *end;
	char            *buf;
	int             byt_rd;
	char            *p;
	char            *trash;
	int		d;

	trash = NULL;
	p = NULL;
	d = 0;
	if (!line || fd < 0 || read(fd, end, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	trash = end;
	p = if_end(&end, line);
//		free(trash);
	while (!p && (byt_rd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byt_rd] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			p++;
			trash = end;
			end = ft_strdup(p);
			free(trash);
			trash = NULL;
		}
		trash = *line;
		if(!(*line = ft_strjoin(*line, buf)) || byt_rd < 0)
			return (-1);
		free(trash);
		trash = NULL;
	}
	free(buf);
	if (p)
		return (1);
	else
	{
		if (trash != NULL)
			free(trash);
		return (0);
	}
}

