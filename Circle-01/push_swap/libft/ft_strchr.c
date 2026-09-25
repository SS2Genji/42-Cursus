/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:17:38 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/08/13 10:58:39 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chc;

	i = 0;
	chc = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chc)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == chc)
	{
		return ((char *)&s[i]);
	}
	return (0);
}
