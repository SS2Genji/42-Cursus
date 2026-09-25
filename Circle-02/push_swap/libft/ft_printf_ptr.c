/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:46:00 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/11 23:12:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_puthex_ptr(int fd, unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += pf_puthex_ptr(fd, n / 16);
	len += pf_putchar(fd, "0123456789abcdef"[n % 16]);
	return (len);
}

int	pf_putptr(int fd, unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (pf_putstr(fd, "(nil)"));
	len += pf_putstr(fd, "0x");
	len += pf_puthex_ptr(fd, ptr);
	return (len);
}
