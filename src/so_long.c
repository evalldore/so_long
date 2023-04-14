/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/12 15:12:09 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	sl_init(void *params)
{
	t_map		map;
	mlx_t		*mlx;

	mlx = params;
	map = map_get();
	assets_init(mlx);
	entities_init();
	map_iter_tiles(map, &game_set_tile, mlx);
	game_add_player(map.start);
	moves_init(params);
	return (true);
}

void	sl_keys(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		sl_exit();
		exit(0);
	}
	sys_controls(keydata, param);
}

void	sl_tick(void *param)
{
	mlx_t		*mlx;

	mlx = param;
	if (mlx->delta_time > 0.03)
		mlx->delta_time = 0.016;
	ecs_iterate(&sys_controls_tick, mlx);
	ecs_iterate(&sys_projectiles, mlx);
	ecs_iterate(&sys_collectible, mlx);
	ecs_iterate(&sys_ai, mlx);
	ecs_iterate(&sys_gravity, mlx);
	ecs_iterate(&sys_collision, mlx);
	ecs_iterate(&sys_movement, mlx);
	ecs_iterate(&sys_state, mlx);
	ecs_iterate(&sys_animation, mlx);
	ecs_iterate(&sys_sprites, mlx);
	game_tick(mlx);
	moves_update(param);
}

void	sl_exit(void)
{
	ecs_clear();
	map_clear();
}
