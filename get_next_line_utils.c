/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:24:01 by kenzo             #+#    #+#             */
/*   Updated: 2024/02/29 17:34:17 by kenzo            ###   ########.fr       */
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
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = '\0';
	return (res);
}


//renvoit l'indice de la premiere apparition de searchedChar
int	ft_strchr(char *str, int searchedChar)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != searchedChar && str[i] != 0)
		i++;
	if (str[i] == searchedChar)
		return (i);
	else
		return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int i;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		//printf("this is the src : %s ??\n", src);
		//printf("%i", n);
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	//printf("this is the dest : %s ??\n", dest);
	return (dest);
}


void pustr(char *str)
{
    if (str != NULL) {
        size_t len = 0;
        // Calculate the length of the string
        while (str[len] != '\0') {
            len++;
        }
        // Write the string to stdout
        write(1, str, len);
        // Write newline character
        write(1, "\n", 1);
    }
}