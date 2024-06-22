/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:53:59 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/22 19:04:59 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->full[map->pos_x - 1][map->pos_y] == 'C')
	{
		map->nbr_collec--;
	}
	map->full[map->pos_x][map->pos_y] = '0';
	map->full[map->pos_x - 1][map->pos_y] = 'P';
	display_map(map, map->mlx, map->window);
}
void	move_down(t_map *map)
{
	if (map->full[map->pos_x + 1][map->pos_y] == 'C')
	{
		map->nbr_collec--;
	}
	map->full[map->pos_x][map->pos_y] = '0';
	map->full[map->pos_x + 1][map->pos_y] = 'P';
	display_map(map, map->mlx, map->window);
}
void	move_right(t_map *map)
{
	if (map->full[map->pos_x][map->pos_y + 1] == 'C')
	{
		map->nbr_collec--;
	}
	map->full[map->pos_x][map->pos_y] = '0';
	map->full[map->pos_x][map->pos_y + 1] = 'P';
	display_map(map, map->mlx, map->window);
}
void	move_left(t_map *map)
{
	if (map->full[map->pos_x][map->pos_y - 1] == 'C')
	{
		map->nbr_collec--;
	}
	map->full[map->pos_x][map->pos_y] = '0';
	map->full[map->pos_x][map->pos_y - 1] = 'P';
	display_map(map, map->mlx, map->window);
}

int	controls(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		close_window(map);
	}
	if (keycode == 13 || keycode == 126)
	{
		if (can_up(map))
		{
			move_up(map);
		}
	}
	if (keycode == 2 || keycode == 124)
	{
		if (can_right(map))
		{
			move_right(map);
		}
	}
	if (keycode == 1 || keycode == 125)
	{
		if (can_down(map))
		{
			move_down(map);
		}
	}
	if (keycode == 0 || keycode == 123)
	{
		if (can_left(map))
		{
			move_left(map);
		}
	}
	return (0);
}