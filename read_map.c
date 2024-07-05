/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:43:22 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/05 15:26:30 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	read_map(t_map map)
{
	int		fd;
	char	*line;

	fd = open(map.name, O_RDONLY);
	if (fd < 1)
		ft_error("Map invalide");
	line = get_next_line(fd);
	map.columns = ft_strlen(line);
	while (line)
	{
		if (map.columns != ft_strlen(line))
			ft_error("Error : Longueur des lignes ne sont pas les mêmes");
		map.lines++;
		line = get_next_line(fd);
	}
	map.columns--;
	if (map.lines < 5 || map.columns < 5)
		ft_error("La map est trop petite chef");
	free(line);
	return (map);
}
