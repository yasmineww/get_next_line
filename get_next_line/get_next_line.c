/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:21:54 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/06 00:00:16 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *buff)
{
	int	count;

	count = 0;
	while (buff[count])
		count++;
	return (count);
}

char	*ft_strchr(char *buff, int c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(buff) + 1)
	{
		if (buff[i] == (char)c)
			return ((char *)buff + i);
		i++;
	}
	return (NULL); 
}
# include <stdlib.h>
# include <strings.h>
char	*read_line(int fd, char *st)
{
	char		*buff;
	int		read_count;

	read_count = 1;
	buff = NULL;
	buff = (char *) malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	memset(buff, 0, BUFFER_SIZE + 1);
	printf("buffff [%s]\n", buff);
	while ((read_count != 0) && (ft_strchr(buff, '\n') == NULL))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_count] = '\0';
		st = ft_strjoin(st, buff);//leak
		printf("walid %s\n",st);
	}
	free(buff);
	buff = NULL;
	return (st);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (!stock)
		stock = "";
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_line(fd, stock);
	printf("stock1 ==> [%s]\n", stock);
	line = line_to_return(stock);
	printf("stock2 ==> [%s]\n", stock);
	stock = modify_static(stock, line);
	return (line);
}
int main (void)
{
	int fd = open("file", O_CREAT | O_WRONLY, 0777);
	write(fd, "hello t\nhere\n", 12);
	close(fd);
	fd = open("file", O_RDONLY); // Reopen the file in read mode/////it wasnt printing buffer because of these 3 lines
    printf("-------->%s \n",get_next_line(fd));
	printf("-------->%s",get_next_line(fd));
	printf("-------->%s",get_next_line(fd));
	close(fd);
}