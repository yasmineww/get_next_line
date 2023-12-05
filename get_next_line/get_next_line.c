/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:21:54 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/05 13:02:37 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *buff)
{
	int	count;

	count = 0;
	while (buff[count])
		count++;
	return (count);
}

static char	*ft_strchr(char *buff, int c)
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

static char	*read_line(int fd, char *buff)
{
	char	*stock;
	int		read_count;

	read_count = 1;
	buff = (char *) malloc (BUFFER_SIZE + 1);
	if (!BUFFER_SIZE)
		return (NULL);
	stock = (char *) malloc (1);
	if (!stock)
		return (NULL);
	stock[0] = '\0';
	while ((read_count != 0) && (ft_strchr(buff, '\n') == NULL))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_count] = '\0';
		stock = strjoin(stock, buff);
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*stock;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_line(fd, *buff);
	line = line_to_return(stock);
	// line = (char *) malloc ();
	// return (NULL);
}
// int main (void)
// {
// 	int fd = open("file", O_CREAT | O_WRONLY, 0777);
// 	write(fd, "hello t\nhere\n", 12);
// 	close(fd);
// 	fd = open("file", O_RDONLY); // Reopen the file in read mode/////it wasnt printing buffer because of these 3 lines
//     printf("get_next_line is    %s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));
// 	//printf("%s",get_next_line(fd));
// 	close(fd);
// }
