/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:39:38 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/08 15:31:02 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_close_window(int keycode, t_map *map)
{
	if (keycode == 53)
		close_window(map);
}

int	controls(int keycode, t_map *map)
{
	is_close_window(keycode, map);
	if (map->win == 0)
	{
		if (keycode == 45)
		{
			change_player(map);
		}
		if ((keycode == 13 || keycode == 126) && can_up(map))
			move_up(map);
		if ((keycode == 2 || keycode == 124) && can_right(map))
			move_right(map);
		if ((keycode == 1 || keycode == 125) && can_down(map))
			move_down(map);
		if ((keycode == 0 || keycode == 123) && can_left(map))
			move_left(map);
	}
	return (0);
}
