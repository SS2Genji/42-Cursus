/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.com.tr> +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:14:32 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/30 12:46:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_formats(va_list args, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		len += ft_putptr((unsigned long)va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_formats(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
