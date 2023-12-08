/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:21:54 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/08 00:22:21 by ymakhlou         ###   ########.fr       */
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

char	*ft_strjoin(char *stock, char *buff)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stock || !buff)
		return (NULL);
	ptr = (char *) malloc (ft_strlen(stock) + ft_strlen(buff) + 1);
	if (!ptr)
		return (NULL);
	while (stock[i])
	{
		ptr[i] = stock[i];
		i++;
	}
	while (buff[j])
	{
		ptr[i++] = buff[j++];
	}
	ptr[i] = '\0';
	return (ptr);
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

char	*read_line(int fd, char *stock)
{
	char	*buff;
	char	*to_free;
	int		read_count;

	read_count = 1;
	buff = (char *) malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	while ((read_count != 0) && (ft_strchr(buff, '\n') == NULL))
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
			return (free(buff), free(stock), buff = NULL, NULL);
		buff[read_count] = '\0';
		to_free = stock;
		stock = ft_strjoin(stock, buff);
		free(to_free);
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (!stock)
	{
		stock = (char *) malloc (1);
		if (!stock)
			return (NULL);
		*stock = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stock), stock = NULL, NULL);
	stock = read_line(fd, stock);
	line = line_to_return(stock);
	stock = modify_static(stock, line);
	return (line);
}

int main (void)
{
	int fd = open("file", O_CREAT | O_RDONLY, 0777);
	// write(fd, "hello t\nhere\nhhhhhh \n 88", 24);
	// close(fd);
	// fd = open("file", O_RDONLY); // Reopen the file in read mode/////it wasnt printing buffer because of these 3 lines
	// close(fd);
	char *s = get_next_line(fd);
	while (s != NULL)
	{
    	printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
    printf("%s", s);
	close(fd);
}