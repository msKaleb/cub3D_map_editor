/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:30:00 by msoria-j          #+#    #+#             */
/*   Updated: 2023/04/13 13:42:37 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*lb_rest(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = ft_strlen(line);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	tmp = malloc((j - i) + 2);
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		tmp[j++] = line[i++];
	tmp[j] = '\0';
	free(line);
	return (tmp);
}

static char	*lb_before(char *line)
{
	char	*retline;
	int		i;

	if (!line[0])
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	retline = malloc(i + 2);
	if (!retline)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		retline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		retline[i] = '\n';
		i++;
	}
	retline[i] = '\0';
	return (retline);
}

static char	*read_line(char *retline, char *readbuf, int fd)
{
	int	readchars;

	readchars = 1;
	while (readchars != 0)
	{
		readchars = read(fd, readbuf, BUFFER_SIZE);
		if (readchars == -1)
		{
			free(retline);
			free(readbuf);
			return (NULL);
		}
		readbuf[readchars] = '\0';
		retline = gnl_strjoin(retline, readbuf);
		if (gnl_strchr(readbuf, '\n'))
			break ;
	}
	free(readbuf);
	return (retline);
}

char	*get_next_line(int fd)
{
	static char	*retline[4026];
	char		*readbuf;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbuf = malloc(BUFFER_SIZE + 1);
	if (!readbuf)
		return (NULL);
	retline[fd] = read_line(retline[fd], readbuf, fd);
	if (!retline[fd])
		return (NULL);
	tmp = lb_before(retline[fd]);
	retline[fd] = lb_rest(retline[fd]);
	return (tmp);
}

/*
#include<fcntl.h>
#include<stdio.h>

int main(void)
{
    int fd, fd1, fd2;
	char	*line;
	
    fd = open ("b01", O_RDONLY);
	fd1 = open ("b02", O_RDONLY);
	fd2 = open ("b03", O_RDONLY);
    if (fd == -1)
        return (-1);
	line = get_next_line (fd);
	printf("%s", line);
	line = get_next_line (fd1);
	printf("%s", line);
	line = get_next_line (fd2);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line (fd);
    	printf("%s", line);
		line = get_next_line (fd1);
		printf("%s", line);
		line = get_next_line (fd2);
		printf("%s", line);
	}
	free(line);
    return (0);
}*/