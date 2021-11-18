/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/17 10:33:55 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int validate_map(t_game *info)
{
	int i;
	int j;

	i = -1;
	while (++i < info->map_y)
	{
		j = 0;
		if (i == 0 || i == info->map_y - 1)
			while (info->map_array[i][j] != '\0')
			{
				if(info->map_array[i][j++] != '1')
					error(ERROR_MAP_BORDER, info);
			}
		else
		{
			if((int)ft_strlen(info->map_array[i]) != info->map_x)
				error(ERROR_MAP_RECTANGLE, info);
			else if (info->map_array[i][0] != '1' || info->map_array[i][info->map_x - 1] != '1')
				error(ERROR_MAP_BORDER, info);
			while (info->map_array[i][j] != '\0')
			{
				// TO DO: new function to parse and validate if > 1
				if(info->map_array[i][j] == 'E' || info->map_array[i][j] == 'e')
					info->exits += 1;
				if(info->map_array[i][j] == 'P' || info->map_array[i][j] == 'p')
					info->players += 1;
				if(info->map_array[i][j] == 'C' || info->map_array[i][j] == 'c')
					info->collectibles += 1;
				j++;
			}
		}
	}
	return(1);
}

int handle_map(char *file, t_game *info)
{
	int fd;
	int i;
	char *line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	info->map_array = malloc(sizeof(char *) * 1000);
	while (get_next_line(fd, &line))
	{
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		info->map_array[i] = ft_strdup(line);
		i++;
		info->map_y++;
		free(line);
	}
	free(line);
	validate_map(info);
	close(fd);
	return(1);
}
