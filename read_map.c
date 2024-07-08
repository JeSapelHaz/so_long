/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:43:22 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/08 16:17:46 by hbutt            ###   ########.fr       */
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
	map.columns = ft_strlen_2(line);
	while (line)
	{
		if (map.columns != ft_strlen_2(line))
			ft_error("Error : Longueur des lignes ne sont pas les mêmes");
		map.lines++;
		line = get_next_line(fd);
	}
	if (map.lines < 5 || map.columns < 5)
		ft_error("La map est trop petite chef");
	free(line);
	return (map);
}
