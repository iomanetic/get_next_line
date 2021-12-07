#include "get_next_line.h"
#include <stdio.h>

int len_line(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\n')
        i++;
    return (i);
}

char    *ft_strcpy(char *dst, char *src)
{
    int index;

    index = 0;
    while(src[index])
    {
        dst[index] = src[index];
        index++;
    }
    if(dst[index] != '\0')
        dst[index] = '\0';
    return (dst);
}

void	clear_line(char *str)
{
	if (str)
	{
		while (*str)
		{
			*str = '\0';
			str++;
		}
	}
}

// char    *get_line(char *rem)
// {
//     char    *tmp;
//     int     i;

//     tmp = (char *) malloc(sizeof(char) * len_line(rem) + 1);
//     i = 0;
//     while(rem[i] != '\n' && rem[i] != '\0')
//     {
//         tmp[i] = rem[i];
//         i++;
//     }
//     tmp[i] = '\0';
//     free(rem);
//     // printf("tmp - %s\n", tmp);
//     return(tmp);
// }

void    check_remainder(char *rem, char *line)
{
    char    *p_n;
    
    if (rem)
    {
        if((p_n = ft_strchr(rem, '\n')))
        {
            *p_n = '\0';
            line = ft_strdup(rem);
            ft_strcpy(rem, ++p_n);
        }
        else
        {
            line = ft_strdup(rem);
            clear_line(rem);
        }
    }
    else
        line = ft_strdup("");
}

char	*get_next_line(int fd)
{
	static char     *remainder;
	char            buf[BUFFER_SIZE + 1];
	char		    *line;
	char		    *chr;
	int             rd;
    char            *anti_leak;
    int             flag;
 
    // line = check_remainder(remainder, line);
    flag = 1;
    if(remainder)
        line = ft_strdup(remainder);
    if(!remainder)
        line = ft_strdup("");
    while (flag && (rd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rd] = '\0';	
		if ((chr = ft_strchr(buf, '\n')))
		{
            *chr = '\0';
            chr++;
			remainder = ft_strdup(chr);
            flag = 0;
        }
        // anti_leak = line;
	    line = ft_strjoin(line, buf);
        // free(anti_leak);
	}
	return (line);
}

#include <fcntl.h>
int main(void)
{
	int fd;
    int i;

	fd = open("test.txt", O_RDONLY);
    //printf("free - %s", rem);
    i = 0;
    while(i < 2)
    {
        printf("i - %s\n", get_next_line(fd));
        i++;
    }
}
