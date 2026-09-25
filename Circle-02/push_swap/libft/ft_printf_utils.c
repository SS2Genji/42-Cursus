/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:46:00 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/11 23:12:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	pf_putstr(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (pf_putstr(fd, "(null)"));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	pf_putnbr(int fd, int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += pf_putchar(fd, '-');
		n = -n;
	}
	if (n >= 10)
		len += pf_putnbr(fd, n / 10);
	len += pf_putchar(fd, (n % 10) + '0');
	return (len);
}

int	pf_putunsigned(int fd, unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += pf_putunsigned(fd, n / 10);
	len += pf_putchar(fd, (n % 10) + '0');
	return (len);
}

int	pf_puthex(int fd, unsigned int n, const char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += pf_puthex(fd, n / 16, format);
	if (format == 'x')
		len += pf_putchar(fd, "0123456789abcdef"[n % 16]);
	else if (format == 'X')
		len += pf_putchar(fd, "0123456789ABCDEF"[n % 16]);
	return (len);
}
