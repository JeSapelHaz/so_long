/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:27 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/04 15:56:21 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_map *map, void *mlx, void *window)
{
	int	i;
	int	j;

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
				display_collec(mlx, window, j, i);
			if (map->full[i][j] == 'P')
			{
				display_floor(mlx, window, j, i);
				display_player(mlx, window, j, i);
			}
			if (map->full[i][j] == 'E')
				display_exit(mlx, window, j, i);
		}
	}
}

void	refresh_display(t_map *map, int i, int j)
{
	if (map->full[i][j] == '1')
		display_wall(map->mlx, map->window, j, i);
	if (map->full[i][j] == '0' || map->full[i][j] == 'C')
		display_floor(map->mlx, map->window, j, i);
	if (map->full[i][j] == 'C')
		display_collec(map->mlx, map->window, j, i);
	if (map->full[i][j] == 'P')
	{
		display_floor(map->mlx, map->window, j, i);
		display_player(map->mlx, map->window, j, i);
	}
	if (map->full[i][j] == 'E')
		display_exit(map->mlx, map->window, j, i);
}

void	refresh_movements(t_map *map)
{
	display_wall(map->mlx, map->window, 0, 0);
	display_wall(map->mlx, map->window, 1, 0);
	display_wall(map->mlx, map->window, 2, 0);
	display_wall(map->mlx, map->window, 3, 0);
	display_wall(map->mlx, map->window, 4, 0);
}
