/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:35:55 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/12/30 13:06:55 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>

// MACROS
# define DECIMAL_BASE "0123456789"
# define HEXA_UP "0123456789ABCDEF"
# define HEXA_LOW "0123456789abcdef"

// Print a string with specified format to a file descriptor
int		ft_printf_fd(int fd, const char *format, ...);

size_t	ft_putchar_fd(int fd, char c);
size_t	ft_putstr_fd(int fd, char *str);
size_t	ft_putptr_fd(int fd, unsigned long number, char *base);
size_t	ft_putnbr_base_fd(int fd, long int number, char *base);

#endif
