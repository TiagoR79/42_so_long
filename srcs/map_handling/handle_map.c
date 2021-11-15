/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/15 16:51:38 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int validate_map(t_game *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->map_y)
	{
		j = 0;
		if (i == 0 || i == info->map_y - 1)
			while (info->map_array[i][j] != '\0')
			{
				if(info->map_array[i][j] != '1')
					return(0);
				j++;
			}
		else
		{
			if((int)ft_strlen(info->map_array[i]) != info->map_x)
				return(0);
			else if (info->map_array[i][0] != '1' || info->map_array[i][info->map_x - 1] != '1')
				return(0);
			while (info->map_array[i][j] != '\0')
			{
				if(info->map_array[i][j] == 'E' || info->map_array[i][j] == 'e')
					info->exits += 1;
				if(info->map_array[i][j] == 'P' || info->map_array[i][j] == 'p')
					info->players += 1;
				if(info->map_array[i][j] == 'C' || info->map_array[i][j] == 'c')
					info->collectibles += 1;
				j++;
			}
		}
		i++;
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
	info->map_array = malloc(sizeof(char *) * 100);
	if (info->map_array == NULL)
	{
		printf("malloc failed\n");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		if(line == NULL)
		{
			printf("malloc failed\n");
			exit(0);
		}
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		info->map_array[i] = ft_strdup(line);
		if (info->map_array[i] == NULL)
		{
			printf("\n\tMALLOC FAIL\n\n");
			exit(0);
		}
			printf("\n\tDEBUG: map_array[i] = %s\n\n", info->map_array[i]);
		i++;
		info->map_y++;
		free(line);
	}
	free(line);
	if(!validate_map(info))
	{
		printf("MAP ERROR\n");
		free(info->map_array);
		exit (0);
	}
	printf("Debug:\tn of exits: %d\n", info->exits);
	printf("Debug:\tn of players: %d\n", info->players);
	printf("Debug:\tn of collectibles: %d\n", info->collectibles);

	close(fd);
	return(1);
}
