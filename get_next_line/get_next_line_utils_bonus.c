/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:28:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/07 16:56:20 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_strdup(char *stock)
{
	int		i;
	int		len;
	int		len_line;
	char	*temp;

	i = 0;
	len = ft_strlen(stock);
	len_line = stock_len(stock);
	temp = (char *) malloc (len - len_line + 1);
	if (!temp)
		return (NULL);
	while (stock[len_line])
		temp[i++] = stock[len_line++];
	temp[i] = '\0';
	return (temp);
}

char	*modify_static(char *stock, char *line)
{
	char	*temp;

	if (!stock || stock[0] == '\0')
		return (free(stock), NULL);
	temp = my_strdup(stock);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(stock);
	stock = temp;
	return (stock);
}

int	stock_len(char *stock)
{
	int	count;

	count = 0;
	while (stock[count])
	{
		if (stock[count] == '\n')
			return (count + 1);
		count++;
	}
	return (count);
}

char	*line_to_return(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock || stock[0] == '\0')
		return (NULL);
	line = (char *) malloc (stock_len(stock) + 1);
	if (!line)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}