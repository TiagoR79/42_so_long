/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/11 11:25:04 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int validate_line(char *map)
{
	int i;

	i = 0;
	return(i);
}


int handle_map(char *file, t_game *info)
{
	int fd;
	int buffer_size;
	char *line;


	fd = open(file, O_RDONLY);
	//read(fd, map, 4096);
		// need map length and height --> struct
	while (get_next_line(fd, &line))
	{
		if (info->map_y == 0)
			info->map_x = ft_strlen(line);
		printf("maplength is: %d\n", info->map_x);
		printf("map is:\n%s\n", line);
		// find last line
	}
	free(line);

	//validate_map(map);

	return(1);
}
