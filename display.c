/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:27 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/21 16:58:15 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_map map, void *mlx, void *window)
{
	void *img_wall;
	void *img_floor;
	void *img_player;
	void *img_collec;
	void *img_exit;
	int i;
	int j;
	int img_height;

	img_height = TILE_SIZE;

	i = 0;
	img_wall = mlx_xpm_file_to_image(mlx, "images/crate.xpm", &img_height, &img_height);
	img_floor = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &img_height, &img_height);
	img_player = mlx_xpm_file_to_image(mlx, "images/bee.xpm", &img_height, &img_height);
	img_collec = mlx_xpm_file_to_image(mlx, "images/Honey.xpm", &img_height, &img_height);
	img_exit = mlx_xpm_file_to_image(mlx, "images/beehive.xpm", &img_height, &img_height);

	while (i < map.lines)
	{
		j = 0;
		while (j < map.columns)
		{
			if (map.full[i][j] == '1')
			{
				mlx_put_image_to_window(mlx, window, img_wall, j * TILE_SIZE, i
					* TILE_SIZE);
			}
			if (map.full[i][j] == '0')
			{
				mlx_put_image_to_window(mlx, window, img_floor, j * TILE_SIZE, i
					* TILE_SIZE);
			}
			if (map.full[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx, window, img_collec, j * TILE_SIZE, i
					* TILE_SIZE);
			}
			if (map.full[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx, window, img_player, j * TILE_SIZE, i
					* TILE_SIZE);
			}
			if (map.full[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx, window, img_exit, j * TILE_SIZE, i
					* TILE_SIZE);
			}
			j++;
		}
		i++;
	}
}