/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:24:51 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/10 14:57:28 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int		ft_to_line(char **str, char **line)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\0')
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	else if ((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		tmp = ft_strdup(&(*str)[len + 1]);
		free(*str);
		*str = tmp;
	}
	return (1);
}

void	buffer_to_static(char **str, char *buffer, int ret)
{
	char *tmp;

	buffer[ret] = '\0';
	if (*str == NULL)
		*str = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*str, buffer);
		free(*str);
		*str = tmp;
	}
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buffer;
	static char	*static_string[MAX_SIZE];

	if (line == NULL || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer_to_static(&static_string[fd], buffer, ret);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (ret < 0)
		return (-1);
	if (ret == 0 && static_string[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_to_line(&static_string[fd], line));
}
