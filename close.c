/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:36:09 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/22 18:39:11 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void close_window(t_map *map)
{
	mlx_clear_window(map->mlx, map->window);
	mlx_destroy_window(map->mlx, map->window);
	exit(0);
}