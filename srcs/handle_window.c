/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:34:51 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/17 11:01:38 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_exit(t_game *info)
{
	free_array(info);
	exit(0);
}

int	ft_close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
	return(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		ft_close(keycode, vars);
	return(1);
}

int handle_window(t_game *game_info, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window = mlx_new_window(vars->mlx, game_info->map_x * ASSET_SIZE, game_info->map_y * ASSET_SIZE, "Game Window");

	//imgs to window

	if(!mlx_key_hook(vars->window, key_hook, &vars))
		free_exit(game_info);
	if(!mlx_hook(vars->window, 17, 1L<<17, ft_close, &vars))
		free_exit(game_info);
	return(1);
}
