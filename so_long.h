/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:09 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/21 16:47:31 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TILE_SIZE 64

typedef struct s_map
{
	char	**full;
	int		lines;
	int		columns;
	char	*name;

}			t_map;

/* Check args */
void		check_args(int ac, char **av);

/* Read map */
t_map		read_map(t_map map);

/* Init map */
t_map		init_map(t_map map);

/* Display */
void display_map(t_map map, void *mlx, void *window);

/* Utils */
void		ft_error(char *msg);
int			ft_strlen(const char *str);