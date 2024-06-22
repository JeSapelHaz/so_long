/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:27 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/22 19:38:03 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_map *map, void *mlx, void *window)
{
	int i;
	int j;

	i = -1;
	while (++i < map->lines)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->full[i][j] == '1')
				display_wall(mlx, window, j, i);
			if (map->full[i][j] == '0' || map->full[i][j] == 'C')
				display_floor(mlx, window, j, i);
			if (map->full[i][j] == 'C')
			{
				display_collec(mlx, window, j, i);
				map->nbr_collec++;
			}
			if (map->full[i][j] == 'P')
			{
				display_floor(mlx, window, j, i);
				display_player(mlx, window, j, i);
				map->pos_x = i;
				map->pos_y = j;
			}
			if (map->full[i][j] == 'E')
				display_exit(mlx, window, j, i);
		}
	}
}