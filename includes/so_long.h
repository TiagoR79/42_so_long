/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:26:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/12/15 11:49:05 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/get_next_line.h"
# include "../libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// Asset size defaulted to 64 -> .xpm files must be 64x64 pixels (not confirmed in code -> to do)
# define ASSET_SIZE 64

// Define the messages for error types
# define ERROR_MAP_BORDER "Map not surrounded by walls (1)\n"
# define ERROR_MAP_FILE "Map file not valid\n"
# define ERROR_MAP_RECTANGLE "Map is not a rectangle\n"
# define ERROR_MAP_ASSETS "There is atleast one type of asset missing, check the map before submiting\n"
/*
# define ERROR_MAP_EXITS "There must be atleast one Exit\n"
# define ERROR_MAP_PLAYERS "There must be atleast one Player\n"
# define ERROR_MAP_COLLECTIBLES "There must be atleast one Collectible\n"
 */
// map coordinates to render the different sprites
typedef struct s_map_coords {
	int	x;
	int	y;
}				t_map_coords;

// records the live coordinates of the player sprite
typedef struct s_player_coords {
	int	column;
	int	row;
}				t_player_coords;

// Data to create a image using mlx
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}				t_data;

// all the info needed to create/run the game
typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				map_x;
	int				map_y;
	char			**map_array;
	int				exits;
	int				players;
	int				collectibles;
	int				moves;
	t_player_coords	player_position;
	t_data			img_floor;
	t_data			img_wall;
	t_data			img_player;
	t_data			img_collectible;
	t_data			img_exit;
}				t_game;

// frees the memory allocated to creating the map array
int		free_array(t_game *game_info);

// handles the different types of errors
int		error(char *type, t_game *info);

int		handle_map(char *file, t_game *info);
int		handle_window(t_game *game_info);

// Function to terminate the game and close window by freeing the array using free_array() and mlx_destroy_image() and mlx_destroy_windows()
int		ft_close(t_game *vars);
// Function to handle key presses
int		key_hook(int keycode, t_game *vars);
// Custom function to create the different mlx images from the custom sprites (ex. player.xpm) using mlx_xpm_file_to_image()
int		xpm_to_image_wrapper(t_game *game, t_data *image, char *filename);
// Loads the chosen sprites to the correspondent asset (ex. player, wall, floor, ...) in game using xpm_to_image_wrapper()
int		load_textures(t_game *info);
// Renders the asset to the window using mlx_put_image_to_window()
void	render_asset(t_game *game, t_data *asset, t_map_coords *coords);
// Defines where to render and size by ASSET_SIZE * x and ASSET_SIZE * y
void	get_map_coordinates(int x, int y, t_map_coords *coords);
// Renders the map based on the chosen .ber file uses rener_asset()
void	render_map(t_game *game);

#endif
