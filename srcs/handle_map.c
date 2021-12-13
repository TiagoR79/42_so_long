/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/12/13 12:04:34 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int validate_map(t_game *info)
{
	int i;
	int j;

	i = -1;
	// Loop iterates the map_array line by line
	while (++i < info->map_y)
	{
		j = 0;
		// If first line or last line
		if (i == 0 || i == info->map_y - 1)
			// iterates the line
			while (info->map_array[i][j] != '\0')
			{
				// if not 1 calls the function error with the appropriate msg
				if(info->map_array[i][j++] != '1')
					error(ERROR_MAP_BORDER, info);
			}
		// all the other lines
		else
		{
			// checks if the lines are all the same size by comparing with map_x saved from 1st line - map must be rectangle
			if((int)ft_strlen(info->map_array[i]) != info->map_x)
				error(ERROR_MAP_RECTANGLE, info);
			// first position and last position must be 1 - map must be closed by walls (1)
			else if (info->map_array[i][0] != '1' || info->map_array[i][info->map_x - 1] != '1')
				error(ERROR_MAP_BORDER, info);
			// loop to record the number of exits, players, collectibles
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
	// checks if there is atleast one of each asset
	if (info->collectibles == 0 || info->players == 0 || info->exits == 0)
		error(ERROR_MAP_ASSETS, info);
	return(1);
}

int handle_map(char *file, t_game *info)
{
	int fd;
	int i;
	char *line;

	i = 0;
	// open the access to .ber file and get fd value
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	// Allocate memory to store the map info according to the map selected. (1000 temporary -> find better size)
	info->map_array = malloc(sizeof(char *) * 1000);
	// we iterate the .ber file line by line and store its values (1, 0, P, E, C) on the array
	while (get_next_line(fd, &line))
	{
		// we define the map width/X from the first line (all lines width must be = )
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		// saves to the array
		info->map_array[i] = ft_strdup(line);
		i++;
		// map length/y
		info->map_y++;
		// free the memory allocated by GNL()
		free(line);
	}
	// free the memory allocated in the last iteration of GNL()
	free(line);
	// Function to check if the map follows the rules defined by subject
	validate_map(info);
	// close the access to .ber file
	close(fd);
	return(1);
}
