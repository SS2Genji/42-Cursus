/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:35:00 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/11 23:12:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	pf_putchar(int fd, char c);
int	pf_putstr(int fd, char *s);
int	pf_putnbr(int fd, int n);
int	pf_putunsigned(int fd, unsigned int n);
int	pf_puthex(int fd, unsigned int n, const char format);
int	pf_putptr(int fd, unsigned long ptr);

#endif
