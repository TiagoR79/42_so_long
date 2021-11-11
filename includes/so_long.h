/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:26:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/11 11:23:44 by tribeiro         ###   ########.fr       */
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
}				t_game;


int handle_map(char *file, t_game *info);

#endif
