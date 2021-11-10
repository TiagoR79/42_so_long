/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:18 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/10 15:03:46 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int validate_map(char *map)
{
	int i;

	i = 0;
	return(i);
}

int handle_map(char *file)
{
	int fd;
	int buffer_size;
	char *map;
	int ret;

	buffer_size = 4096;
	fd = open(file, O_RDONLY);
	printf("Map fd is: %d\n", fd);
	map = malloc(sizeof(char) * buffer_size);
	read(fd, map, 4096);
	printf("read:\n%s\n", map);


	validate_map(map);

	return(1);
}
