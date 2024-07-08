/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:34:41 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/06 16:27:23 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_wall(void *mlx, void *window, int j, int i)
{
	int		img_height;
	void	*img_wall;

	img_height = TILE_SIZE;
	img_wall = mlx_xpm_file_to_image(mlx, "images/wall_2.xpm", &img_height,
			&img_height);
	mlx_put_image_to_window(mlx, window, img_wall, j * TILE_SIZE, i
		* TILE_SIZE);
}

void	display_floor(void *mlx, void *window, int j, int i)
{
	int		img_height;
	void	*img_floor;

	img_height = TILE_SIZE;
	img_floor = mlx_xpm_file_to_image(mlx, "images/floor_2.xpm", &img_height,
			&img_height);
	mlx_put_image_to_window(mlx, window, img_floor, j * TILE_SIZE, i
		* TILE_SIZE);
}

void	display_collec(void *mlx, void *window, int j, int i)
{
	int		img_height;
	void	*img_collec;

	img_height = TILE_SIZE;
	img_height /= 7;
	img_collec = mlx_xpm_file_to_image(mlx, "images/apple.xpm", &img_height,
			&img_height);
	mlx_put_image_to_window(mlx, window, img_collec, j * TILE_SIZE, i
		* TILE_SIZE);
}

void	display_player(void *mlx, void *window, int j, int i)
{
	int		img_height;
	void	*img_player;

	img_height = TILE_SIZE;
	img_player = mlx_xpm_file_to_image(mlx, "images/player.xpm", &img_height,
			&img_height);
	mlx_put_image_to_window(mlx, window, img_player, j * TILE_SIZE, i
		* TILE_SIZE);
}

void	display_exit(void *mlx, void *window, int j, int i)
{
	int		img_height;
	void	*img_exit;

	img_height = TILE_SIZE;
	img_exit = mlx_xpm_file_to_image(mlx, "images/exit.xpm", &img_height,
			&img_height);
	mlx_put_image_to_window(mlx, window, img_exit, j * TILE_SIZE, i
		* TILE_SIZE);
}
