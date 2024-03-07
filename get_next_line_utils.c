/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:24:01 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/07 17:35:56 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res)
		return (free(s1), NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[sizetotal] = '\0';
	return (free(s1), res);
}

//renvoit l'indice de la premiere apparition de searchedChar
int	ft_strchr(char *s, int c)
{
	int	len;

	len = 0;
	while (s[len] != 0)
	{
		if (s[len] == (char)c)
			return (len);
		len++;
	}
	if ((char)c == s[len])
		return (len);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



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
/*
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
	static char	stock[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			found;

	line = NULL;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	stock[BUFFER_SIZE + 1] = '\0';
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
	return (line);
}
*/