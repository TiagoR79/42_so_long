/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/12 15:02:05 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int validate_line(char *line, t_game *info)
{
	int j;

	printf("iteration n: %d\n", info->map_y);
	//printf("X: %d\n", info->map_x);
	j = 0;
	if (info->map_y == 0)
	{
		while (line[j] != '\0')
		{
			if(line[j] != '1')
				return(0);
			j++;
		}
	}
	if (info->map_y > 0)
	{
		//printf("DEBUG:\tstrlen map : %d\n", (int)ft_strlen(map));
		//printf("DEBUG:\tmap_x : %d\n", info->map_x);
		if((int)ft_strlen(line) != info->map_x)
			return(0);
		else if (line[0] != '1' || line[info->map_x - 1] != '1')
			return(0);
		while (line[j] != '\0')
		{
			if(line[j] == 'E' || line[j] == 'e')
				info->exits += 1;
			if(line[j] == 'P' || line[j] == 'p')
				info->players += 1;
			if(line[j] == 'C' || line[j] == 'c')
				info->collectibles += 1;
			j++;
		}
		//printf("DEBUG:\tthis is :%c\n", map[info->map_x - 1]);
	}
	return(1);
}

/* int	form_matrix(char *line, t_game *info)
{
	size_t		count;
	int		i;
	char	**lines;

	count = (size_t)info->map_y + 1;
	lines = ft_calloc(count, sizeof(char **));
	if (!lines)
		return (-1);
	i = -1;
	while (++i < info->map_y)
		lines[i] = info->map_array[i];
	lines[i] = line;
	if (info->map_array)
		free(info->map_array);
	info->map_array = lines;
	info->map_y++;
	return (1);
} */

int handle_map(char *file, t_game *info)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
		// need map length and height --> struct
	while (get_next_line(fd, &line))
	{
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		if(!validate_line(line, info))
		{
			printf("MAP ERROR\n");
			free(line);
			exit (0);
		}
		//form_matrix(line, info);
		info->map_y++;
		printf("Debug:\t%s\n", line);
		printf("Debug:\tmap_y: %d\n", info->map_y);
		// find last line
	}
	printf("Debug:\tn of exits: %d\n", info->exits);
	printf("Debug:\tn of players: %d\n", info->players);
	printf("Debug:\tn of collectibles: %d\n", info->collectibles);

	free(line);

	return(1);
}

		//printf("maplength is: %d\n", info->map_x);
