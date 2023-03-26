/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/24 20:59:39 by evallee-         ###   ########.fr       */
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
# define WIDTH 512
# define HEIGHT 512
# define TILE_SIZE 32

typedef struct
{
	uint32_t	num_coll;
	char		**data;
	uint32_t	dim_x;
	uint32_t	dim_y;
}	map_t;

typedef struct 
{
	ent_id_t	player;
	map_t		map;
}	gamestate_t;

typedef struct
{
	bool		has_exit;
	bool		has_start;
	uint32_t	collectibles;
	size_t		len;
}	t_linecheck;

typedef struct
{
	bool		has_exit;
	bool		has_start;
	uint32_t	collectibles;
	uint32_t	x;
	uint32_t	y;
}	t_mapcheck;

bool	map_load(map_t *map_data, const char *path);
void	sl_init(mlx_t *mlx);
void	sl_keys(mlx_key_data_t keydata, void *params);
void	sl_tick(void *params);
void	sl_draw(mlx_image_t *buffer, void *param);
void	sl_exit(void);

#endif