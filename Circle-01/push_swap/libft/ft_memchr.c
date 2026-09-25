/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 20:43:24 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/24 04:28:42 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*loc;
	unsigned char		col;
	size_t				i;

	i = 0;
	loc = (const unsigned char *)s;
	col = (unsigned char)c;
	while (i < n)
	{
		if (loc[i] == col)
		{
			return ((void *)&loc[i]);
		}
		i++;
	}
	return (NULL);
}
