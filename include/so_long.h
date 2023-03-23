/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:08:10 by niceguy           #+#    #+#             */
/*   Updated: 2023/03/23 02:41:38 by niceguy          ###   ########.fr       */
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
	unsigned int num_coll;
}	map_t;

typedef struct 
{
    ent_id_t	player;
	map_t		map;
}   gamestate_t;

void	sl_init(mlx_t *mlx);
void	sl_keys(mlx_key_data_t keydata, void *params);
void	sl_tick(void *params);
void	sl_draw(mlx_image_t *buffer, void *param);
void	sl_exit();

void	sys_controls(mlx_key_data_t keydata, void *params);
void	sys_movement(double dt);
void	sys_sprites(double dt);

#endif