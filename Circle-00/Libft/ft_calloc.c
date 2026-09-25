/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 14:11:32 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/08 16:31:54 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*a;

	if (size != 0 && nmemb > (size_t)-1 / size)
	{
		return (NULL);
	}
	total = nmemb * size;
	a = malloc(total);
	if (a == NULL)
	{
		return (NULL);
	}
	ft_bzero(a, total);
	return (a);
}
