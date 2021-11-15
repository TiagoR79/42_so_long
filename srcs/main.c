/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/15 16:22:52 by tribeiro         ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_vars vars;
	t_game game_info;

	if(ac != 2)
		printf("Arguments Format Error\n");
	init_game_info(&game_info);
	handle_map(av[1], &game_info);
/* 	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 600, 300, "Hello world!"); */

	/* mlx_loop(vars.mlx); */

	free(game_info.map_array[0]);
	free(game_info.map_array[1]);
	free(game_info.map_array[2]);
	free(game_info.map_array[3]);
	free(game_info.map_array[4]);
	free(game_info.map_array);
	return(1);
}
