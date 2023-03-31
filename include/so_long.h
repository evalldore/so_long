/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/31 01:26:47 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <MLX42/MLX42.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <libft.h>
# include <stddef.h>
# include <ecs.h>
# include <math.h>
# include "vector.h"
# include "entities.h"
# define WIDTH 512
# define HEIGHT 512
# define TILE_SIZE 32

typedef struct s_map
{
	uint32_t	num_coll;
	char		**data;
	uint32_t	dim_x;
	uint32_t	dim_y;
	t_ivec		start;
	t_ivec		end;
}	t_map;

typedef struct s_gamestate
{
	uint32_t	player;
	uint32_t	collected;
}	t_gamestate;

typedef struct s_linecheck
{
	bool		has_exit;
	bool		has_start;
	uint32_t	collectibles;
	int32_t		len;
}	t_mapcheck;

typedef struct s_sweep
{
	t_uvec	min;
	t_uvec	max;
	t_dvec	step;
	double	time;
	t_ivec	normal;
}	t_sweepinfos;

t_uvec		pos_to_coords(double x, double y);
t_list		*parse_file(char *path);
void		interact(uint32_t ent1, uint32_t ent2);
bool		map_load(char *path);
t_map		map_get(void);
void		sl_init(mlx_t *mlx, char *path);
void		sl_keys(mlx_key_data_t keydata, void *params);
void		sl_tick(void *params);
void		sl_draw(mlx_image_t *buffer, void *param);
void		sl_exit(void);

#endif