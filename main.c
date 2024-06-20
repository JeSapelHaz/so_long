/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:11:43 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/20 15:59:24 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map map;
	
	check_args(ac, av);
	map.name = av[1];
	map = read_map(map);
	map = init_map(map);
	

	mlx_new_window();
	int i = 0;
	while(map.full[i])
	{
		printf("%s", map.full[i]);
		i++;
	}
}
