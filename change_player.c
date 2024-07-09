/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:43:57 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/09 16:42:27 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player(t_map *map)
{
	int	img_height;

	img_height = TILE_SIZE;
	map->img_player = mlx_xpm_file_to_image(map->mlx, "images/ajitss.xpm",
			&img_height, &img_height);
	refresh_display(map, map->pos_x, map->pos_y);
}
