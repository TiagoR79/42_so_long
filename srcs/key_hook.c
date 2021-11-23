/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:47:47 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/23 10:46:20 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *vars)
{
	int column;
	int row;
	//t_map_coords coords;
	t_data *asset;

	column 	= vars->player_position.column;
	row 	= vars->player_position.row;
	//printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		ft_close(keycode, vars);
	// W key
	if (keycode == 13 || keycode == 126 || keycode == 119)
	{
		//get_map_coordinates(row, column, &coords);
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_W.xpm");
		render_map(vars);
		if(vars->map_array[column - 1][row] == '1')
			return(1);
		if(vars->map_array[column - 1][row] == 'C')
		{
			vars->map_array[column][row] = '0';
			vars->map_array[column - 1][row] = 'P';
			vars->collectibles--;
		}
		if(vars->map_array[column - 1][row] == '0')
		{
			vars->map_array[column - 1][row] = 'P';
			vars->map_array[column][row] = '0';
		}
		if(vars->map_array[column - 1][row] == 'E')
			if(vars->collectibles > 0)
				return(1);
			else
				vars->map_array[column][row] = '0';
				//render end screen??
		render_map(vars);
	}
	// S key
	if (keycode == 1 || keycode == 125 || keycode == 115)
	{
		//get_map_coordinates(row, column, &coords);
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_S.xpm");
		render_map(vars);
		if(vars->map_array[column + 1][row] == '1')
			return(1);
		if(vars->map_array[column + 1][row] == 'C')
		{
			vars->map_array[column + 1][row] = 'P';
			vars->map_array[column][row] = '0';
			vars->collectibles--;
		}
		if(vars->map_array[column + 1][row] == '0')
		{
			vars->map_array[column + 1][row] = 'P';
			vars->map_array[column][row] = '0';
		}
		if(vars->map_array[column + 1][row] == 'E')
			if(vars->collectibles > 0)
				return(1);
			else
				vars->map_array[column][row] = '0';
				//render end screen??
		render_map(vars);
	}
	// D key
	if (keycode == 2 || keycode == 124 || keycode == 100)
	{
		//get_map_coordinates(row, column, &coords);
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_D.xpm");
		render_map(vars);
		if(vars->map_array[column][row + 1] == '1')
			return(1);
		if(vars->map_array[column][row + 1] == 'C')
		{
			vars->map_array[column][row + 1] = 'P';
			vars->map_array[column][row] = '0';
			vars->collectibles--;
		}
		if(vars->map_array[column][row + 1] == '0')
		{
			vars->map_array[column][row + 1] = 'P';
			vars->map_array[column][row] = '0';
		}
		if(vars->map_array[column][row + 1] == 'E')
			if(vars->collectibles > 0)
				return(1);
			else
				vars->map_array[column][row] = '0';
				//render end screen??
		render_map(vars);
	}
	// A key
	if (keycode == 0 || keycode == 123 || keycode == 97)
	{
		//get_map_coordinates(row, column, &coords);
		xpm_to_image_wrapper(vars, &vars->img_player, "./assets/player_A.xpm");
		render_map(vars);
		if(vars->map_array[column][row - 1] == '1')
			return(1);
		if(vars->map_array[column][row - 1] == 'C')
		{
			vars->map_array[column][row - 1] = 'P';
			vars->map_array[column][row] = '0';
			vars->collectibles--;
		}
		if(vars->map_array[column][row - 1] == '0')
		{
			vars->map_array[column][row - 1] = 'P';
			vars->map_array[column][row] = '0';
		}
		if(vars->map_array[column][row - 1] == 'E')
			if(vars->collectibles > 0)
				return(1);
			else
				vars->map_array[column][row] = '0';
				//render end screen??
		render_map(vars);
	}
	return(1);
}
