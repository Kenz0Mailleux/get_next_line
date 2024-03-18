

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:44 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/07 17:29:48 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stock)
{
	char	*line_read;
	char	*line;
	int		i;

	i = 1;
	line = NULL;
	line_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line_read)
		return ( NULL);
	line = ft_strncpy(line, stock, ft_strlen(stock));
	if (line == NULL)
		return (free(line), free(line_read), NULL);
	while (1)
	{
		i = read(fd, line_read, BUFFER_SIZE);
		if (i == -1)
			return (free(line), free(line_read), NULL);
		line_read[i] = '\0';
		line = ft_strjoin(line, line_read);
		if (line == NULL)
			return (free(line), free(line_read), NULL);
		if (i == 0)
			return (free(line_read), line);
		if (ft_strchr(line, '\n', '\n') > -1)
		{
			//printf("Ceci est la line : %s. ", line);
			return (free(line_read), line);
		}
	}
	return (free(line_read), line);
}

void modify_stock(char *stock, char *line, int i)
{
    int found = 0;
	//printf("%i", i);
    while (line[i] != '\0')
	{
        stock[found++] = line[i++];
    }
	stock[found] = '\0';
	//printf("LINE ; %s", stock);
}



char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1];
	char		*line;
	int			found;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, stock);
	if (line == NULL)
		return (free(line), NULL);
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	found = ft_strchr(line, '\n', '\0');
	if (found == -1)
		return (free(line), NULL);
	found += 1;
	modify_stock(stock, line, found);
	line[found] = '\0';
	return (line);
}
