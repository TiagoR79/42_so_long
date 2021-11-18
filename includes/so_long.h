/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:26:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/17 10:48:42 by tribeiro         ###   ########.fr       */
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


typedef struct  s_vars {
    void *mlx;
    void *window;
}               t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game
{
	int map_x;
	int map_y;
	char **map_array;
	int exits;
	int players;
	int collectibles;
}				t_game;


int free_array(t_game *game_info);

int error(char *type, t_game *info);
int handle_map(char *file, t_game *info);
int handle_window(t_game *game_info, t_vars *vars);

#endif
