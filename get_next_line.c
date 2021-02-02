#include "get_next_line.h"

char     *if_end(char *end, char **line)
{
	char *p;

	p = NULL;
	if (end)
		if ((p = ft_strchr(end, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(end);
			p++;
			ft_strcpy(end, p);
		}
		else
		{
			*line = ft_strdup(end);
			while (*end)
				*end++ = '\0';
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

	buf = ft_strnew(BUFF_SIZE + 1);
	p = if_end(end, line);
	while (!p && (byt_rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[byt_rd] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			p++;
			end = ft_strdup(p);
		}
		trash = *line;
		*line = ft_strjoin(*line, buf);
		free(trash);
	}
	free(buf);
	if (p)
		return (1);
	return (0);
}

int main(void)
{
	char *line;
	int fd;

	fd = open("C:\\Users\\Dsons\\CLionProjects\\untitled2\\test.txt", O_RDONLY);
	while (1 == (get_next_line(fd, &line)))
		printf("%s\n", line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	get_next_line(fd, &line);
	printf("%s\n", line);

}