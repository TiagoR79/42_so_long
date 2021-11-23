/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:34:51 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/23 10:45:38 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(int keycode, t_game *vars)
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

int	xpm_to_image_wrapper(t_game *game, t_data *image, char *filename)
{
	image->img = mlx_xpm_file_to_image(game->mlx,
			filename, &image->img_width, &image->img_height);
	if (!image->img)
		return (0);
	return (1);
}

int	load_textures(t_game *info)
{
	xpm_to_image_wrapper(info, &info->img_floor,
		"./assets/tile00.xpm");
	xpm_to_image_wrapper(info, &info->img_exit,
		"./assets/ladder.xpm");
	xpm_to_image_wrapper(info, &info->img_collectible,
		"./assets/ball_new.xpm");
	xpm_to_image_wrapper(info, &info->img_wall,
		"./assets/tile01.xpm");
	xpm_to_image_wrapper(info, &info->img_player,
		"./assets/player_W.xpm");
	if (!info->img_floor.img || !info->img_exit.img
		|| !info->img_collectible.img || !info->img_wall.img
		|| !info->img_player.img)
		return (0);
	return (1);
}

void	render_asset(t_game *game, t_data *asset, t_map_coords *coords)
{
	mlx_put_image_to_window(game->mlx, game->window,
		asset->img, coords->x, coords->y);
}

void	get_map_coordinates(int x, int y, t_map_coords *coords)
{
	coords->x = ASSET_SIZE * x;
	coords->y = ASSET_SIZE * y;
}

void	render_map(t_game *game)
{
	int				row;
	int				column;
	t_map_coords	coords;
	t_data			*asset;

	column = -1;
	while (++column < game->map_y)
	{
		row = -1;
		while (++row < game->map_x)
		{
			get_map_coordinates(row, column, &coords);
			if (game->map_array[column][row] == 'P')
			{
				asset = &game->img_player;
				game->player_position.column = column;
				game->player_position.row = row;
			}
			else if (game->map_array[column][row] == '0')
				asset = &game->img_floor;
			else if (game->map_array[column][row] == '1')
				asset = &game->img_wall;
			else if (game->map_array[column][row] == 'C')
				asset = &game->img_collectible;
			else
				asset = &game->img_exit;
			render_asset(game, asset, &coords);
		}
	}
	/* printf("DEBUG:  %d\n", game->player_position.row);
	printf("DEBUG:  %d\n", game->player_position.column); */
}

int handle_window(t_game *game_info)
{
	game_info->mlx = mlx_init();
	game_info->window = mlx_new_window(game_info->mlx, game_info->map_x * ASSET_SIZE, game_info->map_y * ASSET_SIZE, "Game Window");
	if (!load_textures(game_info))
		error("Failed to Load Assets\n", game_info);
	render_map(game_info);
		//free_exit(game_info);
	return(1);
}
