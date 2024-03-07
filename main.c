/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:20:35 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/07 17:07:00 by kmailleu         ###   ########.fr       */
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
    while (1)
    {
		line = get_next_line(fd);
        if (!line)
            return (0);
        if (strlen(line) == 0)
            break;
        if (line[0] == '\021')
            printf("BAKA");
        printf("%s", line);
    }
    close(fd);
    return (0);
}
