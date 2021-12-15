/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:47:47 by tribeiro          #+#    #+#             */
/*   Updated: 2021/12/15 14:37:27 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(t_game *vars)
{
	free_array(vars);
	mlx_destroy_image(vars->mlx, vars->img_floor.img);
	mlx_destroy_image(vars->mlx, vars->img_player.img);
	mlx_destroy_image(vars->mlx, vars->img_collectible.img);
	mlx_destroy_image(vars->mlx, vars->img_exit.img);
	mlx_destroy_image(vars->mlx, vars->img_wall.img);
	mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
	return (1);
}

int	key_hook(int keycode, t_game *vars)
{
	int	column;
	int	row;

	column = vars->player_position.column;
	row = vars->player_position.row;
	if (keycode == 65307 || keycode == 53)
		ft_close(vars);
	if (keycode == 13 || keycode == 126 || keycode == 119 || keycode == 65362)
	{
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_W.xpm");
		render_map(vars);
		if (vars->map_array[column - 1][row] == '1')
			return (1);
		if (vars->map_array[column - 1][row] == 'C')
		{
			vars->map_array[column][row] = '0';
			vars->map_array[column - 1][row] = 'P';
			vars->collectibles--;
		}
		if (vars->map_array[column - 1][row] == '0')
		{
			vars->map_array[column - 1][row] = 'P';
			vars->map_array[column][row] = '0';
		}
		if (vars->map_array[column - 1][row] == 'E')
		{
			if (vars->collectibles > 0)
				return (1);
			else
			{
				vars->map_array[column][row] = '0';
				error(END_GAME, vars, 0);
			}
		}
		render_map(vars);
	}
	if (keycode == 1 || keycode == 125 || keycode == 115 || keycode == 65364)
	{
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_S.xpm");
		render_map(vars);
		if (vars->map_array[column + 1][row] == '1')
			return (1);
		if (vars->map_array[column + 1][row] == 'C')
		{
			vars->map_array[column + 1][row] = 'P';
			vars->map_array[column][row] = '0';
			vars->collectibles--;
		}
		if (vars->map_array[column + 1][row] == '0')
		{
			vars->map_array[column + 1][row] = 'P';
			vars->map_array[column][row] = '0';
		}
		if (vars->map_array[column + 1][row] == 'E')
		{
			if (vars->collectibles > 0)
				return (1);
			else
			{
				vars->map_array[column][row] = '0';
				error(END_GAME, vars, 0);
			}
		}
		render_map(vars);
	}
	if (keycode == 2 || keycode == 124 || keycode == 100 || keycode == 65363)
	{
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_D.xpm");
		render_map(vars);
		if (vars->map_array[column][row + 1] == '1')
			return (1);
		if (vars->map_array[column][row + 1] == 'C')
		{
			vars->map_array[column][row + 1] = 'P';
			vars->map_array[column][row] = '0';
			vars->collectibles--;
		}
		if (vars->map_array[column][row + 1] == '0')
		{
			vars->map_array[column][row + 1] = 'P';
			vars->map_array[column][row] = '0';
		}
		if (vars->map_array[column][row + 1] == 'E')
		{
			if (vars->collectibles > 0)
				return (1);
			else
			{
				vars->map_array[column][row] = '0';
				error(END_GAME, vars, 0);
			}
		}
		render_map(vars);
	}
	if (keycode == 0 || keycode == 123 || keycode == 97 || keycode == 65361)
	{
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_A.xpm");
		render_map(vars);
		if (vars->map_array[column][row - 1] == '1')
			return (1);
		if (vars->map_array[column][row - 1] == 'C')
		{
			vars->map_array[column][row - 1] = 'P';
			vars->map_array[column][row] = '0';
			vars->collectibles--;
		}
		if (vars->map_array[column][row - 1] == '0')
		{
			vars->map_array[column][row - 1] = 'P';
			vars->map_array[column][row] = '0';
		}
		if (vars->map_array[column][row - 1] == 'E')
		{
			if (vars->collectibles > 0)
				return (1);
		else
			{
				vars->map_array[column][row] = '0';
				error(END_GAME, vars, 0);
			}
		}
		render_map(vars);
	}
	++vars->moves;
	return (1);
}
