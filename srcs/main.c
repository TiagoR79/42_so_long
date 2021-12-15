/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/12/15 14:38:10 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_info(t_game *vars)
{
	vars->map_y = 0;
	vars->exits = 0;
	vars->players = 0;
	vars->collectibles = 0;
	vars->player_position.row = 0;
	vars->player_position.column = 0;
	vars->moves = 1;
}

int	free_array(t_game *game_info)
{
	int	i;

	i = 0;
	while (i < game_info->map_y)
		free(game_info->map_array[i++]);
	free(game_info->map_array);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game_info;

	if (ac != 2)
		printf("Arguments Format Error\n");
	init_game_info(&game_info);
	handle_map(av[1], &game_info);
	handle_window(&game_info);
	mlx_key_hook(game_info.window, key_hook, &game_info);
	mlx_hook(game_info.window, 17, 1L, ft_close, &game_info);
	mlx_loop(game_info.mlx);
	return (1);
}
