/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:47:47 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/19 14:59:51 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *vars)
{
	int column;
	int row;
	t_data coords;
	t_data *asset;

	column = vars->player_position.column;
	row = vars->player_position.row;
	//printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		ft_close(keycode, vars);
	// W key
	if (keycode == 13 || keycode == 126)
	{
		get_map_coordinates(row, column, &coords);
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
	if (keycode == 1 || keycode == 125)
	{
		get_map_coordinates(row, column, &coords);
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
	if (keycode == 2 || keycode == 124)
	{
		get_map_coordinates(row, column, &coords);
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
	if (keycode == 0 || keycode == 123)
	{
		get_map_coordinates(row, column, &coords);
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
