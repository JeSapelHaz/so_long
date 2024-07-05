/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:14:02 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/22 16:52:44 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(t_map map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map.name, O_RDONLY);
	map.full = malloc(sizeof(char *) * map.lines);
	line = get_next_line(fd);
	while (line)
	{
		map.full[i] = malloc(ft_strlen(line));
		map.full[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map.win = 0;
	free(line);
	return (map);
}

void	check_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.lines)
	{
		if (map.full[i][0] != '1' || map.full[i][map.columns - 1] != '1')
			ft_error("Tu veux me piéger chef ?");
		i++;
	}
	i = 0;
	while (i < map.columns)
	{
		if (map.full[0][i] != '1' || map.full[map.lines - 1][i] != '1')
			ft_error("Tu veux me piéger chef ?");
		i++;
	}
}

static void	check_info_map(int nbr_player, t_map *map)
{
	int	i;
	int	j;
	int	nbr_exit;

	i = -1;
	nbr_exit = 0;
	while (++i < map->lines)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->full[i][j] == 'E')
				nbr_exit++;
		}
	}
	if (map->nbr_collec < 1)
		ft_error("Pas de collectibles, tu veux gagner sans jouer ?");
	if (nbr_exit > 1)
		ft_error("Que tu veux sortir du jeu toi");
	if (nbr_player > 1)
		ft_error("Il y a pas encore le multi chef");
}

void	info_map(t_map *map)
{
	int	i;
	int	j;
	int	nbr_player;
	int	nbr_exit;

	i = -1;
	nbr_player = 0;
	nbr_exit = 0;
	while (++i < map->lines)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->full[i][j] == 'C')
				map->nbr_collec++;
			if (map->full[i][j] == 'P')
			{
				nbr_player++;
				map->pos_x = i;
				map->pos_y = j;
			}
		}
	}
	check_info_map(nbr_player, map);
}
