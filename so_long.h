/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:09 by hbutt             #+#    #+#             */
/*   Updated: 2024/06/23 20:57:43 by hbutt            ###   ########.fr       */
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
	void	*mlx;
	void	*window;
	char	*name;
	char	**full;
	int		lines;
	int		columns;
	int		nbr_collec;
	int		pos_x;
	int		pos_y;
}			t_map;

/* Check args */
void		check_args(int ac, char **av);

/* Read map */
t_map		read_map(t_map map);

/* Init map */
void		info_map(t_map *map);
t_map		init_map(t_map map);

/* Display */
void		display_map(t_map *map, void *mlx, void *window);

/* Display tiles */
void		display_wall(void *mlx, void *window, int j, int i);
void		display_floor(void *mlx, void *window, int j, int i);
void		display_exit(void *mlx, void *window, int j, int i);
void		display_collec(void *mlx, void *window, int j, int i);
void		display_player(void *mlx, void *window, int j, int i);

/* Can or not */
int			can_up(t_map *map);
int			can_down(t_map *map);
int			can_right(t_map *map);
int			can_left(t_map *map);

/* Moves */
int			controls(int keycode, t_map *map);

/* Close */
void		close_window(t_map *map);

/* Utils */
void		ft_error(char *msg);
int			ft_strlen(const char *str);
void ft_you_win();