/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:44:07 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/05 15:42:44 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_up(t_map *map)
{
	if (map->full[map->pos_x - 1][map->pos_y] == '1')
		return (0);
	else if (map->full[map->pos_x - 1][map->pos_y] == 'E' && map->nbr_collec > 0
		&& map->full[map->pos_x - 2][map->pos_y] == '1')
		return (0);
	return (1);
}

int	can_down(t_map *map)
{
	if (map->full[map->pos_x + 1][map->pos_y] == '1')
		return (0);
	else if (map->full[map->pos_x + 1][map->pos_y] == 'E' && map->nbr_collec > 0
		&& map->full[map->pos_x + 2][map->pos_y] == '1')
		return (0);
	return (1);
}

int	can_left(t_map *map)
{
	if (map->full[map->pos_x][map->pos_y - 1] == '1')
		return (0);
	else if (map->full[map->pos_x][map->pos_y - 1] == 'E' && map->nbr_collec > 0
		&& map->full[map->pos_x][map->pos_y - 2] == '1')
		return (0);
	return (1);
}

int	can_right(t_map *map)
{
	if (map->full[map->pos_x][map->pos_y + 1] == '1')
		return (0);
	else if (map->full[map->pos_x][map->pos_y + 1] == 'E' && map->nbr_collec > 0
		&& map->full[map->pos_x][map->pos_y + 2] == '1')
		return (0);
	return (1);
}

void	moves_u(t_map *map, int direction)
{
	map->full[map->pos_x][map->pos_y] = '0';
	if (direction == 1)
	{
		map->full[map->pos_x - 1][map->pos_y] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x - 1, map->pos_y);
	}
	if (direction == 2)
	{
		map->full[map->pos_x + 1][map->pos_y] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x + 1, map->pos_y);
	}
	if (direction == 3)
	{
		map->full[map->pos_x][map->pos_y + 1] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x, map->pos_y + 1);
	}
	if (direction == 4)
	{
		map->full[map->pos_x][map->pos_y - 1] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x, map->pos_y - 1);
	}
}
