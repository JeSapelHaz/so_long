/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:44:07 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/01 12:14:43 by hbutt            ###   ########.fr       */
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
