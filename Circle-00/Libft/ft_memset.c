/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:38:05 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/14 19:06:18 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*dest;

	dest = (unsigned char *)ptr;
	while (num > 0)
	{
		*dest = (unsigned char)value;
		dest++;
		num--;
	}
	return (ptr);
}
