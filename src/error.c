/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:00 by lhenriqu          #+#    #+#             */
/*   Updated: 2025/01/07 16:01:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void handle_error(short code)
{
    if (code == E_INVALID_ARGS)
        ft_printf_fd(2, C_ERROR "expected: ./so_long <map>\n" C_BREAK);
    if (code == E_INVALID_MAP_NAME)
        ft_printf_fd(2, C_ERROR "maps must be terminated by .ber\n" C_BREAK);
    if (code == E_INVALID_MAP_CONTENT)
        ft_printf_fd(2, C_ERROR "invalid map content\n" C_BREAK);
    if (code == E_INVALID_FILE)
        perror(C_ERROR "invalid file" C_BREAK);

    exit(code);
}