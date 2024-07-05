/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:03:13 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/04 15:58:15 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour libérer la mémoire allouée pour la copie de la carte
void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// Exemple de débogage avec printf
char	**copy_map(t_map *map)
{
	char	**map_copy;
	int		i;

	i = 0;
	while (map->full[i])
		i++;
	map_copy = (char **)malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	map_copy[i] = 0;
	i = 0;
	while (i < map->lines)
	{
		map_copy[i] = (char *)malloc(strlen(map->full[i]) + 1);
		if (!map_copy[i])
		{
			map_copy[i] = 0;
			free_map_copy(map_copy);
			return (NULL);
		}
		ft_strcpy(map_copy[i], map->full[i]);
		i++;
	}
	map_copy[i] = 0;
	return (map_copy);
}

void	explore_map(char **map, int row, int col, t_explore_data *data)
{
	if (row < 0 || row >= data->map_info->lines || col < 0
		|| col >= data->map_info->columns || map[row][col] == '1'
		|| map[row][col] == 'V')
		return ;
	if (map[row][col] == 'E')
		data->objects->exit = 1;
	if (map[row][col] == 'C')
		data->objects->collec++;
	map[row][col] = 'V';
	explore_map(map, row - 1, col, data);
	explore_map(map, row + 1, col, data);
	explore_map(map, row, col - 1, data);
	explore_map(map, row, col + 1, data);
}

int	is_finishable(t_map *map)
{
	t_objects		objects;
	char			**map_copy;
	t_explore_data	data;

	objects = (t_objects){0, 0};
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	data.objects = &objects;
	data.map_info = map;
	explore_map(map_copy, map->pos_x, map->pos_y, &data);
	free_map_copy(map_copy);
	return (objects.exit == 1 && objects.collec == map->nbr_collec);
}
