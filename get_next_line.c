/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:44 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/07 17:38:28 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stock)
{
	char	*line;
	int		i;
	int		j;

	i = 1;
	j = 0;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (free(stock), NULL);
	while (1)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			return (stock);
		line[i] = '\0';
		stock = ft_strjoin(stock, line);
		if (stock == NULL)
			return (NULL);
		if (ft_strchr(stock, '\n') > -1)
			return (free(line), stock);
	}
	return (free(stock), free(line), stock);
}

char	*stock_modification(char *stock)
{
	char	*next_line;
	int		i;
	int		j;
	int		len;

	next_line = NULL;
	i = ft_strchr(stock, '\n');
	if (i == -1)
		i = ft_strchr(stock, '\0');
	i++;
	len = ft_strlen(stock) - i;
	next_line = malloc(sizeof(char) * (len + 1));
	if (next_line == NULL)
		return (free(stock), NULL);
	j = 0;
	while (j < len)
		next_line[j++] = stock[i++];
	next_line[j] = '\0';
	return (free(stock), next_line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	int			i;
	int			found;

	line = NULL;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	if (!stock)
	{
		stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (stock == NULL)
			return(NULL);
		stock[BUFFER_SIZE] = '\0';
	}	
	stock = read_line(fd, stock);
	//printf("le stock ; %s", stock);
	if (stock == NULL)
		return (NULL);
	found = ft_strchr(stock, '\n');
	if (found == -1)
		found = ft_strchr(stock, '\0');
	found++;
	line = ft_strncpy(line, stock, found);
	if (line == NULL)
		return (free(line), NULL);
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	stock = stock_modification(stock);
	if (stock == NULL)
		return (free(stock), free(line), NULL);
	return (line);
}
