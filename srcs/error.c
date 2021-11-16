/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:13:05 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/16 11:42:38 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int error(char *type, t_game *info)
{
	int i;

	i = 0;
	printf("\nError\n");
	printf("\n%s\n", type);
	while(i < info->map_y)
		free(info->map_array[i++]);
	free(info->map_array);
	exit(0);
}
