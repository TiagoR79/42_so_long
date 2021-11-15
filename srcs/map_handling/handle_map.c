/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/15 11:29:38 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int validate_map(t_game *info)
{
	int i;
	int j;

	//printf("iteration n: %d\n", info->map_y);
	//printf("X: %d\n", info->map_x);
	i = 0;
	while (info->map_array[i])
	{
		j = 0;
		printf("Debug:\tmap_array[i]: %s\n", info->map_array[i]);
		printf("Debug:\titeration n: %d\n", i + 1);
		if (i == 0 || i == info->map_y - 1)
		{
			printf("Debug:\tInside if 1\n");
			while (info->map_array[i][j] != '\0')
			{
				if(info->map_array[i][j] != '1')
				{
					printf("Debug:\tif != 1\n");
					return(0);
				}
				j++;
			}
			printf("Debug:\tSucess\n");
		}
		else
		{
			printf("Debug:\tInside Else\n");
			//printf("DEBUG:\tstrlen map : %d\n", (int)ft_strlen(map));
			//printf("DEBUG:\tmap_x : %d\n", info->map_x);
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
			//printf("DEBUG:\tthis is :%c\n", map[info->map_x - 1]);
		}
		printf("Debug:\tNext Iteration\n");
		i++;
	}
	return(1);
}

int handle_map(char *file, t_game *info)
{
	int fd;
	int i;
	int j;
	char *line;

	i = 0;
	fd = open(file, O_RDONLY);
		// need map length and height --> struct
	// Check this malloc                                  <--------------------------
	info->map_array = malloc(sizeof(char *) * 1000);
	while (get_next_line(fd, &line))
	{
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		info->map_array[i++] = ft_strdup(line);
		//printf("Debug:\t%c\n", line[j]);
		//j++;

		info->map_y++;
		//printf("Debug: map_y is:\t%d\n", info->map_y);
		//printf("Debug:\t%s\n", line);
		free(line);
		// find last line
	}

	// ========= Array DEBUG  ==============
	/* i = 0;
	while(i < info->map_y)
		printf("Debug:\tmap_array: %s\n", info->map_array[i++]); */
	// ======================================

	if(!validate_map(info))
	{
		printf("MAP ERROR\n");
		free(line);
		exit (0);
	}
	printf("Debug:\tn of exits: %d\n", info->exits);
	printf("Debug:\tn of players: %d\n", info->players);
	printf("Debug:\tn of collectibles: %d\n", info->collectibles);

	//close(fd);
	//free(line);

	return(1);
}

		//printf("maplength is: %d\n", info->map_x);
