/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:25:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/05 23:43:59 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *stock)
{
	int		i;
	int		len;
	int		len_line;
	char	*temp;

	i = 0;
	len = ft_strlen(stock);
	len_line = stock_len(stock) + 1;
	temp = (char *) malloc (len - len_line + 1);
	if (!temp)
		return (NULL);
	while (stock[len_line])
	{
		temp[i] = stock[len_line];
		len_line++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	stock_len(char *stock)
{
	int	count;

	count = 0;
	while (stock[count] != '\n' && stock[count] != '\0')
		count++;
	return (count);
}

static char	*helper(char const *s1, char const *s2, char *ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	helper(s1, s2, ptr);
	return (ptr);
}

// char	*ft_strjoin(char *stock, char *buff)
// {
// 	int		i;
// 	int		len;
	
// 	i = 0;
// 	stock = (char *) malloc (ft_strlen(stock) + ft_strlen(buff) + 1);
// 	if (!stock)
// 		return (NULL);
// 	len = ft_strlen(stock);
// 	while (buff[i])
// 	{
// 		stock[len] = buff[i];
// 		i++;
// 		len++;
// 	}
// 	stock[len] = '\0';
// 	return (stock);
// }

char	*line_to_return(char *stock)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	line = (char *) malloc (stock_len(stock) + 2);
	if (!line)
		return (NULL);
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	line[i + 1] = '\n';
	// temp = ft_strdup(stock);
	// if (!temp)
	// {
	// 	free(line);/////////
	// 	return (NULL);
	// }
	// free(stock);
	// stock = temp;
	// printf("\n stock in func => %s\n", stock);
	return (line);
}

char *modify_static(char *stock, char *line)
{
	char *temp;
	
	temp = ft_strdup(stock);
	if (!temp)
	{
		free(line);/////////
		return (NULL);
	}
	free(stock);
	stock = temp;
	//printf("\n stock in func => %s\n", stock);
	return (stock);
}