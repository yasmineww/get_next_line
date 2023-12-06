/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:22:47 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/05 23:30:48 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef		BUFFER_SIZE
# define	BUFFER_SIZE 10
#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char		*get_next_line(int fd);
char	*read_line(int fd, char *st);
char	*ft_strchr(char *buff, int c);
int	ft_strlen(char *buff);
char	*ft_strjoin(char *stock, char *buff);
int	stock_len(char *stock);
char	*ft_strdup(char *stock);
char	*line_to_return(char *stock);
char *modify_static(char *stock, char *line);

#endif