/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:22:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/07 16:37:09 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_validate_file(char *file)
{
    int fd;
    char *line;

    line = "\0";
    if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		handle_error(E_INVALID_MAP_NAME);
    fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_error(E_INVALID_FILE);
	line = get_next_line(fd);
    printf("line: |%s|\n", line);
    if (line == NULL || line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
    {
        close(fd);
		free(line);
        handle_error(E_INVALID_MAP_CONTENT);
    }
    close(fd);
	free(line);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        handle_error(E_INVALID_ARGS);
    ft_validate_file(argv[1]);
    // ft_printf("|%s|\n", get_next_line(open("maps/test.ber",O_RDONLY)));
}