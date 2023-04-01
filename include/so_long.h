/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/01 03:57:42 by niceguy          ###   ########.fr       */
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
# include "coordinates.h"
# include "map.h"

# define WIDTH 512
# define HEIGHT 512

typedef struct s_gamestate
{
	uint32_t	player;
	uint32_t	collected;
	uint32_t	moves;
}	t_gamestate;

typedef struct s_sweep
{
	t_uvec	min;
	t_uvec	max;
	t_dvec	step;
	double	time;
	t_ivec	normal;
}	t_sweepinfos;

void		interact(uint32_t ent1, uint32_t ent2);
void		shoot(uint32_t	player);
bool		sl_init(mlx_t *mlx);
void		sl_keys(mlx_key_data_t keydata, void *params);
void		sl_tick(void *params);
void		sl_exit(void);

#endif