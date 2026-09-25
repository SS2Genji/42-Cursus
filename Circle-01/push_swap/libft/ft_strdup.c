/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 15:41:12 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/24 04:06:55 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*d;

	i = ft_strlen(s);
	d = malloc((1) * (i + 1));
	if (d == NULL)
	{
		return (NULL);
	}
	ft_memcpy(d, s, i + 1);
	return (d);
}
