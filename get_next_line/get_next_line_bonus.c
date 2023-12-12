/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:28:31 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/12 15:53:10 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	buff = (char *) malloc ((size_t)BUFFER_SIZE + 1);
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
	static char	*stock[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
		return (NULL);
	if (!stock[fd])
	{
		stock[fd] = (char *) malloc (1);
		if (!stock[fd])
			return (NULL);
		*stock[fd] = '\0';
	}
	stock[fd] = read_line(fd, stock[fd]);
	line = line_to_return(stock[fd]);
	stock[fd] = modify_static(stock[fd], line);
	return (line);
}

int main (void)
{
	int		fd1 = open("file1", O_CREAT | O_RDWR, 0777);
	int		fd2 = open("file2", O_CREAT | O_RDWR, 0777);
	int		arr[2] = {fd1, fd2};
	char	*s;
	int		i;

	write(fd1, "hello \n hey there ", 18); 
	write(fd2, "are you \n good?", 15); 
	close (fd1);
	close (fd2);
	fd1 = open("file1", O_RDONLY, 0777); 
	fd2 = open("file2", O_RDONLY, 0777);
	i = 0;
	while (i < 2)
	{
		s = get_next_line(arr[i % 2]);
		while (s != NULL)
		{
			printf("%s", s);
			free(s); 
			s = get_next_line(arr[i % 2]);
		}
		i++;
	}
	close (fd1);
	close (fd2);
}