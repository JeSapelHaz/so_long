/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:14:02 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/20 15:32:02 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(t_map map)
{
	int i;
	int fd;
	char *line;

	i = 0;
	fd = open("generator/maps/map.ber", O_RDONLY);
	map.full = malloc(sizeof(char *) * map.lines);
	line = get_next_line(fd);
	while (line)
	{
		map.full[i] = malloc(ft_strlen(line) + 1);
		map.full[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (map);
}