/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:44 by kenzo             #+#    #+#             */
/*   Updated: 2024/02/29 17:24:12 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stock)
{
	char 	*line;
	int	i;
	int 	j;

	i = 1;
	j = 0;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (i != 0)
	{
		
		i = read(fd, line, BUFFER_SIZE);
		if (i == 0)
		{
			free(line);
			//printf("end of the file: %s ;\n", stock);
			return(stock); //free??
		}
		line[i] = '\0';
		stock = ft_strjoin(stock, line);
		if (ft_strchr(stock, '\n') > -1)
		{
			free(line);
			return(stock);
		}
	}
	free(line);
	return (stock);
}

char *stock_modification(char *stock)
{
	char *next_line;
	int i;
	int j;
	int len;

	i = ft_strchr(stock, '\n') + 1;
	//printf("%i???", i);
	if (i < 1)
		return (NULL);
	len = ft_strlen(stock) - i;
	next_line = malloc(sizeof(char) * len);
	if (next_line == NULL)
		return (NULL);	
	j = 0;
	while (j < len)
	{
		next_line[j++] = stock[i++];
	}
	next_line[j] = 0;
	//printf(next_line);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char *line;
	int i;
	int found;

	i = 0;
	if (!stock)
		stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	//	read_line
	//printf("This is the stock : %s ;\n", stock);
	stock = read_line(fd, stock);
	if (!stock)
	{
		printf("This is the end : %s ;\n", stock);
		return (NULL);
	}
	found = ft_strchr(stock, '\n') + 1;
	if (found == -0)
	{
		found = ft_strchr(stock, '\0');
	}
	//printf("%i???", found);
	//printf("%i", found);
	line = ft_strncpy(line, stock, found);
	//printf("This is the line : %s ;", line);
	stock = stock_modification(stock);
	//printf("This is the stock : %s ;\n", stock);
	return (line);
}
