/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:09 by hbutt             #+#    #+#             */
/*   Updated: 2024/07/05 15:43:14 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
#include "printf/ft_printf.h"
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
	void		*mlx;
	void		*window;
	char		*name;
	char		**full;
	int			lines;
	int			columns;
	int			nbr_collec;
	int			pos_x;
	int			pos_y;
	int			moves;
	int			win;
}				t_map;
// Définition de la structure des objets
typedef struct s_objects
{
	int			exit;
	int			collec;
}				t_objects;

typedef struct s_explore_data
{
	t_objects	*objects;
	t_map		*map_info;
}				t_explore_data;

/* Check args */
void			check_args(int ac, char **av);

/* Read map */
t_map			read_map(t_map map);

/* Init map */
void			info_map(t_map *map);
t_map			init_map(t_map map);
void			check_map(t_map map);

/* Finishable or not */
int				is_finishable(t_map *map);

/* Display */
void			display_map(t_map *map, void *mlx, void *window);
void			refresh_display(t_map *map, int i, int j);
void			refresh_movements(t_map *map);

/* Display tiles */
void			display_wall(void *mlx, void *window, int j, int i);
void			display_floor(void *mlx, void *window, int j, int i);
void			display_exit(void *mlx, void *window, int j, int i);
void			display_collec(void *mlx, void *window, int j, int i);
void			display_player(void *mlx, void *window, int j, int i);

/* Can or not */
int				can_up(t_map *map);
int				can_down(t_map *map);
int				can_right(t_map *map);
int				can_left(t_map *map);

/* Moves */
int				controls(int keycode, t_map *map);
void	moves_u(t_map *map, int direction);

/* Close */
void			close_window(t_map *map);

/* Utils */
void			ft_error(char *msg);
int				ft_strlen(const char *str);
void			ft_you_win(t_map *map);
char			*ft_strcpy(char *dest, char *src);