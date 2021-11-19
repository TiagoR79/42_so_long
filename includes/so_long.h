/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:26:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/19 13:09:02 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../includes/get_next_line.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define ASSET_SIZE 64

# define ERROR_MAP_BORDER "Map not surrounded by walls (1)\n"
# define ERROR_MAP_RECTANGLE "Map is not a rectangle\n"
# define ERROR_MAP_EXITS "There must be atleast one Exit\n"
# define ERROR_MAP_PLAYERS "There must be atleast one Player\n"
# define ERROR_MAP_COLLECTIBLES "There must be atleast one Collectible\n"

typedef struct s_map_coords {
	int	x;
	int	y;
}				t_map_coords;

typedef struct s_player_coords {
	int	column;
	int	row;
}				t_player_coords;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}				t_data;

typedef struct	s_game
{
	void 			*mlx;
    void 			*window;
	int 			map_x;
	int 			map_y;
	char 			**map_array;
	int 			exits;
	int 			players;
	int 			collectibles;
	t_player_coords player_position;
	t_data			img_floor;
	t_data			img_wall;
	t_data			img_player;
	t_data			img_collectible;
	t_data			img_exit;
}				t_game;


int free_array(t_game *game_info);

int error(char *type, t_game *info);
int handle_map(char *file, t_game *info);
int handle_window(t_game *game_info);

int	ft_close(int keycode, t_game *vars);
int	key_hook(int keycode, t_game *vars);
static int	xpm_to_image_wrapper(t_game *game, t_data *image, char *filename);
int	load_textures(t_game *info);
void	render_asset(t_game *game, t_data *asset, t_map_coords *coords);
void	get_map_coordinates(int x, int y, t_map_coords *coords);
void	render_map(t_game *game);

int	key_hook(int keycode, t_game *vars);


#endif
