/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:34:51 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/18 10:45:19 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_exit(t_game *info)
{
	free_array(info);
	exit(0);
}

int	ft_close(int keycode, t_game *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
	return(0);
}

int	key_hook(int keycode, t_game *vars)
{
	printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 53)
		ft_close(keycode, vars);
	return(1);
}

static int	xpm_to_image_wrapper(t_game *game, t_data *image, char *filename)
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
		"./assets/ball.xpm");
	xpm_to_image_wrapper(info, &info->img_wall,
		"./assets/tile01.xpm");
	xpm_to_image_wrapper(info, &info->img_player,
		"./assets/loading0.xpm");
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

void	fill_first_map(t_game *game)
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
			if (game->map_array[column][row] == '0')
				asset = &game->img_floor;
			else if (game->map_array[column][row] == '1')
				asset = &game->img_wall;
			else if (game->map_array[column][row] == 'C')
				asset = &game->img_collectible;
			else if (game->map_array[column][row] == 'P')
				asset = &game->img_player;
			else
				asset = &game->img_exit;
			render_asset(game, asset, &coords);
		}
	}
}

int handle_window(t_game *game_info)
{
	game_info->mlx = mlx_init();
	game_info->window = mlx_new_window(game_info->mlx, game_info->map_x * ASSET_SIZE, game_info->map_y * ASSET_SIZE, "Game Window");
	if (!load_textures(game_info))
		error("", game_info);
	fill_first_map(game_info);
	//imgs to window

	if(!mlx_key_hook(game_info->window, key_hook, &game_info))
		free_exit(game_info);
	if(!mlx_hook(game_info->window, 17, 1L<<17, ft_close, &game_info))
		free_exit(game_info);
	return(1);
}
