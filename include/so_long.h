/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/27 17:27:03 by evallee-         ###   ########.fr       */
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
	t_uvec	start;
	t_uvec	end;
}	t_map;

typedef struct s_gamestate
{
	uint32_t	player;
}	gamestate_t;

typedef struct s_linecheck
{
	bool		has_exit;
	bool		has_start;
	uint32_t	collectibles;
	size_t		len;
}	t_mapcheck;

typedef struct s_collparams
{
	t_dvec	pos;
	t_uvec	size;
	t_dvec	vel;
	t_dvec	tpos;
	t_uvec	t_size;
}	t_collparams;

typedef struct s_collinfos
{
	bool	found;
	
}	t_collinfos;

bool		box_check(t_dvec pos, t_uvec size, t_dvec tpos, t_uvec tsize);
t_uvec		pos_to_coords(double x, double y);
void		ent_coords(t_uvec *coords[2], t_c_pos pos, t_c_coll *coll, t_c_vel *vel);
t_list		*parse_file(char *path);
bool		map_load(char *path);
t_map		map_get();
void		sl_init(mlx_t *mlx, char *path);
void		sl_keys(mlx_key_data_t keydata, void *params);
void		sl_tick(void *params);
void		sl_draw(mlx_image_t *buffer, void *param);
void		sl_exit(void);

#endif