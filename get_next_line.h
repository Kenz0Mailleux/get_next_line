/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:36:16 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/05 14:58:29 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 5



#include <string.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
int 	ft_strchr(char *string, int searchedChar);
int		ft_strlen(char *str);
char	*ft_strncpy(char *dest, char *src, int n);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void pustr(char *str);


#endif