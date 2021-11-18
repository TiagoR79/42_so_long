/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/18 10:10:23 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* static */ void	init_game_info(t_game *info)
{
	info->map_y = 0;
	info->exits = 0;
	info->players = 0;
	info->collectibles = 0;
}

int free_array(t_game *game_info)
{
	int i;

	i = 0;
	while(i < game_info->map_y)
		free(game_info->map_array[i++]);
	free(game_info->map_array);
}

int main(int ac, char **av)
{
	t_vars vars;
	t_game game_info;

	if(ac != 2)
		printf("Arguments Format Error\n");
	init_game_info(&game_info);
	handle_map(av[1], &game_info);
	handle_window(&game_info, &vars);
	mlx_loop(vars.mlx);
	free_array(&game_info);
	return(1);
}
