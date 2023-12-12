/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:28:19 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/12 15:38:02 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *st);
char	*ft_strchr(char *buff, int c);
int		ft_strlen(char *buff);
char	*ft_strjoin(char *stock, char *buff);
int		stock_len(char *stock);
char	*my_strdup(char *stock);
char	*line_to_return(char *stock);
char	*modify_static(char *stock, char *line);

#endif