/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:43:22 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/20 15:32:21 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	read_map(t_map map)
{
	int fd;
	char *line;

	fd = open("generator/maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	map.columns = ft_strlen(line);
	while (line)
	{
		if (map.columns != ft_strlen(line))
			ft_error("Error : Longueur des lignes ne sont pas les mêmes");
		map.lines++;
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}