/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:06:18 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/13 08:25:11 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lit_len;

	if (!*little)
	{
		return ((char *)big);
	}
	lit_len = ft_strlen(little);
	i = 0;
	while (big[i] && (i + lit_len) <= len)
	{
		if (ft_strncmp(&big[i], little, lit_len) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
