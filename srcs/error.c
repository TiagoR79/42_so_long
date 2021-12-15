/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:13:05 by tribeiro          #+#    #+#             */
/*   Updated: 2021/12/15 14:35:20 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(char *type, t_game *info, int is_error)
{
	int	i;

	i = 0;
	if (is_error == 0)
	{
		printf("\n\t%s\n", type);
		printf("\tMoves made: ");
		printf("%d\n\n", info->moves);
	}
	else
	{
		printf("\nError: \n");
		printf("\n\t%s\n", type);
	}
	while (i < info->map_y)
		free(info->map_array[i++]);
	free(info->map_array);
	exit(0);
}
