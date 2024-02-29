/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:20:35 by kenzo             #+#    #+#             */
/*   Updated: 2024/02/29 17:38:19 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open the file.\n");
        return (1);
    }
	int i = 1;
	line = get_next_line(fd);
    while (ft_strlen(line) > 0)
    {
		printf("%s", line);
		line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
