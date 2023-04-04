/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:20:54 by niceguy           #+#    #+#             */
/*   Updated: 2023/04/04 04:08:28 by niceguy          ###   ########.fr       */
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
	return (true);
}

void	sl_keys(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		sl_exit(param);
	sys_controls(keydata, param);
}

void	sl_tick(void *param)
{
	mlx_t		*mlx;
	double		dt;
	t_gamestate	game;

	game = game_get();
	mlx = param;
	dt = mlx->delta_time;
	if (dt > 0.03)
		dt = 0.016;
	ecs_iterate(&sys_controls_tick, dt);
	ecs_iterate(&sys_projectiles, dt);
	ecs_iterate(&sys_collectible, dt, game.player);
	ecs_iterate(&sys_ai, dt, game.player);
	ecs_iterate(&sys_gravity, dt);
	ecs_iterate(&sys_collision, dt, param);
	ecs_iterate(&sys_movement, dt);
	ecs_iterate(&sys_state);
	ecs_iterate(&sys_animation, dt);
	ecs_iterate(&sys_sprites, mlx);
	game_tick(param);
}

void	sl_exit(void *params)
{
	ecs_clear();
	map_clear();
	mlx_terminate(params);
	exit(EXIT_SUCCESS);
}
