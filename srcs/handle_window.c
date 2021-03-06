/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:34:51 by tribeiro          #+#    #+#             */
/*   Updated: 2021/12/13 12:10:47 by tribeiro         ###   ########.fr       */
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
	return(1);
}

void	render_asset(t_game *vars, t_data *asset, t_map_coords *coords)
{
	mlx_put_image_to_window(vars->mlx, vars->window,
		asset->img, coords->x, coords->y);
}

void	get_map_coordinates(int x, int y, t_map_coords *coords)
{
	coords->x = ASSET_SIZE * x;
	coords->y = ASSET_SIZE * y;
}

void	render_map(t_game *vars)
{
	int				row;
	int				column;
	t_map_coords	coords;
	t_data			*asset;

	column = -1;
	while (++column < vars->map_y)
	{
		row = -1;
		while (++row < vars->map_x)
		{
			get_map_coordinates(row, column, &coords);
			if (vars->map_array[column][row] == 'P')
			{
				asset = &vars->img_player;
				vars->player_position.column = column;
				vars->player_position.row = row;
			}
			else if (vars->map_array[column][row] == '0')
				asset = &vars->img_floor;
			else if (vars->map_array[column][row] == '1')
				asset = &vars->img_wall;
			else if (vars->map_array[column][row] == 'C')
				asset = &vars->img_collectible;
			else
				asset = &vars->img_exit;
			render_asset(vars, asset, &coords);
		}
	}
	/* printf("DEBUG:  %d\n", game->player_position.row);
	printf("DEBUG:  %d\n", game->player_position.column); */
}

// Custom function to create the different mlx images from the custom sprites (ex. player.xpm) using mlx_xpm_file_to_image()
int	xpm_to_image_wrapper(t_game *vars, t_data *image, char *filename)
{
	image->img = mlx_xpm_file_to_image(vars->mlx,
			filename, &image->img_width, &image->img_height);
	if (!image->img)
		return (0);
	return (1);
}

int	load_textures(t_game *vars)
{
	xpm_to_image_wrapper(vars, &vars->img_floor,
		"./assets/tile00.xpm");
	xpm_to_image_wrapper(vars, &vars->img_exit,
		"./assets/ladder.xpm");
	xpm_to_image_wrapper(vars, &vars->img_collectible,
		"./assets/ball_new.xpm");
	xpm_to_image_wrapper(vars, &vars->img_wall,
		"./assets/tile01.xpm");
	xpm_to_image_wrapper(vars, &vars->img_player,
		"./assets/player_W.xpm");
	if (!vars->img_floor.img || !vars->img_exit.img
		|| !vars->img_collectible.img || !vars->img_wall.img
		|| !vars->img_player.img)
		return (0);
	return (1);
}

int handle_window(t_game *game_vars)
{
	// inits the mlx variables
	game_vars->mlx = mlx_init();
	// creates a window with the appropriate size
	game_vars->window = mlx_new_window(game_vars->mlx, game_vars->map_x * ASSET_SIZE, game_vars->map_y * ASSET_SIZE, "Game Window");
	// Loads the chosen sprites to the correspondent asset (ex. player, wall, floor, ...) in game using xpm_to_image_wrapper()
	load_textures(game_vars);
	render_map(game_vars);
	return(1);
}
