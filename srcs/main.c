/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:17 by tribeiro          #+#    #+#             */
/*   Updated: 2021/11/10 11:57:17 by tribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
	t_vars vars;

	if(ac != 2)
		printf("Arguments Format Error\n");
	handle_map(av[1]);
/* 	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 600, 300, "Hello world!"); */
	printf("Hello World\n");

	/* mlx_loop(vars.mlx); */
	return(1);
}
