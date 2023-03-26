/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/26 06:12:06 by niceguy          ###   ########.fr       */
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

typedef struct s_coord
{
	uint32_t	x;
	uint32_t	y;
}	t_coord;

typedef struct s_map
{
	uint32_t	num_coll;
	char		**data;
	uint32_t	dim_x;
	uint32_t	dim_y;
	t_coord		start;
	t_coord		end;
}	t_map;

typedef struct s_gamestate
{
	ent_id_t	player;
}	gamestate_t;

typedef struct s_linecheck
{
	bool		has_exit;
	bool		has_start;
	uint32_t	collectibles;
	size_t		len;
}	t_mapcheck;

t_list  *parse_file(char *path);
bool	map_load(char *path);
t_map	map_get();
void	sl_init(mlx_t *mlx, char *path);
void	sl_keys(mlx_key_data_t keydata, void *params);
void	sl_tick(void *params);
void	sl_draw(mlx_image_t *buffer, void *param);
void	sl_exit(void);

#endif