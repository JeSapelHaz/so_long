/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:45:01 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/05 15:56:01 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_images(t_map *map)
{
	int		img_height;
	void	*img_win;

	img_height = TILE_SIZE;
	img_win = mlx_xpm_file_to_image(map->mlx, "images/YOU_WIN.xpm",
			&img_height, &img_height);
	mlx_put_image_to_window(map->mlx, map->window, img_win, 150, 0);
	img_win = mlx_xpm_file_to_image(map->mlx, "images/ajit_victory.xpm",
			&img_height, &img_height);
	mlx_put_image_to_window(map->mlx, map->window, img_win, 10, 10);
	img_win = mlx_xpm_file_to_image(map->mlx, "images/mathias_victory.xpm",
			&img_height, &img_height);
	mlx_put_image_to_window(map->mlx, map->window, img_win, 400, 10);
	
}
void	ft_you_win(t_map *map)
{
	int		img_height;
	int		i;
	int		j;
	void	*img_wall;

	i = 0;
	img_height = TILE_SIZE;
	map->win = 1;
	img_wall = mlx_xpm_file_to_image(map->mlx, "images/noir.xpm", &img_height,
			&img_height);
	map->win = 1;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			mlx_put_image_to_window(map->mlx, map->window, img_wall, j
				* TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	put_images(map);
}
