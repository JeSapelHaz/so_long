/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:53:59 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/06 16:39:59 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	char	move_str[50];

	refresh_movements(map);
	map->moves++;
	sprintf(move_str, "Nombre de mouvements : %d", map->moves);
	mlx_string_put(map->mlx, map->window, 10, 10, 0xFFFFFF, move_str);
	if (map->full[map->pos_x - 1][map->pos_y] == 'C')
		map->nbr_collec--;
	if (map->full[map->pos_x - 1][map->pos_y] == 'E' && map->nbr_collec == 0)
	{
		ft_you_win(map);
		return ;
	}
	if (map->full[map->pos_x - 1][map->pos_y] == 'E' && map->nbr_collec > 0)
	{
		map->full[map->pos_x][map->pos_y] = '0';
		map->full[map->pos_x - 2][map->pos_y] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x - 2, map->pos_y);
		map->pos_x = map->pos_x - 2;
		return ;
	}
	moves_u(map, 1);
	map->pos_x--;
}

void	move_down(t_map *map)
{
	char	move_str[50];

	refresh_movements(map);
	map->moves++;
	sprintf(move_str, "Nombre de mouvements : %d", map->moves);
	mlx_string_put(map->mlx, map->window, 10, 10, 0xFFFFFF, move_str);
	if (map->full[map->pos_x + 1][map->pos_y] == 'C')
		map->nbr_collec--;
	if (map->full[map->pos_x + 1][map->pos_y] == 'E' && map->nbr_collec == 0)
	{
		ft_you_win(map);
		return ;
	}
	if (map->full[map->pos_x + 1][map->pos_y] == 'E' && map->nbr_collec > 0)
	{
		map->full[map->pos_x][map->pos_y] = '0';
		map->full[map->pos_x + 2][map->pos_y] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x + 2, map->pos_y);
		map->pos_x = map->pos_x + 2;
		return ;
	}
	moves_u(map, 2);
	map->pos_x++;
}

void	move_right(t_map *map)
{
	char	move_str[50];

	refresh_movements(map);
	map->moves++;
	sprintf(move_str, "Nombre de mouvements : %d", map->moves);
	mlx_string_put(map->mlx, map->window, 10, 10, 0xFFFFFF, move_str);
	if (map->full[map->pos_x][map->pos_y + 1] == 'C')
		map->nbr_collec--;
	if (map->full[map->pos_x][map->pos_y + 1] == 'E' && map->nbr_collec == 0)
	{
		ft_you_win(map);
		return ;
	}
	if (map->full[map->pos_x][map->pos_y + 1] == 'E' && map->nbr_collec > 0)
	{
		map->full[map->pos_x][map->pos_y] = '0';
		map->full[map->pos_x][map->pos_y + 2] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x, map->pos_y + 2);
		map->pos_y = map->pos_y + 2;
		return ;
	}
	moves_u(map, 3);
	map->pos_y++;
}

void	move_left(t_map *map)
{
	char	move_str[50];

	refresh_movements(map);
	map->moves++;
	sprintf(move_str, "Nombre de mouvements : %d", map->moves);
	mlx_string_put(map->mlx, map->window, 10, 10, 0xFFFFFF, move_str);
	if (map->full[map->pos_x][map->pos_y - 1] == 'C')
		map->nbr_collec--;
	if (map->full[map->pos_x][map->pos_y - 1] == 'E' && map->nbr_collec == 0)
	{
		ft_you_win(map);
		return ;
	}
	if (map->full[map->pos_x][map->pos_y - 1] == 'E' && map->nbr_collec > 0)
	{
		map->full[map->pos_x][map->pos_y] = '0';
		map->full[map->pos_x][map->pos_y - 2] = 'P';
		refresh_display(map, map->pos_x, map->pos_y);
		refresh_display(map, map->pos_x, map->pos_y - 2);
		map->pos_y = map->pos_y - 2;
		return ;
	}
	moves_u(map, 4);
	map->pos_y--;
}
