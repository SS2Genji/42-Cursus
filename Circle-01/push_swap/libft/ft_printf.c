/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:14:32 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/11 23:12:00 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(int fd, va_list args, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += pf_putchar(fd, va_arg(args, int));
	else if (specifier == 's')
		len += pf_putstr(fd, va_arg(args, char *));
	else if (specifier == 'p')
		len += pf_putptr(fd, (unsigned long)va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		len += pf_putnbr(fd, va_arg(args, int));
	else if (specifier == 'u')
		len += pf_putunsigned(fd, va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += pf_puthex(fd, va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		len += pf_putchar(fd, '%');
	return (len);
}

static int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_formats(fd, args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			len += pf_putchar(fd, format[i]);
		i++;
	}
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	len = ft_vdprintf(fd, format, args);
	va_end(args);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	len = ft_vdprintf(1, format, args);
	va_end(args);
	return (len);
}
