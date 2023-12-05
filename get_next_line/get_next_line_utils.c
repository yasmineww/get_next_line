/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:25:04 by ymakhlou          #+#    #+#             */
/*   Updated: 2023/12/05 01:35:06 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_strjoin(char *stock, char *buff)
{
	int		i;
	int		len;

	i = 0;
	stock = (char *) malloc (ft_strlen(stock) + ft_strlen(buff) + 1);
	if (!stock)
		return (0);
	len = ft_strlen(stock);
	while (buff[i])
	{
		stock[len] = buff[i];
		i++;
		len++;
	}
	stock[len] = '\0';
	return (stock);
}

static char	*line_to_return(char *stock)
{
	
}