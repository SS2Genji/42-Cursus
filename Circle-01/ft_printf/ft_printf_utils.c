/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.com.tr> +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 12:46:00 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/30 12:46:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_puthex(unsigned int n, const char format)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	if (format == 'x')
		len += ft_putchar("0123456789abcdef"[n % 16]);
	else if (format == 'X')
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len);
}

static int	ft_puthex_ptr(unsigned long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_ptr(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex_ptr(ptr);
	return (len);
}
