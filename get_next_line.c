#include "get_next_line.h"
#include <stdio.h>
int	len_line(char *rem)
{
	int	i;

	i = 0;
	while(rem[i + 1] != '\n')
		i++;
	return (i);
}

char	*get_line(char *rem)
{
	 int	i;
	 char	*tmp;

	i = 0;
	tmp = (char*) malloc(sizeof(char) * len_line(rem) + 1);
	if(!tmp)
		return (NULL);
	while(rem[i] != '\n' && rem[i])
	{
		tmp[i] = rem[i];
		i++;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*chr;
	int		rd;
	int		flag;
	
	if (!remainder)
		line = ft_strdup("");
	if (remainder)
		line = ft_strdup(remainder);
	flag = 1;
	while (flag && (rd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rd] = '\0';	
		if ((chr = ft_strchr(buf, '\n')))
		{
			chr++;
			//printf("db - %s\n", chr);
			remainder = ft_strdup(chr);
			flag = 0;
		}
		line = ft_strjoin(line, buf);
	}
	line = get_line(line);
	return (line);
}

#include <fcntl.h>
int main(void)
{
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("1 - %s\n", get_next_line(fd));
	printf("2 - %s\n", get_next_line(fd));
	printf("3 - %s\n", get_next_line(fd));
}
