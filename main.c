/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:11:43 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/21 16:47:04 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 // Taille de chaque case en pixels

int	main(int ac, char **av)
{
	t_map	map;
	void	*mlx;
	void	*window;

	check_args(ac, av);
	map.name = av[1];
	map = read_map(map);
	map = init_map(map);
	mlx = mlx_init();
	mlx = mlx_init();
	window = mlx_new_window(mlx, TILE_SIZE * map.columns, TILE_SIZE * map.lines, "so_long");
	display_map(map, mlx, window);
	mlx_loop(mlx);
	// i = 0;
	// while (map.full[i])
	// {
	// 	printf("%s", map.full[i]);
	// 	i++;
	// }
	return (0);
}
