/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/11 15:23:55 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int validate_line(char *map, int iteration, t_game *info)
{
	int i;
	int j;

	i = iteration;
	//printf("iteration n: %d\n", i);
	//printf("X: %d\n", info->map_x);
	j = 0;
	if (i == 0)
	{
		while (map[j] != '\0')
		{
			if(map[j] != '1')
				return(0);
			j++;
		}
	}
	if (i > 0 || i < info->map_y)
	{
		if (map[0] != '1' || map[info->map_x - 1] != '1')
			return(0);
		while (map[j] != '\0')
		{
			if(map[j] == 'E' || map[j] == 'e')
				info->exits += 1;
			if(map[j] == 'P' || map[j] == 'p')
				info->players += 1;
			if(map[j] == 'C' || map[j] == 'c')
				info->collectibles += 1;
			j++;
		}
		//printf("this is :%c\n", map[info->map_x - 1]);
	}
	if (i == info->map_y)
	{
		while (map[j] != '\0')
		{
			if(map[j] != '1')
				return(0);
			j++;
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
	//read(fd, map, 4096);
		// need map length and height --> struct
	while (get_next_line(fd, &line))
	{
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		if(!validate_line(line, i, info))
		{
			printf("MAP ERROR\n");
			free(line);
			exit (0);
		}
		printf("Debug:\t%s\n", line);
		i++;
		// find last line
	}
	printf("Debug:\tn of exits: %d\n", info->exits);
	printf("Debug:\tn of players: %d\n", info->players);
	printf("Debug:\tn of collectibles: %d\n", info->collectibles);
	/* info->map_y = i;
	if (!validate_line(line, i, info))
	{
		printf("MAP ERROR\n");
		free(line);
		exit (0);
	} */
	free(line);

	//validate_map(map);

	return(1);
}

		//printf("maplength is: %d\n", info->map_x);
