/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:11:43 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/01 14:11:05 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Taille de chaque case en pixels

int	main(int ac, char **av)
{
	t_map	map;

	check_args(ac, av);
	map.name = av[1];
	map = read_map(map);
	map = init_map(map);
	info_map(&map);
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx, TILE_SIZE * map.columns, TILE_SIZE
			* map.lines, "so_long");
	display_map(&map, map.mlx, map.window);
	mlx_key_hook(map.window, controls, &map);
	mlx_hook(map.window, 17, 0, (void *)exit, 0);
	mlx_loop(map.mlx);
	return (0);
}
