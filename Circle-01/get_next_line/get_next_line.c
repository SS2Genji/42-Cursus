/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsimsek <ahsimsek@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 18:43:18 by ahsimsek          #+#    #+#             */
/*   Updated: 2026/09/01 18:58:02 by ahsimsek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(str), NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (str);
}

static char	*extract_str(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + (str[i] == '\n') + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = '\0';
	return (new_str);
}

static char	*clean_left_str(char *str)
{
	char	*new_line_str;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	new_line_str = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!new_line_str)
		return (free(str), NULL);
	j = 0;
	while (str[++i])
		new_line_str[j++] = str[i];
	new_line_str[j] = '\0';
	free(str);
	return (new_line_str);
}

char	*get_next_line(int fd)
{
	static char	*mem_char;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem_char = read_fd(fd, mem_char);
	if (!mem_char)
		return (NULL);
	line = extract_str(mem_char);
	mem_char = clean_left_str(mem_char);
	return (line);
}
