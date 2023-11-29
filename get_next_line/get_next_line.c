/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:21:54 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/11/29 13:02:07 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	int			i;

	i = 1;
	temp = (char *) malloc ();
	if (!temp)
		return (NULL);
	buffer = (char *) malloc ();
	if (!buffer)
		return (NULL);
	if (*temp != '\n')
	{
		while (i <= BUFFER_SIZE)
		{
			read(fd, *buffer, BUFFER_SIZE);
			*temp = *buffer;
			i++;
			temp++;
		}
	}
}

int main (void)
{
	int fd = open("file", O_CREAT | O_WRONLY, 0777);
	write(fd, "Hello everyone how are you\n You can be right and you can be wrong as well \n", 77);
	get_next_line(fd);
	close(fd);
	//a.out process
	//user that launches a.out
}